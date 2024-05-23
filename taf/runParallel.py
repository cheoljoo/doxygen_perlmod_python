import sys,os
sys.path.append(os.getcwd())
import argparse
import json
import shutil
from pprint import pprint
from multiprocessing import Pool
from functools import partial
import subprocess

prefixDir = '_doc_service_'

def work_func(x,outdir):
     #print(args.outReportDir , outdir)
    module = x.replace(prefixDir,'')
     #print(x,module,flush=True)
    cmd = '''cd {x}; make -f taf-doc.mk INDIR=_hpp_ OUTDIR={o}/{m} MODULE="{m}" '''.format(x=x,o=outdir,m=module)
     #print(cmd,flush=True)
    ret = subprocess.run(cmd,stdout=subprocess.PIPE , stderr=subprocess.PIPE, shell=True,text=True)
    os.system('stty sane')
    os.system('stty erase ^H')
    print(cmd, ret.returncode)
    return ret.returncode , ret.stdout , ret.stderr

if (__name__ == "__main__"):
    parser = argparse.ArgumentParser(
        prog=sys.argv[0],
        description=
        'copy file to <specific-dir> : starts with <specific-dirname> and ends with <specific-extension>'
    )
    parser.add_argument( '--inDir', 
        metavar="<str>",
        type=str,
        required=True,
        help='starting directory for searching')
    parser.add_argument( '--startDirname', 
        metavar="<str>",
        type=str,
        default='service,include,interface',
        help='several starting directory name with comma in <inDir>')
    parser.add_argument( '--endExt',
        metavar="<str>",
        type=str,
        default='h,hpp,hxx',
        help='several extension with comma in <inDir>')
    parser.add_argument( '--outReportDir',
        metavar="<str>",
        type=str,
        required=True,
        help='output directory for document result')
    parser.add_argument( '--variant',
        metavar="<str>",
        type=str,
        default='',
        help='common variant postfix')
    parser.add_argument( '--parallel', default=False , action="store_true" , help="run parallelly      default : run on single thread")
    args = parser.parse_args()

    doc_target = []   # get sub directory under services (core/variant)
    for t in os.listdir('.'):
        if os.path.isdir(t) and t.startswith(prefixDir):
            doc_target.append(t)
    if len(doc_target):
        print('already existed doc_target',doc_target , 'len',len(doc_target),'doc targets')
        print('move _doc_service_* to done_doc_service_*')
        for t in doc_target:
            ret = subprocess.run('mv -f {f} {t}'.format(f=t,t='done'+t),stdout=subprocess.PIPE , stderr=subprocess.PIPE, shell=True,text=True)

    os.makedirs(args.outReportDir,exist_ok=True)
    startList = [ x.strip() for x in args.startDirname.split(',') ]
    extList = [ x.strip() for x in args.endExt.split(',') ]
    excludeList = ['mock','unittest','uts']
    filecnt = {}
    
    target = []   # get sub directory under services (core/variant)
    print(args.inDir)
    for t in os.listdir(args.inDir):
        if os.path.isdir(os.path.join(args.inDir, t)):
            target.append(t)
    print('target',target,'len',len(target),'modules')

    for t in target:
        if t.find('telephony-service') >= 0 :
            inputDir = os.path.join(args.inDir, t)
            shutil.rmtree(prefixDir+'telephony-interface'+args.variant,ignore_errors=True)
            targetDir = os.path.join(prefixDir+'telephony-interface'+args.variant,'_hpp_')
            os.makedirs(targetDir,exist_ok=True)
            shutil.copy('taf-doc.mk', prefixDir+'telephony-interface'+args.variant)
            for root , dirs,files in os.walk(inputDir + '/interface'):
                for file in files:
                    exclFlag = False
                    for excl in excludeList:
                        if file.lower().find(excl) >= 0:
                            exclFlag = True
                            break
                    if exclFlag :
                        continue
                    if file.split('.')[-1] in extList:
                         #print('copy',os.path.join(root, file), targetDir)
                        tname = 'telephony-interface'+args.variant
                        if tname not in filecnt:
                            filecnt[tname] = 0
                        filecnt[tname] += 1
                        shutil.copy(os.path.join(root, file), targetDir)
            for servicefile in os.listdir(args.inDir + '/' + t + '/service'):
                 #print('servicefile:',servicefile)
                if os.path.isfile(os.path.join(args.inDir + '/' + t + '/service',servicefile)):
                     #print('file:',servicefile)
                    if servicefile.split('.')[-1] in extList:
                         #print('copy',os.path.join(args.inDir + '/' + t + '/service', servicefile), targetDir)
                        tname = 'telephony-interface'+args.variant
                        if tname not in filecnt:
                            filecnt[tname] = 0
                        filecnt[tname] += 1
                        shutil.copy(os.path.join(args.inDir + '/' + t + '/service',servicefile), targetDir)
                elif os.path.isdir(os.path.join(args.inDir + '/' + t + '/service',servicefile)):
                    inputDirSub = os.path.join(args.inDir + '/' + t + '/service', servicefile)
                    shutil.rmtree(prefixDir+'telephony-service-'+servicefile+args.variant,ignore_errors=True)
                    targetDirSub = os.path.join(prefixDir+'telephony-service-'+servicefile+args.variant,'_hpp_')
                    os.makedirs(targetDirSub,exist_ok=True)
                    shutil.copy('taf-doc.mk', prefixDir+'telephony-service-'+servicefile+args.variant)
                     #print('dir:',servicefile , inputDirSub , targetDirSub )
                    for root , dirs,files in os.walk(inputDirSub):
                         #print(files)
                        for file in files:
                            exclFlag = False
                            for excl in excludeList:
                                if file.lower().find(excl) >= 0:
                                    exclFlag = True
                                    break
                            if exclFlag :
                                continue
                            if file.split('.')[-1] in extList:
                                 #print('copy',os.path.join(root, file), targetDirSub)
                                tname = 'telephony-service-'+servicefile+args.variant
                                if tname not in filecnt:
                                    filecnt[tname] = 0
                                filecnt[tname] += 1
                                shutil.copy(os.path.join(root, file), targetDirSub)
                else:
                    print('error:' , file)
            continue
        inputDir = os.path.join(args.inDir, t)
        shutil.rmtree(prefixDir+t+args.variant,ignore_errors=True)
        targetDir = os.path.join(prefixDir+t+args.variant,'_hpp_')
        os.makedirs(targetDir,exist_ok=True)
        shutil.copy('taf-doc.mk', prefixDir+t+args.variant)
        for s in startList:
            for root , dirs,files in os.walk(inputDir + '/' + s):
                 #print(root,files)
                for file in files:
                    exclFlag = False
                    for excl in excludeList:
                        if file.lower().find(excl) >= 0:
                            exclFlag = True
                            break
                    if exclFlag :
                        continue
                    if file.split('.')[-1] in extList:
                         #print('copy',os.path.join(root, file), targetDir)
                        tname = t+args.variant
                        if tname not in filecnt:
                            filecnt[tname] = 0
                        filecnt[tname] += 1
                        shutil.copy(os.path.join(root, file), targetDir)
        
    pprint( {'copy file count of '+sys.argv[0] : filecnt } )

    print('==> Done : create _doc_service_*/_hpp_ , run taf-doc.mk')
    print()

    ret = subprocess.run('taf_create_docker.sh',stdout=subprocess.PIPE , stderr=subprocess.PIPE, shell=True,text=True)
    print('taf_create_docker.sh : return code', ret.returncode,flush=True)
    print('==> Done : make running environment')
    print()

    doc_target = []   # get sub directory under services (core/variant)
    for t in os.listdir('.'):
        if os.path.isdir(t) and t.startswith(prefixDir):
            doc_target.append(t)
    print('doc_target',doc_target , 'len',len(doc_target),'doc targets')
    if args.parallel:
        print('parallel running...')
        num_cores = 32 # 32
        pool = Pool(num_cores)
        partial_func = partial(work_func,outdir=args.outReportDir)
        rt = pool.map(partial_func, doc_target)
        os.system('stty sane')
        os.system('stty erase ^H')
        cnt = 0
        for r,ro,re in rt:
            if r:
                cnt += 1
                print()
                print('[',cnt,']','ReturnCode:',r, flush=True)
                print('Output:',flush=True)
                print(ro,flush=True)
                print('Error Output:',flush=True)
                print(re,flush=True)
        if cnt :
            quit(4)
        print('(p) all success : output is',args.outReportDir)
    else:
        print('single running...')
        for x in doc_target:
            r,ro,re = work_func(x,outdir=args.outReportDir)
            if r:
                print('ReturnCode:',r, flush=True)
                print('Output:',flush=True)
                print(ro,flush=True)
                print('Error Output:',flush=True)
                print(re,flush=True)
                quit(4)
        print('(s) all success : output is',args.outReportDir)
