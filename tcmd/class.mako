<%!
import os
import json
ret = '<br>'

def getProxyPlantuml(pfile,D):
    html = ''
    if os.path.exists(pfile):
        proxylink = '{proxy}&src={phttp}/{file}'.format(proxy=D['_template__']['myPlantumlServerProxy'] , phttp=D['_template__']['mySrcDirHttp']+'/'+D['_template__']['tcmdoutdir'] if D['_template__']['tcmdoutdir'] else D['_template__']['mySrcDirHttp'], file=pfile.split('/')[-1])
        html += '''<img src="{proxylink}" alt="{pfile}")><br>'''.format(proxylink=proxylink,pfile=pfile)
        D['_template__']['files'].append(pfile)
         #print('html',html, 'pfile',pfile)
    return html

def getParameters(parameters,detailed_doc):
    """ parameters
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['parameters']={}
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['parameters'] ['1']={}
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['parameters'] ['1'] ['declaration_name'] =  '''a'''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['parameters'] ['1'] ['type'] =  '''int &'''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['parameters'] ['2']={}
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['parameters'] ['2'] ['type'] =  '''int &'''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['parameters'] ['2'] ['declaration_name'] =  '''b'''
    # when it declare without name (for example, (const QCString &) ) , it does not have 'declaration_name' value
    D ['classes'] ['4'] ['private_methods'] ['members'] ['5'] ['parameters'] ['1'] ['type'] =  '''const QCString &'''
    D ['classes'] ['4'] ['private_methods'] ['members'] ['5'] ['parameters'] ['1'] ['definition_name'] =  '''name'''
    """
    retParameters = []
    for k,v in parameters.items():
        if v.get('declaration_name',''):
            retParameters.append('{t} {d}'.format(t=v.get('type',''),d=v.get('declaration_name','')))
        else:
            retParameters.append('{t} {d}'.format(t=v.get('type',''),d=v.get('definition_name','')))

    """ detailed_doc
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['doc'] ['1']={}
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['doc'] ['1'] ['type'] =  '''text'''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['doc'] ['1'] ['content'] =  '''example of out '''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['parameters']={}
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['parameters'] ['1']={}
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['parameters'] ['1'] ['name'] =  '''b'''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['4'] ['params'] ['1'] ['parameters'] ['1'] ['dir'] =  '''out'''
    """
    retIn = []
    retOut = []
    for k,v in detailed_doc.items():        # k = '4'
        for k2,v2 in v.items():             # k2 = 'params'
            if k2 == 'params':
                for k3,v3 in v2.items():    # k3 = '1'
                    ldesc = getDescription(doc=v3.get('doc'))
                    ldir = v3.get('parameters',{}).get('1',{}).get('dir','')
                    lname = v3.get('parameters',{}).get('1',{}).get('name','')
                    # lname is connected to 'declaration_name' of 'parameters' when it has no warning.
                    if ldir.find('in') >= 0:
                        retIn.append([lname,ldesc])
                    if ldir.find('out') >= 0:
                        retOut.append([lname,ldesc])



    # params = { 'parameters': [] , 'in':[] , 'out':[] }
    return { 'parameters': retParameters , 'in':retIn , 'out':retOut }

def getReturnDescription(doc):
    """
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['1']={}
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['1'] ['type'] =  '''text'''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['1'] ['content'] =  '''The area of the '''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['2']={}
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['2'] ['content'] =  '''Triangle'''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['2'] ['link'] =  '''classTriangle'''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['2'] ['type'] =  '''url'''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['3']={}
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['3'] ['content'] =  ''' object. '''
    D ['classes'] ['9'] ['public_methods'] ['members'] ['16'] ['detailed'] ['doc'] ['3'] ['return'] ['3'] ['type'] =  '''text'''
    """
    ret = []
    for k,v in doc.items():  # k : '3' , v [return]...
        s = ''
        for k2,v2 in v.items():
            if k2 == 'return':
                ret.append(getDescription(doc=doc[k][k2]))
    return ret

def getDetails(doc):
    l = []
    s = ''
    for k,v in doc.items():     # k = '3'
        type = v.get('type','')
        if type == 'plantuml':
            if s.strip():
                l.append(['text',s])
            s = ''
            l.append(['plantuml',v['content']])
        elif type in ['url','text']:
            s += v.get('content','')
        elif type in ['linebreak']:  # 'parbreak'
            if s.strip():
                l.append(['text',s])
            s = ''
    if s.strip():
        l.append(['text',s])
    return l

def getPlantuml(doc):
    """
    D ['classes'] ['2'] ['detailed'] ['doc'] ['3'] ['type'] =  '''plantuml'''
    D ['classes'] ['2'] ['detailed'] ['doc'] ['3'] ['content'] =  '''package "customer domain" #DDDDDD { ... '''
    """
    l = []
    for k,v in doc.items():     # k = '3'
        type = v.get('type','')
        if type == 'plantuml':
            l.append(v['content'])
    return l

def getDescription(doc):
    '''
    link =  D ['classes'] ['2'] ['public_methods'] ['members'] ['1'] ['brief'] ['doc']
    link =  D ['classes'] ['2'] ['public_methods'] ['members'] ['2'] ['detailed'] ['doc']
    '''
    s = ''
    for k,v in doc.items():
        type = v.get('type','')
        if type in ['url','text']:
            s += v.get('content','')
        elif type in ['linebreak']:  # 'parbreak'
            s += ret
    return s
%>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>DoxyDocs</title>
    <style>
        body {
            font-family: "Segoe UI", -apple-system, BlinkMacSystemFont, Roboto,
              Oxygen-Sans, Ubuntu, Cantarell, "Helvetica Neue", sans-serif;
            line-height: 1.4;
            color: #333;
            background-color: #fff;
            padding: 0 5vw;
          }
          
          /* Standard Tables */
          
          table {
            margin: 1em 0;
            border-collapse: collapse;
            border: 0.1em solid #d6d6d6;
          }
          
          caption {
            text-align: left;
            font-style: italic;
            padding: 0.25em 0.5em 0.5em 0.5em;
          }
          
          th,
          td {
            padding: 0.25em 0.5em 0.25em 1em;
            vertical-align: text-top;
            /* text-align: left; */
            text-indent: -0.5em;
          }
          
          th {
            vertical-align: top;
            /* background-color: #666;
            color: #fff; */
          }
          
          tr:nth-child(even) th[scope=row] {
            background-color: #f2f2f2;
          }
          
          tr:nth-child(odd) th[scope=row] {
            background-color: #fff;
          }
          
          tr:nth-child(even) {
            background-color: rgba(0, 0, 0, 0.05);
          }
          
          tr:nth-child(odd) {
            background-color: rgba(255, 255, 255, 0.05);
          }
          
          td:nth-of-type(2) {
            font-style: italic;
          }
          
          th:nth-of-type(1) {
            text-align: left;
            vertical-align: top;
            background-color: #666;
            color: #fff;
          }
          /*
          th:nth-of-type(3),
          td:nth-of-type(3) {
            text-align: right;
          }
          */
          
          /* Fixed Headers */
          
          th {
            position: -webkit-sticky;
            position: sticky;
            top: 0;
            z-index: 2;
          }
          
          th[scope=row] {
            position: -webkit-sticky;
            position: sticky;
            left: 0;
            z-index: 1;
          }
          
          th[scope=row] {
            vertical-align: top;
            color: inherit;
            background-color: inherit;
            background: linear-gradient(90deg, transparent 0%, transparent calc(100% - .05em), #d6d6d6 calc(100% - .05em), #d6d6d6 100%);
          }
          
          table:nth-of-type(2) th:not([scope=row]):first-child {
            left: 0;
            z-index: 3;
            background: linear-gradient(90deg, #666 0%, #666 calc(100% - .05em), #ccc calc(100% - .05em), #ccc 100%);
          }
          
          /* Strictly for making the scrolling happen. */
          
          /*
          th[scope=row] + td {
            min-width: 24em;
          }
          
          th[scope=row] {
            min-width: 20em;
          }
          */
          
          body {
            padding-bottom: 90vh;
          }
    </style>
<style>
* {
  box-sizing: border-box;
}

#myTableInput {
  /* background-image: url('/css/searchicon.png'); */
  background-position: 10px 10px;
  background-repeat: no-repeat;
  width: 100%;
  font-size: 16px;
  padding: 12px 20px 12px 40px;
  border: 1px solid #ddd;
  margin-bottom: 12px;
}

#myCbInput {
  /* background-image: url('/css/searchicon.png'); */
  background-position: 10px 10px;
  background-repeat: no-repeat;
  width: 100%;
  font-size: 16px;
  padding: 12px 20px 12px 40px;
  border: 1px solid #ddd;
  margin-bottom: 12px;
}
</style>
</head>

<body>
<h1>${ D['_template__']['service'] }</h1>
<h2>- class diagram (brief)</h2>
<% html = getProxyPlantuml('_plantuml/_all_puml_nomember_exception_inherit_unknown.puml',D) %>
${ html }
<h2>- class diagram (full)</h2>
${ getProxyPlantuml('_plantuml/_all_puml.puml',D) }
<h2>- class list</h2>
<table>
    <tr><th>Class</th><th>inherit</th><th>Includes</th><th>Brief</th><th>Detailed Description</th></tr>
% for k,v in D['classes'].items():
    % if len( [ accessibility for accessibility,v2 in v.items() if accessibility == 'public_methods'] ):
    <% base=[] %>\
    % for k1,v2 in v.get('base',{}).items():
        <% base.append(v2.get('name','')) %>\
    % endfor
    <% brief = getDescription(doc=v.get('brief',{}).get('doc',{})) %>\
    <% detail = getDescription(doc=v.get('detailed',{}).get('doc',{})) %>\
    <tr><td>${v['name']}</td><td>${' '.join(base)}</td><td>${v.get('includes',{}).get('name','')}</td><td>${brief}</td><td>${detail}</td></tr>
    % endif
% endfor
</table>

<% plantumlCnt = 0 %>\
<% classCnt = 0 %>\
% for k,v in D['classes'].items():
    ##<h2> classes key </h2>
    <% classSubCntL2 = 0 %>\
    % if len( [ accessibility for accessibility,v2 in v.items() if accessibility == 'public_methods'] ):
        <% classCnt += 1 %>\
        <h1>${classCnt}. ${v['name']} class</h1>
        % if os.path.exists('_plantuml/{c}_puml.puml'.format(c=v['name'])):
            <% classSubCntL2 += 1 %>
            <h2>${classCnt}.${classSubCntL2}. class diagram</h2>    
            ${ getProxyPlantuml('_plantuml/{c}_puml.puml'.format(c=v['name']),D) }
        % endif

        <% classSubCntL2 += 1 %>
        <h2>${classCnt}.${classSubCntL2}.class public API</h2>   
        <table>
        <tr><th>Accessibility</th><th>Function</th><th>Description</th><th>Parameters</th><th>param input</th><th>param output</th><th>Returns</th><th>return Description</th></tr>
        % for accessibility,v2 in v.items():
            % if accessibility == 'public_methods':
                % for k3,v3 in v2.get('members',{}).items():
                    <%
                        t = v2['members'][k3]
                        func = t['name']
                        brief = getDescription(doc=t.get('brief',{}).get('doc',{}))
                        detailed = getDescription(doc=t.get('detailed',{}).get('doc',{}))
                        returnType = t.get('type','')
                        # returnDoc = []
                        returnDoc = ret.join(getReturnDescription(doc=t.get('detailed',{}).get('doc',{})))
                        # params = { 'parameters': [] , 'in':[] , 'out':[] }
                        params = getParameters(parameters=t.get('parameters',{}),detailed_doc=t.get('detailed',{}).get('doc',{}))
                    %>
                    <tr><td>${accessibility}</td><td>${func}</td><td>${brief}</td><td>${ret.join(params['parameters'])}</td><td>${ret.join([ x for x,y in params['in']])}</td><td>${ret.join([x for x,y in params['out']])}</td><td>${returnType}</td><td>${returnDoc}</td></tr>
                % endfor
            % endif
        % endfor
        </table>
        <br>
    % endif

    ##<h2>start</h2>
    ##${ v }
    ##<p>
    ##${ v.get('detailed',{}).get('doc',{}) }
    ##<h2>end</h2>

    <% details = getDetails(doc=v.get('detailed',{}).get('doc',{})) %>\
    ##AA ${ details }
    % if len(details):
        <% classSubCntL2 += 1 %>
        <h2>${classCnt}.${classSubCntL2}. class details</h2>    
        % for detailsType , detailsContent in details:
            % if detailsType == 'plantuml':
                <%
                plantumlCnt += 1
                with open('_test-{c}.puml'.format(c=plantumlCnt),'w') as f:
                    f.write('@startuml _test-{c}.png\n'.format(c=plantumlCnt))
                    f.write(detailsContent)
                    f.write('\n@enduml\n')
                %>
                ${ getProxyPlantuml("_test-{c}.puml".format(c=plantumlCnt),D) }
            % else:
                ${ detailsContent } <br>
            % endif
        % endfor
        <br>
    % endif

    % if len( [ accessibility for accessibility,v2 in v.items() if accessibility == 'public_methods'] ):
        <% classSubCntL2 += 1 %>
        <h2>${classCnt}.${classSubCntL2}. member details</h2>    
        <% classMemCntL3 = 0 %>\
        % for accessibility,v2 in v.items():
            % if accessibility == 'public_methods':
                % for k3,v3 in v2.get('members',{}).items():
                    <%
                        t = v2['members'][k3]
                        func = t['name']
                        details = getDetails(doc=t.get('detailed',{}).get('doc',{}))
                        returnType = t.get('type','')
                        # returnDoc = []
                        returnDoc = ret.join(getReturnDescription(doc=t.get('detailed',{}).get('doc',{})))
                        # params = { 'parameters': [] , 'in':[] , 'out':[] }
                        params = getParameters(parameters=t.get('parameters',{}),detailed_doc=t.get('detailed',{}).get('doc',{}))
                    %>
                    <% classMemCntL3 += 1 %>
                    <h3>${classCnt}.${classSubCntL2}.${classMemCntL3}. ${returnType} ${ func }( ${ ' , '.join(params['parameters']) })</h3>      
                    ##${ params } <br>
                    % if params['in']:
                    <h4>parameters [in]</h4>
                        % for paramsName,paramsDesc in params['in']:
                            - ${paramsName} ${': ' + paramsDesc if pramsDesc else ''} <br>
                        % endfor
                    % endif
                    % if params['out']:
                    <h4>parameters [out]</h4>
                        % for paramsName,paramsDesc in params['out']:
                            - ${paramsName} ${': ' + paramsDesc if pramsDesc else ''} <br>
                        % endfor
                    % endif
                    % if returnType:
                    <h4>return type</h4>
                    - ${returnType} ${': ' + returnDoc if returnDoc else ''} <br>
                    % endif
                    % if len(details):
                        <h4>member detailed description</h4>
                        % for detailsType , detailsContent in details:
                            % if detailsType == 'plantuml':
                                <%
                                plantumlCnt += 1
                                with open('_test-{c}.puml'.format(c=plantumlCnt),'w') as f:
                                    f.write('@startuml _test-{c}.png\n'.format(c=plantumlCnt))
                                    f.write(detailsContent)
                                    f.write('\n@enduml\n')
                                %>
                                ${ getProxyPlantuml("_test-{c}.puml".format(c=plantumlCnt),D) }
                            % else:
                                ${ detailsContent } <br>
                            % endif
                        % endfor
                    % endif
                % endfor
            % endif
        % endfor
    % endif

% endfor

</body>
</html>

