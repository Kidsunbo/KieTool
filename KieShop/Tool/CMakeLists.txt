cmake_minimum_required(VERSION 3.16)
project(Tool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_subdirectory(lib)

find_library(THRIFT NAMES libthrift.a HINTS /usr/local/lib)
aux_source_directory(gen-cpp thrift-gen)
aux_source_directory(handler handler)
aux_source_directory(dto dto)
aux_source_directory(util util)


add_executable(Tool main.cpp ${thrift-gen} ${handler} ${dto} ${util})
target_include_directories(Tool PUBLIC /usr/local/include /Users/sunbo/Downloads/FrameWork/boost_1_73_0 lib/spdlog/include)
target_link_libraries(Tool PUBLIC ${THRIFT} libssl.a libcrypto.a libc.a libdl.a -static-libgcc -static-libstdc++ libpthread.a)
install(TARGETS Tool DESTINATION /root/bin/Tool)