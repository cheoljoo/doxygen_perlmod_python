newOUTDIR:=`realpath ${OUTDIR}`

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
	if [ ! -e mysetting.py ]; then cp -f ../../src/mysetting_example.py mysetting.py; fi
	rm -f plantuml.md plantuml.json
	rm -rf _output_ _plantuml DoxyDocs.pm DoxyDocs.py
	which doxygen
	echo "doxygen"
	-doxygen  ../Doxyfile      # _hpp_
	echo "DoxyDocs.pm is used for this document" 
	cp -f _output_/perlmod/DoxyDocs.pm . 
	echo "doxy2py.pl" 
	-perl ../doxy2py.pl
	-echo "mkdir -p ${OUTDIR}" 
	-mkdir -p ${OUTDIR}
	echo "docker run --rm  --user `id -u`:`id -g`  -v `pwd`/_hpp_:/docker_in -v `realpath ${OUTDIR}`:/docker_out -v `pwd`/..:/docker_git -v `pwd`:/docker_now -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_git -e DOCKER_MODULE=${MODULE} doxygen_perlmod_python:latest  bash /docker_git/taf-doc_run_in_docker.sh"
	docker run --rm  --user `id -u`:`id -g`  -v `pwd`/_hpp_:/docker_in -v `realpath ${OUTDIR}`:/docker_out -v `pwd`/..:/docker_git -v `pwd`:/docker_now -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_git -e DOCKER_MODULE="${MODULE}" doxygen_perlmod_python:latest  bash /docker_git/taf-doc_run_in_docker.sh
	echo "OUTPUT directory : ${newOUTDIR}"
	if [ -e doxygen_perlmod_python.log ]; then echo "copy doxygen_perlmod_python.log ${OUTDIR}"; cp -f doxygen_perlmod_python.log ${OUTDIR} ; fi
	if [ -e DoxyDocs.py ]; then echo "copy DoxyDocs.py ${OUTDIR}"; cp -f DoxyDocs.py ${OUTDIR} ; fi
