# doxygen_perlmod_python
- developers want to use parsing data from doxygen.
- they want to do something with python.

## Doxyfile
- set **GENERATE_PERLMOD = YES**   and **PERLMOD_PYTHON = YES**
- it gives more examples and usage when you set PERLMOD_PYTHON to YES in doxygen

## make python_doc
- DoxyDocs.pm converts to DoxyDocs.py.
  - DoxyDocs.py is loaded in python program.
- sample.py makes markdown (output.md) file as final output.
  - output.md includes table for classes and member functions.
  - if doxygen comments include plantuml , output.md includes plantuml   if you set PLANTUML_JAR_PATH = ./plantuml.jar and this file exists.
- output
	- output.md : show markdown including plantuml with vscode (useful extension : markdown preview enhanced)

## make code2cpp
- add new file in input_perlmodgen_files directory
    - add new line for new file in Makefile : `cd input_perlmodgen_files; ln -s ../[wanted_file] [wanted_file]`
- all codes with related to PERLMOD_PYTHON are created by perlmodgen.cpp.
- put2cpp.py insert converted c++ code into perlmodgen.cpp from files in input_perlmodgen_files directory.
- `--perlmodgen` option : location of perlmodgen.cpp. python codes in inputdir will be updated.
- generated code will be inserted between `// perlmodPython PerlModGenerator [key] <start>` and `// perlmodPython PerlModGenerator [key] <end>`
- output    ( `--perlmodgen=../../../../src/perlmodgen.cpp` )
	- ../../../../src/perlmodgen.cpp.mod : you can replace perlmodgen.cpp with it.
