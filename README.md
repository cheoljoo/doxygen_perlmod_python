# doxygen_perlmod_python
- developers want to use parsing data from doxygen.
- they want to do something with python.

## Doxyfile
- set **GENERATE_PERLMOD = YES**   and **PERLMOD_PYTHON = YES**
- it gives more examples and usage when you set PERLMOD_PYTHON to YES in Doxyfile

## make test1
- directory : test-1
- Doxyfile
  - PLANTUML_JAR_PATH      = ./plantuml.jar
    - but we do not copy proper plantuml.jar. we use 'touch plantuml.jar' to remove java running time.
- output
	- test-1/output/perlmod/output.md : show markdown including plantuml with vscode (useful extension : markdown preview enhanced)
- [link](test-1/README.md)


# TODO
- make html output with plantuml server 
- make alternative url in html : we can use png file when we have some error to connect to plantuml server
- use mako
- use hpp2plantuml
