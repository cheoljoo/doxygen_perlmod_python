# example

## Doxyfile
- GENERATE_PERLMOD = YES
- PERLMOD_PYTHON = YES
- INPUT =  ../doxygen-test-src
- PLANTUML_JAR_PATH = ./plantuml.jar

# new technology
- Mako is a template library written in Python. It provides a familiar, non-XML syntax which compiles into Python modules for maximum performance. Mako's syntax and API borrows from the best ideas of many others, including Django and Jinja2 templates, Cheetah, Myghty, and Genshi. Conceptually, Mako is an embedded Python (i.e. Python Server Page) language, which refines the familiar ideas of componentized layout and inheritance to produce one of the most straightforward and flexible models available, while also maintaining close ties to Python calling and scoping semantics.
  - https://www.makotemplates.org/
- mako is similar to php in web development.
- pip3 install mako

## make testmako
- check doxygen version whether supports PERLMOD_PYTHON
- DoxyDocs.pm converts to DoxyDocs.py.
  - DoxyDocs.py is loaded in python program.
- input : class.mako
- sample-mako.py makes html (class.mako.html) file as final output.
  - class.mako.html includes table for classes and member functions.
- output
  - class.mako.html : you can see the plantuml picture if you set myPlantumlServerProxy and mySrcDirHttp in src/mysetting.py
- If doxygen comments include plantuml , output.html includes plantuml proxy url   if you set PLANTUML_JAR_PATH = ./plantuml.jar and this file exists.
  - I use `touch plantuml.jar` in Makefile. so it will have the follwoing error. but , it will make DoxyDocs.pm rapidly without generating png file.
  - ```
    Generating PlantUML png Files in html
    Error: Invalid or corrupt jarfile ./plantuml.jar
    /home/cheoljoo.lee/code/doxygen_perlmod_python/doxygen-test-src/dog.hpp:24: error: Problems running PlantUML. Verify that the command 'java -jar "./plantuml.jar" -h' works from the command line. Exit code: 1.
    Generating PlantUML eps Files in latex
    Error: Invalid or corrupt jarfile ./plantuml.jar
    /home/cheoljoo.lee/code/doxygen_perlmod_python/doxygen-test-src/dog.hpp:24: error: Problems running PlantUML. Verify that the command 'java -jar "./plantuml.jar" -h' works from the command line. Exit code: 1.
    epstopdf ($Id: epstopdf.pl 48681 2018-09-16 23:03:58Z karl $) 2.28
    !!! Error: Cannot open /home/cheoljoo.lee/code/doxygen_perlmod_python/test-1/output/latex/inline_umlgraph_2.eps: No such file or directory
    /home/cheoljoo.lee/code/doxygen_perlmod_python/doxygen-test-src/dog.hpp:24: error: Problems running epstopdf. Check your TeX installation! Exit code: 2.
    epstopdf ($Id: epstopdf.pl 48681 2018-09-16 23:03:58Z karl $) 2.28
    !!! Error: Cannot open /home/cheoljoo.lee/code/doxygen_perlmod_python/test-1/output/latex/inline_umlgraph_4.eps: No such file or directory
    /home/cheoljoo.lee/code/doxygen_perlmod_python/doxygen-test-src/dog.hpp:24: error: Problems running epstopdf. Check your TeX installation! Exit code: 2.
    ```
