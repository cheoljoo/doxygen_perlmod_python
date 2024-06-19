import xml.etree.ElementTree as ET
import os

from lxml import etree
import re
import argparse
import sys
# add template imformation
from pprint import pprint
import json
from collections import defaultdict

g_depth = 0
debug = 0
caseRe = re.compile('^(?P<cond>\S+\s*:)')
breakRe = re.compile('\s*__break_\s*')

def parse_doxygen_xml(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()

    sourceDict = {}
    # 모든 클래스 찾기
    for compound in root.findall(".//compound[@kind='class']"):
        class_file = compound.get('refid') + '.xml'
        print('-----class :',class_file)
        parse_class_file(class_file,sourceDict)
    for compound in root.findall(".//compound[@kind='file']"):
        class_file = compound.get('refid') + '.xml'
        print('-----file:',class_file)
        parse_class_file(class_file,sourceDict)
    for compound in root.findall(".//compound[@kind='namespace']"):
        class_file = compound.get('refid') + '.xml'
        print('-----namespae:',class_file)
        parse_class_file(class_file,sourceDict)
    do_process(sourceDict)

def parse_class_file(class_file,sourceDict):
    global g_depth
    tree = ET.parse(class_file)
    root = tree.getroot()

    class_name = root.find("compounddef/compoundname").text
    print(f"{class_file} Class: {class_name}")

    for member in root.findall(".//memberdef[@kind='function']"):
        function_name = member.find("name").text
        def_name = member.find("definition").text
        args = member.find("argsstring").text
        location = member.find("location")
        bodyfile = location.get('bodyfile')
        bodystart = location.get('bodystart')
        bodyend = location.get('bodyend')
        if bodyfile:
            bodyfile = bodyfile.split('/')[-1]
            print(f"  Function: {function_name} / {def_name} {args} / {bodyfile} {bodystart} ~ {bodyend}")
            bodyinfo = f"{bodyfile} {bodystart} ~ {bodyend}"
            func = def_name+args
            if bodyinfo not in sourceDict:
                sourceDict[bodyinfo] = {
                    'func':  func,
                    'bodyinfo':  bodyinfo,
                    'function_name':  function_name,
                    'def_name':  def_name,
                    'args':  args,
                    'bodyfile':  bodyfile,
                    'bodystart':  bodystart,
                    'bodyend':  bodyend,
                }

def do_process(sourceDict):
    global g_depth
    myd = {}
    msgs = []
    for k,v in sourceDict.items():
        bodyinfo = k
        func = v['func']
        function_name = v['function_name']
        def_name = v['def_name']
        args = v['args']
        bodyfile = v['bodyfile'].split('/')[-1]
        bodystart = v['bodystart']
        bodyend = v['bodyend']
        print(f"  Function: {function_name} / {func} / {def_name} {args} / {bodyfile} {bodystart} ~ {bodyend}")
        xmlfile = bodyfile.split('/')[-1].replace('_','__').replace('.','_8')

        stack = []
        keywordflow = ''
        g_depth = 0
        parser = etree.XMLParser(recover=True)
        tree = etree.parse(xmlfile+'.xml', parser)
        bodyroot = tree.getroot()

        if debug: print('open',xmlfile+'.xml')
        msgs += analyze(myd,bodyinfo,xmlfile,func,bodyroot,bodystart,bodyend,stack,keywordflow) 

    with open('../step1-myd.json',"w") as json_file:
        print('write: step1-myd.json', '<- myd : 1st stage')
        json.dump(myd,json_file,indent = 4)
    second_analysis(myd)
    with open('../step2-nextd.json',"w") as json_file:
        print('write: step2-nextd.json', '<- myd : 2nd stage')
        json.dump(myd,json_file,indent = 4)
    make_flowchart_plantuml(myd)
    with open('../step3-puml.json',"w") as json_file:
        print('write: step3-puml.json', '<- myd : 3rd stage')
        json.dump(myd,json_file,indent = 4)

    fcJson = {}
    for info,v in myd.items():
        func_no_space = v['func'].replace(' ','')
        if func_no_space not in fcJson:
            fcJson[func_no_space] = {}
        fcJson[func_no_space]['func'] = v['func']
        fcJson[func_no_space]['file'] = v['file']
        fcJson[func_no_space]['bodystart'] = v['bodystart']
        fcJson[func_no_space]['bodyend'] = v['bodyend']
        fcJson[func_no_space]['info'] = info
        fcJson[func_no_space]['plantumlfile'] = v['plantumlfile']
        fcJson[func_no_space]['puml'] = v['puml']

    with open('../fcJson.json',"w") as json_file:
        print('write: fcJson.json', '<- fcJson : plantuml info')
        json.dump(fcJson,json_file,indent = 4)

    with open('../msgs.json',"w") as json_file:
        print('write: msgs.json', '<- msgs : display messages')
        json.dump(msgs,json_file,indent = 4)

def get_text(v,size=20):
    txt = ''
    for s in v:
        s = s.replace('{','').replace('}','').replace(';','')
        if not s.strip():
            continue
        if txt:
            txt += ';'
        txt += s[:size]
    return txt

def make_flowchart_plantuml(myd):
    cnt = 0
    for k,v in myd.items():
        cnt += 1
        v['plantumlfile'] = f'fc-{cnt}.puml'
        v['puml'] = ''
        v['puml'] += '@startuml\n'
        v['puml'] += 'start\n'
        v['puml'] += '#palegreen:{k};\n'.format(k=k.replace('_8','.'))
        v['puml'] += '#gold:{k};\n'.format(k=v['func'])
        depth = 1
        if debug: print(v['file'],v['func'])
        for i2,v2 in enumerate(v['codeline']):
            if v2['class'] == 'delete':
                continue
            elif v2['class'] == 'something':
                txt = get_text(v2['follow'])
                if txt.strip(): v['puml'] += f':{txt};\n'
            elif v2['class'] == 'keywordflow':
                if v2['text'] == 'if':
                    if depth == 1: v['puml'] += '''partition if {\n'''
                    v['puml'] += '''if {v} then (yes)\n'''.format(v=v2['condition'])
                    txt = get_text(v2['follow'])
                    if txt.strip(): v['puml'] += f':{txt};\n'
                    if breakRe.search(txt):
                        v['puml'] += '''break\n'''
                    depth += 1
                elif v2['text'] == 'elseif':
                    v['puml'] += '''elseif {v} then (yes)\n'''.format(v=v2['condition'])
                    txt = get_text(v2['follow'])
                    if txt.strip(): v['puml'] += f':{txt};\n'
                    if breakRe.search(txt):
                        v['puml'] += '''break\n'''
                elif v2['text'] == 'else':
                    v['puml'] += '''else (no)\n'''
                    txt = get_text(v2['follow'])
                    if txt.strip(): v['puml'] += f':{txt};\n'
                    if breakRe.search(txt):
                        v['puml'] += '''break\n'''
                elif v2['text'] in ['for','while']:
                    if depth == 1: v['puml'] += '''partition {v} '''.format(v=v2['text']) + '{\n'
                    v['puml'] += '''while {v}\n'''.format(v=v2['condition'])
                    txt = get_text(v2['follow'])
                    if txt.strip(): v['puml'] += f':{txt};\n'
                    depth += 1
                elif v2['text'] == 'do':
                    if depth == 1: v['puml'] += '''partition do {\n'''
                    v['puml'] += '''repeat\n'''
                    txt = get_text(v2['follow'])
                    if txt.strip(): v['puml'] += f':{txt};\n'
                    depth += 1
                elif v2['text'] == 'switch':
                    if depth == 1: v['puml'] += '''partition switch {\n'''
                    v['puml'] += '''switch {v}\n'''.format(v=v2['condition'])
                    v['puml'] += '''case ()\n'''.format(v=v2['condition'])
                    depth += 1
                elif v2['text'] == 'case':
                    v['puml'] += '''case ({v})\n'''.format(v=v2['condition'])
                elif v2['text'] == 'default':
                    v['puml'] += '''case (default)\n'''.format(v=v2['condition'])
            elif v2['class'] == 'end':
                if v2['text'] in ['endif','endelse']:
                    depth -= 1
                    v['puml'] += f'endif\n'
                    if depth == 1: v['puml'] += '''}\n'''   # for partition
                elif v2['text'] in ['endfor','endwhile']:
                    depth -= 1
                    v['puml'] += f'endwhile\n'
                    if depth == 1: v['puml'] += '''}\n'''
                elif v2['text'] == 'endswitch':
                    depth -= 1
                    v['puml'] += f'endswitch\n'
                    if depth == 1: v['puml'] += '''}\n'''
            elif v2['class'] == 'enddowhile':  #  이것은 do { }while() 이 끝부분을 나타낸다.
                if v2['text'] == 'while':
                    depth -= 1
                    v['puml'] += '''repeat while {v} is (yes)\n'''.format(v=v2['condition'])
                    v['puml'] += f'->no;\n'
                    if depth == 1: v['puml'] += '''}\n'''
                

        v['puml'] += 'stop\n'
        v['puml'] += '@enduml\n'
        if args.createPlantumlFile:
            with open('../'+v['plantumlfile'],'w') as f:
                print('write:', '../'+v['plantumlfile'])
                f.write(v['puml'])

def second_analysis(myd):
    for k,v in myd.items():
        if debug: print(v['file'],v['func'])
        removedElseCount = defaultdict(int) # we need to delte endelse because of pair.
        for i2,v2 in enumerate(v['codeline']):
            prev = None
            prev2 = None
            if i2-2 >= 0:
                prev2 = v['codeline'][i2-2]
            if i2-1 >= 0:
                prev = v['codeline'][i2-1]
            if v2['class'] == 'something':
                if debug: print('follow:',v2['follow'])
                if prev and prev['class'] == 'something':
                    v2['follow'] = prev['follow'] + v2['follow']
                    prev['class'] = 'delete'
                    prev['debug'] += '''[something :: something]      '''
                elif not v2['follow']:
                    v2['class'] = 'delete'
                    v2['debug'] += '''[something does not have any follow]    '''
                elif len(v2['follow']) == 1 and v2['follow'][0].strip() == ';':
                    v2['class'] = 'delete'
                    v2['debug'] += '''[if len is 1, contents ;]    '''
            if v2['class'] == 'keywordflow':
                if v2['text'] == 'if':
                    if prev and prev['class'] == 'keywordflow' and prev['text'] == 'else' and not prev['follow']:
                        prev['class'] = 'delete'
                        v2['text'] = 'elseif'
                        removedElseCount[v2['depth']] += 1
                        prev['debug'] += '''[else :: if - follow is null and depth={depth} rc={rc}]      '''.format(depth=v2['depth'],rc=removedElseCount)
                if v2['text'] == 'else':
                    if prev and prev['class'] == 'end' and prev['text'] == 'endif':
                        prev['class'] = 'delete'
                        prev['debug'] += '''[end(endif) :: else]      '''
                    if prev and prev['text'] == 'endelse' and prev2 and prev2['text'] == 'endif':
                        prev['class'] = 'delete'
                        prev2['class'] = 'delete'
                        prev['debug'] += '''[endif :: endelse :: :: else]     '''
                        prev2['debug'] += '''[endif :: endelse :: :: else]     '''
                elif v2['text'] == 'while':
                    if prev and prev['class'] == 'end' and prev['text'] == 'enddo':
                        prev['class'] = 'delete'
                        prev['debug'] += '''[end(enddo) :: while]     '''
                        v2['class'] = 'enddowhile'
                        for i3 in range(i2+1,len(v['codeline'])):
                            nxt = v['codeline'][i3]
                            if nxt['class'] == 'end' and nxt['text'] == 'endwhile':
                                nxt['class'] = 'delete'
                                nxt['debug'] += '''[end(enddo) :: while :: end(endwhile)]     '''
                                break
                elif v2['text'] == 'case':
                    xx = ';'.join(v2['follow'])
                    xx = xx.strip()
                    grp = caseRe.search(xx)
                    if grp:
                        v2['condition'] = grp.group('cond')
            if v2['class'] == 'end':
                if v2['text'] == 'endelse':
                    if removedElseCount[v2['depth']] > 0:
                        removedElseCount[v2['depth']] -= 1
                        v2['class'] = 'delete'
                        v2['debug'] += '''[end(endelse) :: depth={depth} rc={rc}]      '''.format(depth=v2['depth'],rc=removedElseCount)
                elif v2['text'] == 'endcase':
                    v2['class'] = 'delete'
                    v2['debug'] += '''[endcase]      '''
                elif v2['text'] == 'enddefault':
                    v2['class'] = 'delete'
                    v2['debug'] += '''[enddefault]      '''
            
        

def analyze(myd,info,file,func,root,bodystart,bodyend,stack,keywordflow):
    global g_depth
    # Extracting codeline elements
    results = []
    txt = ''
    if not bodystart or not bodyend:
        return results
    sfunc = info
    if sfunc not in  myd:
        myd[sfunc] = {'func':func , 'file':file, 'bodystart':bodystart,'bodyend':bodyend , 'codeline':[] , 'stack':[] , 'lastflow':['']}
    cl = myd[sfunc]['codeline']
    st = myd[sfunc]['stack']
    lf = myd[sfunc]['lastflow']  # set when deleted
    sf = myd[sfunc]
    lastflow = sf['lastflow']
    inElseCount = 0
    for codeline in root.xpath(".//codeline"):
        lineno = codeline.get('lineno')
        highlights = []
        if not lineno or not bodystart or not bodyend:
            print(file,func,lineno,bodystart,bodyend)
            continue
        if int(lineno) < int(bodystart)  or int(bodyend) < int(lineno):
            continue
        codeline_text = ' '.join(codeline.itertext())
        results.append('''{f} {l} inElseCount({i}): {c}'''.format(f=file,l=lineno,i=inElseCount,c=codeline_text))
        if codeline_text.strip().startswith('# if'):
            continue
        if codeline_text.strip().startswith('# else'):
            inElseCount += 1
            continue
        if codeline_text.strip().startswith('#else'):
            inElseCount += 1
            continue
        if codeline_text.strip().startswith('# endif'):
            inElseCount -= 1
            continue
        if codeline_text.strip().startswith('#endif'):
            inElseCount -= 1
            continue
        if inElseCount > 0:
            continue

        for highlight in codeline.xpath(".//highlight"):
            highlight_class = highlight.get('class')
            highlight_text = ' '.join(highlight.itertext())
             #print('highlight_text:',highlight_text)
            if highlight_class == 'comment':
                continue
            if highlight_class == 'normal' and highlight_text == '':
                continue
            if highlight_class == 'stringliteral':
                txt += " " + highlight_text.replace('{','').replace('}','')
            if highlight_class == 'normal' or highlight_class == 'keywordtype':
                if highlight_text.strip().startswith('if '):
                    print('===> ',file,': if string start in closure:' , highlight_text)
                    add_results(sf,results,txt,int(lineno))
                    highlight_class = 'keywordflow'
                    highlight_text2 = 'if'
                    cl.append( {'lineno': int(lineno) , 'class':highlight_class,'depth':g_depth , 'text':highlight_text2 , 'condition':'' , 'follow':[] , 'debug':''} )
                    results.append(f"Depth {g_depth} - Codeline {lineno}: class={highlight_class}, text='{highlight_text2}'")
                    st.append( {'flow':'if' , 'depth':g_depth , 'lineno': int(lineno) , 'follow':cl[-1]['follow']} )
                    txt = highlight_text.strip().replace('if ','')
                    continue
                txt += " " + highlight_text
            elif highlight_class == 'keywordflow' and highlight_text == 'break':
                txt += " " + ' __break_ '
            elif highlight_class == 'keywordflow' and highlight_text == 'return':
                txt += " " + ' __return_ '
            elif highlight_class == 'keywordflow':
                 #results.append(f"txt={txt}")
                add_results(sf,results,txt,int(lineno))
                if debug: print('keywoardflow:','line:',lineno , 'class:',highlight_class , 'text:',highlight_text ,'depth:',g_depth)
                cl.append( {'lineno': int(lineno) , 'class':highlight_class,'depth':g_depth , 'text':highlight_text , 'condition':'' , 'follow':[] , 'debug':''} )
                results.append(f"Depth {g_depth} - Codeline {lineno}: class={highlight_class}, text='{highlight_text}'")
                st.append( {'flow':highlight_text , 'depth':g_depth , 'lineno': int(lineno) , 'follow':cl[-1]['follow']} )
                txt = ''
                
    if txt:
         #results.append(f"txt={txt}")
        add_results(sf,results,txt,-1)
        if debug: print('last sentense',txt)

    return results

def add_results(sf,results,txt,lineno):
    cl = sf['codeline']
    st = sf['stack']
    lf = sf['lastflow']
    global g_depth
    cond = ''
    if cl and txt.strip().startswith('('):
        braceCount = 1
        cond = '('
        for t in txt.strip()[1:]:
            if t == '(':
                braceCount += 1
            elif t == ')':
                braceCount -= 1
            cond += t
            if braceCount == 0:
                cl[-1]['condition'] = cond
                cl[-1]['debug'] = txt
                txt = txt.strip().replace(cond,'',1)
                break

                         
        
    txtList = [txt]
    r = []
    sep = ['{','}']
    for s in sep:
        if debug: print(s,'len',len(txtList),txtList)
        for t in txtList:
            aa = t.split(s)
            if debug: print('aa:',aa)
            for i,a in enumerate(aa):
                if i == 0:
                    r.append(a)
                else:
                    r.append(s)
                    r.append(a)
        txtList = r
        r = []
    txt = ' '.join(txtList)
    print('txt3:',txt , '////', txtList)
    print('stack:')
    for i,s in enumerate(st):
        print('  ',i,s['flow'],s['depth'],s['lineno'],' '.join(s['follow']))
    endFlag = False
    if txt.strip().startswith('{'):
        print('txt4:',txt ,'////',  txtList)
        for i,t in enumerate(txtList):
            if not t.strip():
                continue
            if t == '{':
                g_depth += 1
                st.append( {'flow':t , 'depth':g_depth , 'lineno': '..'+str(lineno) , 'follow':cl[-1]['follow']} )
            txtList[i] = f'depth {g_depth} : {t}'
            if cl :
                cl[-1]['follow'].append( t )
            if t == '}':
                g_depth -= 1
                st.pop()
                stack_rearrange(st,cl)
         #pprint( {'stack-1':st})
         #pprint( {'codeline-1':cl})
        # 여기서는 { 만 여러개 있고 , 빠져나간다. 다음은 stack-2
    else:
        print('txt5:',txt ,'////',  txtList)
        for i,t in enumerate(txtList):
            if not t.strip():
                continue
            if debug: print('t-2:',t)
            if t == '{':
                g_depth += 1
                st.append( {'flow':t , 'depth':g_depth , 'lineno':'..'+str(lineno) , 'follow':cl[-1]['follow']} )
            txtList[i] = f'depth {g_depth} : {t}'
            '''
            if cl :
                cl[-1]['follow'].append( {'depth':g_depth , 'text':t} )
            '''
            # }으로 끝나거나 , 한줄로 끝나는 것은 뒤에 { 에 도달할때까지 stack pop을 해야 한다. 
            if t == '}':
                if cl :
                    cl[-1]['follow'].append( t )
                g_depth -= 1
                st.pop()
                stack_rearrange(st,cl)
            if t != '{' and t != '}':
                aa = t.split(';')
                na = []
                for a in aa:
                    if not a.strip():
                        continue
                    na.append(a)
                if t.find(';') >= 0 and not na:
                    na = [';']
                if len(na) > 0:
                    endFlag = True
                    first = na[0]
                    remainList = na[1:]
                    if debug: print('na:',na)
                    if debug: print('first:',first)
                    if len(st) >= 1:
                        if debug: print('st -1 flow:',st[-1]['flow'])
                        if debug: print('cl -1 text:',cl[-1]['text'])
                    if len(st) >= 1 and ( cl[-1]['text'] == 'default' or cl[-1]['text'] == 'case'):    #True:  #len(st) <= 1:
                        st[-1]['follow'].append( first )
                    else:
                        cl.append( {'lineno': '-7' , 'class':'something','depth':g_depth , 'text':first, 'condition':'' , 'follow':[first] , 'debug':'','type':'first'} )
                    stack_rearrange(st,cl)
                    if debug: print('remainList:',remainList)
                    if len(st) >= 1:
                        if debug: print('st -1 flow:',st[-1]['flow'])
                        if debug: print('cl -1 text:',cl[-1]['text'])
                    if len(st) >= 1 and ( cl[-1]['text'] == 'enddefault' or cl[-1]['text'] == 'endcase'):    #True:  #len(st) <= 1:
                        st[-1]['follow'].append( ';'.join(remainList) )
                    else:
                        if remainList:
                            cl.append( {'lineno': '-2' , 'class':'something','depth':g_depth , 'text':','.join(remainList), 'condition':'' , 'follow':remainList , 'debug':'','type':'remain'} )
                     #pprint( {'stack-2':st})
                     #pprint( {'codeline-2':cl})

    results += txtList


def stack_rearrange(st,cl):
    while st:
        item = st[-1]
        if item['flow'] != '{':
            st.pop()
            cl.append( {'lineno': '-3' , 'class':'end','depth':g_depth , 'text':'end'+item['flow'], 'condition':'' , 'follow':[] , 'debug':''} )
        else:
            break
    print('stack_rearragne')
    for i,s in enumerate(st):
        print('  ',i,s['flow'],s['depth'],s['lineno'],' '.join(s['follow']))
            
if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog=sys.argv[0],
        description=
        'make flow chart plantuml : basic input is xml/index.xml')
    parser.add_argument( '--createPlantumlFile', default=False , action="store_true" , help="if set, create fc-?.puml files")
    args = parser.parse_args()
    if not os.path.exists('xml/index.xml'):
        print('error: you need the xml files in xml directory : check xml/index.xml')
        quit(4)
    os.chdir('xml')
    index_file_path = "index.xml"
    parse_doxygen_xml(index_file_path)

