cmake_minimum_required(VERSION 3.16)
project(DB2ES)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(gen-cpp thrift_gen)
aux_source_directory(handler handler)

find_library(THRIFT NAMES thrift HINTS /usr/local/lib)

set(BOOST_DIR /Users/sunbo/Downloads/FrameWork/boost_1_73_0 cache string "Boost path" )

add_executable(DB2ES main.cpp handler.cpp ${thrift_gen} ${handler})
target_include_directories(DB2ES PUBLIC /usr/local/include ${BOOST_DIR} include)
target_link_libraries(DB2ES PUBLIC ${THRIFT})

add_executable(client testclient.cpp ${thrift_gen})
target_include_directories(client PUBLIC /usr/local/include ${BOOST_DIR} include)
target_link_libraries(client PUBLIC ${THRIFT})