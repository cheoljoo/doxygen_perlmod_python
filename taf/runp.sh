rm -rf _doc_* DoxyDocs.pm DoxyDocs.py
rm -rf /home/cheoljoo.lee/temp/report-doc/*
python3 runParallel.py  --inDir=../services --outReportDir=/home/cheoljoo.lee/temp/report-doc --parallel --endExt="h,hpp,hxx" --mk=taf-doc.mk
