FROM ubuntu:latest

RUN apt update && DEBIAN_FRONTEND="noninteractive" apt-get -y install tzdata && apt install -y g++ cmake libboost-dev git wget tar libssl-dev

#install thrift
RUN wget https://mirror.bit.edu.cn/apache/thrift/0.13.0/thrift-0.13.0.tar.gz && \
 tar -xf thrift-0.13.0.tar.gz && \
 cd thrift-0.13.0 && \
 ./configure && \
 make && \
 make install && \
 cd ..&& \
 rm -rf thrift-0.13.0 thrift-0.13.0.tar.gz

WORKDIR /root

RUN git clone https://github.com/Kidsunbo/KieTool.git && cd KieTool/KieShop/Tool && git submodule update --init --recursive

WORKDIR /root/KieTool/KieShop/Tool

ENTRYPOINT ["sh"]

CMD ["build.sh"]

FROM ubuntu:latest


