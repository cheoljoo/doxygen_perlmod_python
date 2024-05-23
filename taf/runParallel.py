import sys,os
sys.path.append(os.getcwd())
import argparse
import json
import shutil
from pprint import pprint

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
    args = parser.parse_args()

    prefixDir = '_doc_service_'
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
    print('target',target)

    for t in target:
        if t.find('telephony-service') >= 0 :
            inputDir = os.path.join(args.inDir, t)
            shutil.copy('taf-doc.mk', prefixDir+'telephony-interface')
            targetDir = os.path.join(prefixDir+'telephony-interface','_hpp_')
            os.makedirs(targetDir,exist_ok=True)
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
                        print('copy',os.path.join(root, file), targetDir)
                        tname = 'telephony-interface'
                        if tname not in filecnt:
                            filecnt[tname] = 0
                        filecnt[tname] += 1
                        shutil.copy(os.path.join(root, file), targetDir)
            for servicefile in os.listdir(args.inDir + '/' + t + '/service'):
                print('servicefile:',servicefile)
                if os.path.isfile(os.path.join(args.inDir + '/' + t + '/service',servicefile)):
                    print('file:',servicefile)
                    if servicefile.split('.')[-1] in extList:
                        print('copy',os.path.join(args.inDir + '/' + t + '/service', servicefile), targetDir)
                        tname = 'telephony-interface'
                        if tname not in filecnt:
                            filecnt[tname] = 0
                        filecnt[tname] += 1
                        shutil.copy(os.path.join(args.inDir + '/' + t + '/service',servicefile), targetDir)
                elif os.path.isdir(os.path.join(args.inDir + '/' + t + '/service',servicefile)):
                    inputDirSub = os.path.join(args.inDir + '/' + t + '/service', servicefile)
                    shutil.copy('taf-doc.mk', prefixDir+'telephony-service-'+servicefile)
                    targetDirSub = os.path.join(prefixDir+'telephony-service-'+servicefile,'_hpp_')
                    os.makedirs(targetDirSub,exist_ok=True)
                    print('dir:',servicefile , inputDirSub , targetDirSub )
                    for root , dirs,files in os.walk(inputDirSub):
                        print(files)
                        for file in files:
                            exclFlag = False
                            for excl in excludeList:
                                if file.lower().find(excl) >= 0:
                                    exclFlag = True
                                    break
                            if exclFlag :
                                continue
                            if file.split('.')[-1] in extList:
                                print('copy',os.path.join(root, file), targetDirSub)
                                tname = 'telephony-service-'+servicefile
                                if tname not in filecnt:
                                    filecnt[tname] = 0
                                filecnt[tname] += 1
                                shutil.copy(os.path.join(root, file), targetDirSub)
                else:
                    print('error:' , file)
            continue
        inputDir = os.path.join(args.inDir, t)
        shutil.copy('taf-doc.mk', prefixDir+t)
        targetDir = os.path.join(prefixDir+t,'_hpp_')
        os.makedirs(targetDir,exist_ok=True)
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
                        print('copy',os.path.join(root, file), targetDir)
                        if t not in filecnt:
                            filecnt[t] = 0
                        filecnt[t] += 1
                        shutil.copy(os.path.join(root, file), targetDir)
        
    pprint( {'copy file count of '+sys.argv[0] : filecnt } )
