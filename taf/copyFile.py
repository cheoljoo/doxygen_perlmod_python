import sys,os
sys.path.append(os.getcwd())
import argparse
import json
import shutil

if (__name__ == "__main__"):
    parser = argparse.ArgumentParser(
        prog=sys.argv[0],
        description=
        'copy file to <specific-dir> : starts with <specific-dirname> and ends with <specific-extension>'
    )
    parser.add_argument( '--inDir', 
        metavar="<str>",
        type=str,
        default='core/service',
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
    parser.add_argument( '--destDir',
        metavar="<str>",
        type=str,
        default='_hpp_',
        help='output directory for tcmd to gather serviced files')
    args = parser.parse_args()

    os.makedirs(args.destDir,exist_ok=True)
    startList = [ x.strip() for x in args.startDirname.split(',') ]
    extList = [ x.strip() for x in args.endExt.split(',') ]

    for s in startList:
        for root , dirs,files in os.walk(args.inDir + '/' + s):
            print(root,files)
            for file in files:
                if file.split('.')[-1] in extList:
                    print('copy',os.path.join(root, file), args.destDir)
                    shutil.copy(os.path.join(root, file), args.destDir)
        
