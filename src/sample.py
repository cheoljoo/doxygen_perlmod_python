import sys,os
sys.path.append(os.getcwd())
import DoxyDocs
import argparse
import mysetting

class DoxyDocsClass :
    '''
    analyze classes as example. it will print table for class with markdown format
    '''
    def __init__(self,doxydocs={},outfile='',debug=False):
        self.plantumlCnt = 0
        self.ret = '<br>'   # or  '\\n'

        self.D = doxydocs
        self.outfile = outfile
        self.debug = debug
        self.of = None
        self.html = False
        if self.outfile.strip():
            print('write:',self.outfile)
            self.of = open(self.outfile.strip(),'w')
            if self.outfile.strip().endswith('.html'):
                self.html = True

    def __fini__(self):
        if self.outfile.strip():
            close(self.of)

    def run(self):
        if self.html:
            self.runHtml()
            print('! output (html) is {f}'.format(f=os.getcwd()+'/'+self.outfile),file=sys.stderr)
        else:
            self.runMarkdown()
            print('! output (markdown) is {f}'.format(f=os.getcwd()+'/'+self.outfile),file=sys.stderr)

    def runHtml(self):
        self.print(0,'<!DOCTYPE html>\n<html>')
        self.print(0,"""

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
                """)
        self.print(0,'<body>')
        self.print(0,'<h1>classes</h1>')
        self.print(0,'<table>')
        self.print(1,'<tr><th>Class</th><th>Derived</th><th>Includes</th><th>Brief</th><th>Detailed Description</th></tr>')
        self.cls = {}
        for k,v in self.D['classes'].items():
            self.cls[k] = {}
            name = v['name']
            includes = v.get('includes',{}).get('name','')
            self.cls[k]['name'] = name
            self.cls[k]['brief'] = self.getDescription(doc=v.get('brief',{}).get('doc',{}))
            self.cls[k]['detailed'] = self.getDescription(doc=v.get('detailed',{}).get('doc',{}))
            self.cls[k]['derived'] = []
            for k1,v2 in v.get('derived',{}).items():
                self.cls[k]['derived'].append(v2.get('name',''))
            self.cls[k]['includes'] = includes
            t = self.cls[k]
            self.print(1,'''<tr><td>{name}</td><td>{drived}</td><td>{includes}</td><td>{brief}</td><td>{detail}</td></tr>'''.format(name=t['name'],brief=t['brief'],drived=' '.join(t['derived']),includes=t['includes'],detail=t['detailed']))
        self.print(0,'</table>')
        self.print(0,'')

        for k,v in self.D['classes'].items():
            self.print(0,'<h2>Function Lists of {c} class</h2>'.format(c=v['name']))
            # plantuml
            plantuml = self.getPlantuml(doc=v.get('detailed',{}).get('doc',{}))
            for p in plantuml:
                self.plantumlCnt += 1
                with open('test-{c}.puml'.format(c=self.plantumlCnt),'w') as f:
                    f.write('@startuml test-{c}.png\n'.format(c=self.plantumlCnt))
                    f.write(p)
                    f.write('\n@enduml\n')
                proxylink = '{proxy}&src={puml}/{file}'.format(proxy=mysetting.myPlantumlServerProxy , puml=mysetting.mySrcDirHttp , file='test-{c}.puml'.format(c=self.plantumlCnt))
                pnglink = '../../../img/{file}'.format(proxy=mysetting.myPlantumlServerProxy , puml=mysetting.mySrcDirHttp , file='test-{c}.png'.format(c=self.plantumlCnt))
                self.print(2,'''<img src="{src}" onerror="this.onerror=null;this.src='{png}';" alt="test-{c}.puml">'''.format(src=proxylink,png=pnglink,c=self.plantumlCnt))

            # Table
            self.print(2,'<table>')
            self.print(2,'<tr><th>Accessibility</th><th>Function</th><th>Description</th><th>Parameters</th><th>param input</th><th>param output</th><th>Returns</th><th>return Description</th></tr>')
            for accessibility,v2 in v.items():
                if accessibility == 'public_methods':
                    for k3,v3 in v2.get('members',{}).items():
                        t = v2['members'][k3]
                        func = t['name']
                        brief = self.getDescription(doc=t.get('brief',{}).get('doc',{}))
                        detailed = self.getDescription(doc=t.get('detailed',{}).get('doc',{}))
                        returnType = t.get('type','')
                        # returnDoc = []
                        returnDoc = self.ret.join(self.getReturnDescription(doc=t.get('detailed',{}).get('doc',{})))
                        # params = { 'parameters': [] , 'in':[] , 'out':[] }
                        params = self.getParameters(parameters=t.get('parameters',{}),detailed_doc=t.get('detailed',{}).get('doc',{}))
                         #print('a',accessibility,func,detailed)
                         #print('r',returnType,returnDoc)
                         #print((self.ret).join(params['parameters']))
                         #print((self.ret).join([x for x,y in params['in']]))
                        self.print(2,'''<tr><td>{acc}</td><td>{func}</td><td>{desc}</td><td>{param}</td><td>{i}</td><td>{o}</td><td>{r}</td><td>{rdesc}</td></tr>'''.format(acc=accessibility,func=func,desc=detailed,param=self.ret.join(params['parameters']),i=self.ret.join([ x for x,y in params['in']]),o=self.ret.join([x for x,y in params['out']]),r=returnType,rdesc=returnDoc))
            self.print(2,'</table>')
            self.print(2,'')
        self.print(0,'</body>\n</html>')

        return

    def runMarkdown(self):
        self.print(0,'# classes')
        self.print(0,'| Class | Derived | Includes | Brief | Detailed Description|')
        self.print(0,'|-------|-------------|---------|---------|----|')

        self.cls = {}
        for k,v in self.D['classes'].items():
            self.cls[k] = {}
            name = v['name']
            includes = v.get('includes',{}).get('name','')
            self.cls[k]['name'] = name
            self.cls[k]['brief'] = self.getDescription(doc=v.get('brief',{}).get('doc',{}))
            self.cls[k]['detailed'] = self.getDescription(doc=v.get('detailed',{}).get('doc',{}))
            self.cls[k]['derived'] = []
            for k1,v2 in v.get('derived',{}).items():
                self.cls[k]['derived'].append(v2.get('name',''))
            self.cls[k]['includes'] = includes
            t = self.cls[k]
            self.print(0,'''|{name}|{drived}|{includes}|{brief}|{detail}|'''.format(name=t['name'],brief=t['brief'],drived=' '.join(t['derived']),includes=t['includes'],detail=t['detailed']))
        self.print(0,'')

        for k,v in self.D['classes'].items():
            self.print(0,'## Function Lists of {c} class'.format(c=v['name']))
            # plantuml
            plantuml = self.getPlantuml(doc=v.get('detailed',{}).get('doc',{}))
            for p in plantuml:
                self.plantumlCnt += 1
                self.print(0,"""- ```puml plantmul-{c}.png""".format(c=self.plantumlCnt))
                self.print(2,'@startuml')
                self.print(2,p)
                self.print(2,'@enduml')
                self.print(2,'```')
                self.print(0,'')
            # Table
            self.print(2,'| Accessibility | Function | Description | Parameters | param input | param output | Returns | return Description |')
            self.print(2,'|-------|-------|----------|-------------|-------|-----|----|-------|')
            for accessibility,v2 in v.items():
                if accessibility == 'public_methods':
                    for k3,v3 in v2.get('members',{}).items():
                        t = v2['members'][k3]
                        func = t['name']
                        brief = self.getDescription(doc=t.get('brief',{}).get('doc',{}))
                        detailed = self.getDescription(doc=t.get('detailed',{}).get('doc',{}))
                        returnType = t.get('type','')
                        # returnDoc = []
                        returnDoc = self.ret.join(self.getReturnDescription(doc=t.get('detailed',{}).get('doc',{})))
                        # params = { 'parameters': [] , 'in':[] , 'out':[] }
                        params = self.getParameters(parameters=t.get('parameters',{}),detailed_doc=t.get('detailed',{}).get('doc',{}))
                         #print('a',accessibility,func,detailed)
                         #print('r',returnType,returnDoc)
                         #print((self.ret).join(params['parameters']))
                         #print((self.ret).join([x for x,y in params['in']]))
                        self.print(2,'''|{acc}|{func}|{desc}|{param}|{i}|{o}|{r}|{rdesc}|'''.format(acc=accessibility,func=func,desc=detailed,param=self.ret.join(params['parameters']),i=self.ret.join([ x for x,y in params['in']]),o=self.ret.join([x for x,y in params['out']]),r=returnType,rdesc=returnDoc))
            self.print(0,'')


    def print(self,spaceCnt=0,text=''):
        spaces = ' '* (spaceCnt)
        for txt in text.split('\n'):
            if self.of:
                print(spaces,txt,sep='',file=self.of)
            else:
                print(spaces,txt,sep='')

    def getParameters(self,parameters,detailed_doc):
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
                        ldesc = self.getDescription(doc=v3.get('doc'))
                        ldir = v3.get('parameters',{}).get('1',{}).get('dir','')
                        lname = v3.get('parameters',{}).get('1',{}).get('name','')
                        # lname is connected to 'declaration_name' of 'parameters' when it has no warning.
                        if ldir.find('in') >= 0:
                            retIn.append([lname,ldesc])
                        if ldir.find('out') >= 0:
                            retOut.append([lname,ldesc])



        # params = { 'parameters': [] , 'in':[] , 'out':[] }
        return { 'parameters': retParameters , 'in':retIn , 'out':retOut }

    def getReturnDescription(self,doc):
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
                    ret.append(self.getDescription(doc=doc[k][k2]))
        return ret

    def getPlantuml(self,doc):
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

    def getDescription(self,doc):
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
                s += self.ret
        return s

# not used yet
def convertCharForHtml(s1):
    s1 = s1.replace('&', '&amp;')
    s1 = s1.replace('<', '&lt;')
    s1 = s1.replace('>', '&gt;')
    s1 = s1.replace('"', "&quot;")
    return s1

if (__name__ == "__main__"):
    parser = argparse.ArgumentParser(
        prog=sys.argv[0],
        description=
        'python sample for analyzing class and their member functions'
    )
    parser.add_argument( '--debug', default=False , action="store_true" , help="debug mode on  default : false")
    parser.add_argument( '--outfile',
        metavar="<str>",
        type=str,
        default='',
        help='if not exist , it prints stdout')
    args = parser.parse_args()

    ddc = DoxyDocsClass(doxydocs=DoxyDocs.D,outfile=args.outfile,debug=args.debug)
    ddc.run()
