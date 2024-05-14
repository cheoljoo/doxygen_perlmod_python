DEST_DIR := "_hpp_"
FILES := $(shell find $(INDIR) -name "*.h" -o -name "*.hpp")
# 절대 경로 변환

all:
#ifndef GITDIR
#@echo "error: GITDIR is not defined"
#exit 4
#endif
#@echo "GITDIR = ${GITDIR}"
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
	if [ ! -e mysetting.py ]; then cp -f ../src/mysetting_example.py mysetting.py; fi
	 #git clone https://github.com/cheoljoo/doxygen_perlmod_python.git ${GITDIR}
	 #mkdir -p ${OUTDIR}/hpp
	 #find ${INDIR} \( -name "*.h" -o -name "*.hpp" \) -exec cp -f {} ${OUTDIR}/hpp \;
	rm -rf plantuml.md
	-doxygen_flowchart > dfc.log
	rm -rf _hpp_ _output_ _plantuml DoxyDocs.pm DoxyDocs.py
	mkdir -p _hpp_
	make copy
	doxygen
	echo "DoxyDocs.pm is used for this document"
	cp -f _output_/perlmod/DoxyDocs.pm .
	perl doxy2py.pl
	bash taf_create_docker.sh
	mkdir -p ${OUTDIR}
	cp -f plantuml.md ${OUTDIR}
	docker run -it  --user `id -u`:`id -g`  -v `pwd`/_hpp_:/docker_in -v `realpath ${OUTDIR}`:/docker_out -v `pwd`:/docker_git -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_git -e DOCKER_MODULE=${MODULE} doxygen_perlmod_python:latest  bash /docker_git/taf_run_in_docker.sh

copy: $(FILES)
	@mkdir -p $(DEST_DIR)
	cp  $^ $(DEST_DIR)

