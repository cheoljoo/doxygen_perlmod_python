all:
	cd ../src; if [ ! -e mysetting.py ]; then cp -f mysetting_example.py mysetting.py; echo "===========.py"; echo "!! edit mysetting.py"; exit 4;  fi
	echo "DoxyDocs.pm is used for this document"
	if [ ! -e mysetting.py ]; then ln -s ../src/mysetting.py mysetting.py; fi
	perl doxy2py.pl
	python3 html.py --outfile=output.html
