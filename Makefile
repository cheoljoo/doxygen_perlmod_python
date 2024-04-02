all:
	make test1

test1:
	cd test-1; touch plantuml.jar
	-cd test-1; doxygen
	cp -f src/sample.py test-1/output/perlmod
	cd test-1/output/perlmod; make python_doc

