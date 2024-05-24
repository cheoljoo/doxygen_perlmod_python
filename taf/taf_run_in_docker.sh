# docker image (doxygen_perlmod_python:latest) is created from docker image(vaeum/alpine-python3-pip3) with taf_install.sh
# docker run -it  --user `id -u`:`id -g`  -v  `pwd`:/docker_in -v `pwd`/op:/docker_out -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_in doxygen_perlmod_python:latest  bash /docker_in/taf_run.sh
umask 000
chmod 777 -R ${DOCKER_OUT}
echo "DOCKER_IN ${DOCKER_IN}"
echo "DOCKER_GIT ${DOCKER_GIT}"
echo "DOCKER_OUT ${DOCKER_OUT}"
echo "DOCKER_MODULE ${DOCKER_MODULE}"
#ls -l  ${DOCKER_OUT}
cd ${DOCKER_GIT}; python3 hpp2plantuml.py --input-directory=${DOCKER_IN} -o all.puml -j out.json
cd ${DOCKER_GIT}; python3 sample-mako.py --infile=class.mako --service="${DOCKER_MODULE}"  --plantumlServerProxy="http://tiger02.lge.com:18080/proxy?fmt=svg"  --tcmdoutdir=${DOCKER_OUT}
