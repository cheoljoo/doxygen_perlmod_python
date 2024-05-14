DEST_DIR := "_hpp_"
SERFILES := $(shell find $(INDIR)/service -name "*.h" -o -name "*.hpp" -o -name "*.hxx")
INCFILES := $(shell find $(INDIR)/include -name "*.h" -o -name "*.hpp" -o -name "*.hxx")
INTFILES := $(shell find $(INDIR)/interface -name "*.h" -o -name "*.hpp" -o -name "*.hxx")
ALL_DIR := "_all_"
SERALLFILES := $(shell find $(INDIR)/service -name "*.h" -o -name "*.hpp" -o -name "*.hxx" -o -name "*.c" -o -name "*.cpp" -o -name "*.cxx")
INCALLFILES := $(shell find $(INDIR)/include -name "*.h" -o -name "*.hpp" -o -name "*.hxx" -o -name "*.c" -o -name "*.cpp" -o -name "*.cxx")
INTALLFILES := $(shell find $(INDIR)/interface -name "*.h" -o -name "*.hpp" -o -name "*.hxx" -o -name "*.c" -o -name "*.cpp" -o -name "*.cxx")
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
	 #rm -rf _hpp_ plantuml.md
	 #mkdir -p _all_
	 #make copyall
	 #-doxygen_flowchart Doxyfile.flowchart > dfc.log
	rm -rf _hpp_ _output_ _plantuml DoxyDocs.pm DoxyDocs.py
	mkdir -p _hpp_
	make copy
	 #doxygen
	 #echo "DoxyDocs.pm is used for this document" > a.log
	 #cp -f _output_/perlmod/DoxyDocs.pm .  >> a.log
	 #echo "doxy2py.pl"  >> a.log
	 #perl doxy2py.pl  >> a.log
	 #echo "taf_create_docker.sh"  >> a.log
	 #/bin/bash taf_create_docker.sh  >> a.log
	 #echo "mkdir -p ${OUTDIR}"  >> a.log
	 #mkdir -p ${OUTDIR}  >> a.log
	 #if [ -e plantuml.md ]; then cp -f plantuml.md ${OUTDIR}; fi
	 #docker run -it  --user `id -u`:`id -g`  -v `pwd`/_hpp_:/docker_in -v `realpath ${OUTDIR}`:/docker_out -v `pwd`:/docker_git -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_git -e DOCKER_MODULE=${MODULE} doxygen_perlmod_python:latest  bash /docker_git/taf_run_in_docker.sh  >> a.log

copy: $(SERFILES) $(INCFILES) $(INTFILES)
	@mkdir -p $(DEST_DIR)
	cp  $^ $(DEST_DIR)

copyall: $(SERALLFILES) $(INCALLFILES) $(INTALLFILES)
	@mkdir -p $(ALL_DIR)
	cp  $^ $(ALL_DIR)
