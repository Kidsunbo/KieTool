cmake_minimum_required(VERSION 3.16)
project(KieShop_tool_logistic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_subdirectory(lib)

find_library(THRIFT NAMES libthrift.a HINTS /usr/local/lib)
aux_source_directory(gen-cpp thrift-gen)
aux_source_directory(handler handler)
aux_source_directory(dto dto)
aux_source_directory(defined constant)

add_executable(KieShop_tool_logistic main.cpp ${thrift-gen} ${handler} ${dto} ${util} ${constant})
target_include_directories(KieShop_tool_logistic PUBLIC /usr/local/include
        /Users/sunbo/Downloads/FrameWork/boost_1_73_0
        ../ToolCommon/utility # common utility
        lib/spdlog/include)
target_link_libraries(KieShop_tool_logistic PUBLIC ${THRIFT} pthread)
install(TARGETS KieShop_tool_logistic DESTINATION /root/bin/Tool)

#add_executable(test test.cpp ${thrift-gen} ${handler} ${dto} ${util} ${constant})
#target_include_directories(test PUBLIC /usr/local/include
#        /Users/sunbo/Downloads/FrameWork/boost_1_73_0
#        lib/spdlog/include)
#target_link_libraries(test PUBLIC ${THRIFT} pthread)