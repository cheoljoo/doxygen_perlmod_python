
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
	@echo "FILES = ${FILES}"
	rm -rf _hpp_  _all_
	python3 copyFile.py --inDir=${INDIR} --startDirname="service,include,interface" --endExt="hpp,hxx,h" --destDir="_hpp_"
	python3 copyFile.py --inDir=${INDIR} --startDirname="service,include,interface" --endExt="hpp,hxx,h,c,cpp,cxx" --destDir="_all_"
	if [ ! -e mysetting.py ]; then cp -f ../src/mysetting_example.py mysetting.py; fi
	rm -rf plantuml.md
	-doxygen_flowchart Doxyfile.flowchart > dfc.log    # _all_
	rm -rf _output_ _plantuml DoxyDocs.pm DoxyDocs.py
	doxygen         # _hpp_
	echo "DoxyDocs.pm is used for this document" > a.log
	cp -f _output_/perlmod/DoxyDocs.pm .  >> a.log
	echo "doxy2py.pl"  >> a.log
	perl doxy2py.pl  >> a.log
	echo "taf_create_docker.sh"  >> a.log
	/bin/bash taf_create_docker.sh  >> a.log
	echo "mkdir -p ${OUTDIR}"  >> a.log
	mkdir -p ${OUTDIR}  >> a.log
	if [ -e plantuml.md ]; then cp -f plantuml.md ${OUTDIR}; fi
	docker run -it  --user `id -u`:`id -g`  -v `pwd`/_hpp_:/docker_in -v `realpath ${OUTDIR}`:/docker_out -v `pwd`:/docker_git -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_git -e DOCKER_MODULE=${MODULE} doxygen_perlmod_python:latest  bash /docker_git/taf_run_in_docker.sh  >> a.log
