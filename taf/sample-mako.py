import sys,os
sys.path.append(os.getcwd())
import mysetting
import DoxyDocs
import argparse
import json
import shutil
from mako.template import Template

class DoxyDocsClass :
    '''
    analyze classes as example. it will print table for class with markdown format
    '''
    def __init__(self,doxydocs={},infile='',outfile='',debug=False,service='',plantumlServerProxy='',tcmdoutdir=''):
        self.plantumlCnt = 0
        self.ret = '<br>'   # or  '\\n'

        self.D = doxydocs
        self.outfile = outfile
        self.infile = infile
        self.debug = debug
        self.service = service
        self.plantumlServerProxy = plantumlServerProxy
        self.tcmdoutdir = tcmdoutdir
        self.of = None
        self.html = False

    def run(self):
        if not self.outfile:
            self.outfile = self.infile.split('/')[-1]+ '.html'
        template = Template(filename=self.infile, input_encoding='utf-8', output_encoding='utf-8')
        self.D['_template__'] = {}
        self.D['_template__']['service'] = self.service
        self.D['_template__']['files'] = []
        self.D['_template__']['files'].append(self.outfile)
        self.D['_template__']['myPlantumlServerProxy'] = mysetting.myPlantumlServerProxy
        if self.plantumlServerProxy:
            self.D['_template__']['myPlantumlServerProxy'] = self.plantumlServerProxy
        self.D['_template__']['mySrcDirHttp'] = mysetting.mySrcDirHttp
        self.D['_template__']['tcmdoutdir'] = self.tcmdoutdir
        with open(self.outfile, mode='wb') as f:
            print('write:',self.outfile)
            f.write(template.render(D=self.D))
            print('! output (html) using mako is {f}'.format(f=os.getcwd()+'/'+self.D['_template__']['tcmdoutdir']+'/'+self.outfile),file=sys.stderr)
            print('! http (html) using mako is {f}'.format(f=self.D['_template__']['mySrcDirHttp']+'/'+self.D['_template__']['tcmdoutdir']+'/'+self.outfile),file=sys.stderr)
        with open('_save-files.json','w') as jsonf:
            json.dump(self.D['_template__'],jsonf,indent = 4)
        if self.D['_template__']['tcmdoutdir']:
            os.makedirs(self.D['_template__']['tcmdoutdir'],exist_ok=True)
            for filename in os.listdir(self.D['_template__']['tcmdoutdir']):
                file_path = os.path.join(self.D['_template__']['tcmdoutdir'], filename)
                try:
                    if os.path.isfile(file_path) or os.path.islink(file_path):
                        os.unlink(file_path)
                    elif os.path.isdir(file_path):
                        print(f"Skipping directory: {file_path}")
                except Exception as e:
                    print(f'Failed to delete {file_path}. Reason: {e}')
            for source_file in self.D['_template__']['files']:
                try:
                    destination_file = os.path.join(self.D['_template__']['tcmdoutdir'], os.path.basename(source_file))
                    print(f'File copied successfully from {source_file} to {destination_file}')
                    shutil.copy(source_file, destination_file)
                     #print(f'File copied successfully from {source_file} to {destination_file}')
                except IOError as e:
                    print(f'Unable to copy file. {e}')
                except Exception as e:
                    print(f'An unexpected error occurred: {e}')
    
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
    parser.add_argument( '--plantumlServerProxy',
        metavar="<str>",
        type=str,
        default='',
        help='plantuml proxy server url   ex) http://plantuml.proxy.com:18080/proxy?fmt=svg')
    parser.add_argument( '--tcmdoutdir',
        metavar="<str>",
        type=str,
        default='',
        help='output directory for tcmd to gather serviced files')
    args = parser.parse_args()

    print('====start',sys.argv[0])
    ddc = DoxyDocsClass(doxydocs=DoxyDocs.D,infile=args.infile,outfile=args.outfile,debug=args.debug,service=args.service,plantumlServerProxy=args.plantumlServerProxy,tcmdoutdir=args.tcmdoutdir)
    ddc.run()
