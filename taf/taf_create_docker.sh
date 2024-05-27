# docker run -v `pwd`:/docker_in -v `pwd`:/docker_out -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out vaeum/alpine-python3-pip3 bash /docker_in/taf_install.sh
image_exists=$(docker images | grep "doxygen_perlmod_python")

if [[ -z "$image_exists" ]]; then
    echo "taf_create_docker.sh: not exist doxygen_perlmod_python image"
    docker run --name base_of_python3_and_pip3 -v `pwd`:/docker_in -v `pwd`:/docker_out -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out vaeum/alpine-python3-pip3 bash /docker_in/taf_install_in_docker.sh
    docker commit base_of_python3_and_pip3 doxygen_perlmod_python:latest
else
    echo "taf_create_docker.sh: exist doxygen_perlmod_python image"
fi

docker images

image_exists=$(docker images | grep "doxygen_perlmod_python")
if [[ -z "$image_exists" ]]; then
    echo "error: fail again. taf_create_docker.sh:we can not run with doxygen_perlmod_python:latest image."
else
    echo "taf_create_docker.sh: we will run hpp2plantuml and mako"
fi

# docker iamge (doxygen_perlmod_python:latest) is created from docker image(vaeum/alpine-python3-pip3) with taf_install.sh
# docker run --user `id -u`:`id -g`  -v  `pwd`:/docker_in -v `pwd`/op:/docker_out -e DOCKER_IN=/docker_in -e DOCKER_OUT=/docker_out -e DOCKER_GIT=/docker_in doxygen_perlmod_python:latest  bash /docker_in/taf_run.sh
