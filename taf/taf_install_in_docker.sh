# docker run -it  -v `pwd`:/docker_in -v `pwd`:/docker_out -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out vaeum/alpine-python3-pip3 bash /docker_in/taf_install.sh
echo "DOCKER_IN ${DOCKER_IN}"
echo "DOCKER_GIT ${DOCKER_GIT}"
echo "DOCKER_OUT ${DOCKER_OUT}"
pip install --upgrade pip --trusted-host pypi.org --trusted-host pypi.python.org --trusted-host files.pythonhosted.org
pip install hpp2plantuml mako --trusted-host pypi.org --trusted-host pypi.python.org --trusted-host files.pythonhosted.org
