newOUTDIR:=`pwd`/${OUTDIR}

all:
ifndef INDIR
	@echo "error: INDIR is not defined"
	exit 4
endif
	@echo "INDIR = ${INDIR}"
ifndef OUTDIR
	@echo "error: OUTDIR is not defined"
	exit 4
endif
	@echo "OUTDIR = ${OUTDIR}"
	@echo "MODULE = ${MODULE}"
	rm -rf _hpp_  _all_
	python3 copyFile.py --inDir=${INDIR} --startDirname="service,include,interface" --endExt="hpp,hxx,h" --destDir="_hpp_"  > doxygen_perlmod_python.log 
	 #python3 copyFile.py --inDir=${INDIR} --startDirname="service,include,interface" --endExt="hpp,hxx,h,c,cpp,cxx" --destDir="_all_"  >> doxygen_perlmod_python.log  2>&1 
	if [ ! -e mysetting.py ]; then cp -f ../src/mysetting_example.py mysetting.py; fi
	rm -f plantuml.md plantuml.json
	echo "doxgen_flowchart"
	 #-./doxygen_flowchart Doxyfile.flowchart > /dev/null  2>&1   # _all_
	rm -rf _output_ _plantuml DoxyDocs.pm DoxyDocs.py
	echo "doxgen"
	doxygen  >> doxygen_perlmod_python.log  2>&1        # _hpp_
	echo "DoxyDocs.pm is used for this document" 
	cp -f _output_/perlmod/DoxyDocs.pm . 
	echo "doxy2py.pl" 
	perl doxy2py.pl  >> doxygen_perlmod_python.log 2>&1
	echo "taf_create_docker.sh"
	/bin/bash taf_create_docker.sh  >> doxygen_perlmod_python.log 2>&1
	echo "mkdir -p ${OUTDIR}" 
	mkdir -p ${OUTDIR}
	docker run -it  --user `id -u`:`id -g`  -v `pwd`/_hpp_:/docker_in -v `realpath ${OUTDIR}`:/docker_out -v `pwd`:/docker_git -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_git -e DOCKER_MODULE="${MODULE}" doxygen_perlmod_python:latest  bash /docker_git/taf_run_in_docker.sh 
	echo "OUTPUT directory : ${newOUTDIR}"
	 #if [ -e plantuml.md ]; then echo "parse_flowchart.py --inpuml=plantuml.md --outjson=plantuml.json"; python3 parse_flowchart.py --inpuml=plantuml.md --outjson=plantuml.json; fi
	 #if [ -e plantuml.md ]; then echo "copy plantuml.md ${OUTDIR}"; cp -f plantuml.md ${OUTDIR} ; fi
	 #if [ -e plantuml.json ]; then echo "taf_run_flowchart_in_docker.sh" ;  mkdir -p ${OUTDIR}/flowchart;  docker run -it  --user `id -u`:`id -g`  -v `pwd`/_hpp_:/docker_in -v `realpath ${OUTDIR}/flowchart`:/docker_out -v `pwd`:/docker_git -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_git -e DOCKER_MODULE=${MODULE} doxygen_perlmod_python:latest  bash /docker_git/taf_run_flowchart_in_docker.sh >> doxygen_perlmod_python.log  2>&1 ; fi
	if [ -e doxygen_perlmod_python.log ]; then echo "copy doxygen_perlmod_python.log ${OUTDIR}"; cp -f doxygen_perlmod_python.log ${OUTDIR} ; fi
