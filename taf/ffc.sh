for i in ../services/*
do
    bn="$(basename ${i})"
    echo "time make -f fc.mk all INDIR=${i} OUTDIR=./module/${bn} MODULE=${bn}"
    time make -f fc.mk all INDIR=${i} OUTDIR=./module/${bn} MODULE=${bn}
    mkdir -p ../debug/${bn}
    cp -r ../taf ../debug/${bn}
done
