import sys,os
sys.path.append(os.getcwd())
import mysetting
import DoxyDocs
import argparse
from mako.template import Template

class DoxyDocsClass :
    '''
    analyze classes as example. it will print table for class with markdown format
    '''
    def __init__(self,doxydocs={},infile='',outfile='',debug=False,service=''):
        self.plantumlCnt = 0
        self.ret = '<br>'   # or  '\\n'

        self.D = doxydocs
        self.outfile = outfile
        self.infile = infile
        self.debug = debug
        self.service = service
        self.of = None
        self.html = False

    def run(self):
        if not self.outfile:
            self.outfile = self.infile + '.html'
        template = Template(filename=self.infile, input_encoding='utf-8', output_encoding='utf-8')
        self.D['service'] = self.service
        with open(self.outfile, mode='wb') as f:
            f.write(template.render(D=self.D,myPlantumlServerProxy=mysetting.myPlantumlServerProxy,mySrcDirHttp=mysetting.mySrcDirHttp))
            print('! output (html) using mako is {f}'.format(f=os.getcwd()+'/'+self.outfile),file=sys.stderr)

if (__name__ == "__main__"):
    parser = argparse.ArgumentParser(
        prog=sys.argv[0],
        description=
        'python sample for analyzing class and their member functions using mako module'
    )
    parser.add_argument( '--debug', default=False , action="store_true" , help="debug mode on  default : false")
    parser.add_argument( '--infile', 
        metavar="<str>",
        type=str,
        default='class.mako',
        help='input filename')
    parser.add_argument( '--outfile',
        metavar="<str>",
        type=str,
        default='',
        help='output filename : if not exist , it prints stdout')
    parser.add_argument( '--service',
        metavar="<str>",
        type=str,
        default='Perlmod Python Service',
        help='service name')
    args = parser.parse_args()

    ddc = DoxyDocsClass(doxydocs=DoxyDocs.D,infile=args.infile,outfile=args.outfile,debug=args.debug,service=args.service)
    ddc.run()
