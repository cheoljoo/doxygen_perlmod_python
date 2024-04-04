all:
	make test1

test1:
	make doxygen-ver-check
	cd test-1; touch plantuml.jar
	-cd test-1; doxygen
	cp -f src/sample.py test-1/output/perlmod
	cd test-1/output/perlmod; make python_doc

doxygen-ver-check:
	bash check_doxygen.sh
