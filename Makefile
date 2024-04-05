all:
	make test1

test1:
	make doxygen-ver-check
	cd test-1; touch plantuml.jar
	-cd test-1; doxygen
	cd test-1/output/perlmod; rm -f mysetting.py sample-test.py
	cd test-1/output/perlmod; ln -s ../../../src/mysetting.py mysetting.py
	cd test-1/output/perlmod; ln -s ../../../src/sample.py sample-test.py
	cd test-1/output/perlmod; python3 sample-test.py --outfile=output.md

doxygen-ver-check:
	bash check_doxygen.sh

testserver:
	make doxygen-ver-check
	cd test-server; rm -f plantuml.jar ; touch plantuml.jar
	-cd test-server; doxygen
	cd test-server/output/perlmod; rm -f mysetting.py sample-server.py
	cd test-server/output/perlmod; ln -s ../../../src/mysetting.py mysetting.py
	cd test-server/output/perlmod; ln -s ../../../src/sample.py sample-server.py
	cd test-server/output/perlmod; perl doxy2py.pl
	cd test-server/output/perlmod; python3 sample-server.py --outfile=output.html

testmako:
	make doxygen-ver-check
	cd test-mako; rm -f plantuml.jar ; touch plantuml.jar
	-cd test-mako; doxygen
	cd test-mako/output/perlmod; rm -f mysetting.py sample-mako.py class.mako
	cd test-mako/output/perlmod; ln -s ../../../src/mysetting.py mysetting.py
	cd test-mako/output/perlmod; ln -s ../../../src/sample-mako.py sample-mako.py
	cd test-mako/output/perlmod; ln -s ../../../src/class.mako class.mako
	cd test-mako/output/perlmod; perl doxy2py.pl
	cd test-mako/output/perlmod; python3 sample-mako.py --infile=class.mako

