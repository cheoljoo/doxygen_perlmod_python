- parallelization

``` Makefile
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
	docker run -it --rm  --user `id -u`:`id -g`  -v `pwd`/_hpp_:/docker_in -v `realpath ${OUTDIR}`:/docker_out -v `pwd`:/docker_git -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_git -e DOCKER_MODULE="${MODULE}" doxygen_perlmod_python:latest  bash /docker_git/taf_run_in_docker.sh 
	echo "OUTPUT directory : ${newOUTDIR}"
	 #if [ -e plantuml.md ]; then echo "parse_flowchart.py --inpuml=plantuml.md --outjson=plantuml.json"; python3 parse_flowchart.py --inpuml=plantuml.md --outjson=plantuml.json; fi
	 #if [ -e plantuml.md ]; then echo "copy plantuml.md ${OUTDIR}"; cp -f plantuml.md ${OUTDIR} ; fi
	 #if [ -e plantuml.json ]; then echo "taf_run_flowchart_in_docker.sh" ;  mkdir -p ${OUTDIR}/flowchart;  docker run -it  --user `id -u`:`id -g`  -v `pwd`/_hpp_:/docker_in -v `realpath ${OUTDIR}/flowchart`:/docker_out -v `pwd`:/docker_git -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_git -e DOCKER_MODULE=${MODULE} doxygen_perlmod_python:latest  bash /docker_git/taf_run_flowchart_in_docker.sh >> doxygen_perlmod_python.log  2>&1 ; fi
	if [ -e doxygen_perlmod_python.log ]; then echo "copy doxygen_perlmod_python.log ${OUTDIR}"; cp -f doxygen_perlmod_python.log ${OUTDIR} ; fi
```
- Run with one service
    - ```Makefile```
    - ${INDIR} : service directory with service and interface direcotry
        - if ${INDIR} includes telephony-service , we traverse all directory in it.
    - ${OUTDIR} : result directory with class.mako.html and multiple puml file (plantuml)
    - ${MODULE} : it will be used as title of html
    - copyFile.py 
        - copy files from started with --startDirname and with extention of --endExt   to  --destDir
    - doxygen : generate perlmod (DoxyDocs.pm)
    - doxy2py.pl : convert to python (DoxyDocs.pm -> DoxyDocs.py)
    - taf_create_docker.sh :  
        - if doxygen_perlmod_python image exists , it is ok. But if not , generate doxygen_perlmod_python image from vaeum/alpine-python3-pip3:lastest.
            - docker run vaeum/alpine-python3-pip3 with install script (/docker_in/taf_install_in_docker.sh) -> docker commit with doxygen_perlmod_python.
            - /docker_in/taf_install_in_docker.sh wil install hpp2plantuml and mako python package.
        - ```
          REPOSITORY                  TAG                                IMAGE ID       CREATED         SIZE
          doxygen_perlmod_python      latest                             31d637327f92   5 days ago      345MB
          <none>                      <none>                             6b20c8924573   9 days ago      345MB
          ubuntu                      latest                             bf3dc08bfed0   3 weeks ago     76.2MB
          pthread0/tiger-docker       65b9dfec2f75f3f4274799020aac9ac0   08b550dc7c5d   6 weeks ago     9.07GB
          plantuml/plantuml-server    jetty                              fa91ba22c075   6 weeks ago     465MB
          plantuml/plantuml-server    latest                             fa91ba22c075   6 weeks ago     465MB
          plantuml/plantuml-server    tomcat                             9c47d75cb058   6 weeks ago     596MB
          ghcr.io/lhoupert/scc        master                             89c0b7d8b505   3 months ago    13.6MB
          <none>                      <none>                             4ce7c7bf6be1   7 months ago    124MB
          gitlab/gitlab-runner        latest                             221393961331   10 months ago   756MB
          plantuml/plantuml-server    <none>                             0cad2de632fd   13 months ago   905MB
          cheoljoo/ubuntu20-dlt       init                               471190794925   2 years ago     177MB
          vaeum/alpine-python3-pip3   latest                             63a9d299ea3f   6 years ago     255MB
          ```
    - docker run doxygen_perlmod_python:latest : run hpp2plantuml and mako
    - example : 
        - c.sh  : ../services/call
        - mm.sh : ../services/region-service

- Run with multiple service (ex. taf)
    - we start runParallel.py instead of Makefile.
        - runParallel.py will call Makefile.
    - ${INDIR}  has several services 
        - ${INDIR}=../services
    - run.sh : make document sequentially
    - runp.sh : make document parallelly

- appendix
    - docker has -v option. but it must have absolute path.
    - my all output html is class.mako.html
