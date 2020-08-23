FROM ubuntu:latest

RUN apt update &&DEBIAN_FRONTEND="noninteractive" apt-get -y install tzdata && apt install -y g++ cmake libboost-dev libthrift-0.13.0 git

WORKDIR /root/ToolReception

COPY . .

RUN git submodule update --init --recursive

WORKDIR /root/KieTool/KieShop/ToolReception

ENTRYPOINT ["sh"]

CMD ["build.sh"]