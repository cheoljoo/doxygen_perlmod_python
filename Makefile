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
	cd test-server; touch plantuml.jar
	-cd test-server; doxygen
	cd test-server/output/perlmod; rm -f mysetting.py sample-server.py
	cd test-server/output/perlmod; ln -s ../../../src/mysetting.py mysetting.py
	cd test-server/output/perlmod; ln -s ../../../src/sample.py sample-server.py
	cd test-server/output/perlmod; perl doxy2py.pl
	cd test-server/output/perlmod; python3 sample-server.py --outfile=output.html

