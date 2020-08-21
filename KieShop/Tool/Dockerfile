FROM ubuntu:latest

RUN DEBIAN_FRONTEND="noninteractive" apt-get -y install tzdata

RUN apt update && apt install -y g++ cmake libboost-dev libthrift-0.13.0 git

WORKDIR /root

RUN git clone https://github.com/Kidsunbo/KieTool.git && cd KieTool/KieShop/Tool && git submodule update --init --recursive

WORKDIR /root/KieTool/KieShop/Tool

ENTRYPOINT ["sh"]

CMD ["build.sh"]