FROM ubuntu:latest

RUN apt update && DEBIAN_FRONTEND="noninteractive" apt-get -y install tzdata && apt install -y g++ cmake libboost-dev libthrift-0.13.0 git && mkdir Tool

WORKDIR /root/Tool

COPY . .

RUN git submodule update --init --recursive

WORKDIR /root/KieTool/KieShop/Tool

ENTRYPOINT ["sh"]

CMD ["build.sh"]