FROM ubuntu:latest

RUN apt update && DEBIAN_FRONTEND="noninteractive" apt-get -y install tzdata && apt install -y g++ cmake libboost-dev libthrift-0.13.0 git

WORKDIR /root

RUN git clone https://github.com/Kidsunbo/KieTool.git && cd KieTool/KieShop/Tool && git submodule update --init --recursive

WORKDIR /root/KieTool/KieShop/Tool

ENTRYPOINT ["bash"]

#CMD ["build.sh"]
