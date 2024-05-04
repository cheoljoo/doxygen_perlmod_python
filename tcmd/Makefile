DEST_DIR := "_hpp_"
FILES := $(shell find $(INDIR) -name "*.h" -o -name "*.hpp")
FILE_HTTP := "http://tiger02.lge.com/cheoljoo.lee/code/doxygen_perlmod_python/tcmd"

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
ifdef FILE_HTTP_URL
	$(eval FILE_HTTP = ${FILE_HTTP_URL})
endif
	@echo "FILE_HTTP = ${FILE_HTTP}"
	@echo "FILES = ${FILES}"
	if [ ! -e mysetting.py ]; then cp -f ../src/mysetting_example.py mysetting.py; fi
	 #git clone https://github.com/cheoljoo/doxygen_perlmod_python.git ${GITDIR}
	 #mkdir -p ${OUTDIR}/hpp
	 #find ${INDIR} \( -name "*.h" -o -name "*.hpp" \) -exec cp -f {} ${OUTDIR}/hpp \;
	rm -rf _hpp_ _output_ _plantuml
	mkdir -p _hpp_
	make copy
	doxygen
	echo "DoxyDocs.pm is used for this document"
	cp -f _output_/perlmod/DoxyDocs.pm .
	perl doxy2py.pl
	 #git clone for doxygen_perlmod_python in ${GITDIR}
	 #copy from ${INDIR} , Doxyfile to ${OUTDIR}/md/module/basename/hhh (header)
	 #gen doxygen to ${OUTDIR}/md/module/basename/hhh/output (doxygen)
	 #copy from ${INDIR} to ${OUTDIR}/md/module/basename/class.mako.html
	 #copy doxygen _output_ (DoxyDocs.pm)  to ${OUTDIR}/md/module/basename
	 # do run the following things
	python3 hpp2plantuml.py $(shell find ${INDIR} \( -name "*.h" -o -name "*.hpp" \) -print0 | xargs -0 -n 1 echo -i) -o all.puml -j out.json
	# if we use -j option in hpp2plantuml  , parse_hpp2plantuml.py is useless.
	#python3 parse_hpp2plantuml.py --inpuml=all.puml --outjson=parse-out.json
	python3 sample-mako.py --infile=class.mako --service="${MODULE} Service"  --plantumlServerProxy="http://tiger02.lge.com:18080/proxy?fmt=svg"  --fileHttpUrl=${FILE_HTTP} --tcmdoutdir=${OUTDIR}

copy: $(FILES)
	@mkdir -p $(DEST_DIR)
	cp  $^ $(DEST_DIR)

