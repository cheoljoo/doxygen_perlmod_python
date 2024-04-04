#!/bin/bash

target_version="1.11.00"

doxygen_version=$(doxygen -v | cut -d' ' -f1)

version_compare() {
    if [[ $1 == $2 ]]
    then
        return 0
    fi
    local IFS=.
    local i ver1=($1) ver2=($2)
    # fill empty fields in ver1 with zeros
    for ((i=${#ver1[@]}; i<${#ver2[@]}; i++))
    do
        ver1[i]=0
    done
    for ((i=0; i<${#ver1[@]}; i++))
    do
        if [[ -z ${ver2[i]} ]]
        then
            # fill empty fields in ver2 with zeros
            ver2[i]=0
        fi
        if ((10#${ver1[i]} > 10#${ver2[i]}))
        then
            return 1
        fi
        if ((10#${ver1[i]} < 10#${ver2[i]}))
        then
            return 2
        fi
    done
    return 0
}

version_compare $doxygen_version $target_version
case $? in
    0) 
        echo "Doxygen version is exactly $target_version"
        ;;
    1) 
        echo "Doxygen version is greater than $target_version"
        ;;
    2) 
        echo "Doxygen version is less than $target_version"
        git clone https://github.com/cheoljoo/doxygen.git -b 240307/perlmod_python
        cd doxygen; mkdir -p build
        cd build 
        cmake -G "Unix Makefiles" ..
        make
        echo ""
        echo ""
        echo "!! use doxygen/build/bin/doxygen  or add doxygenbuild/bin in your PATH : ${PATH}"
        exit 4
        ;;
esac

