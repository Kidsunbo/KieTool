cmake_minimum_required(VERSION 3.16)
project(KieShop_tool_cellar)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

aux_source_directory(gen-cpp thrift-gen)
aux_source_directory(handler handler)
aux_source_directory(defined defined)

find_library(THRIFT NAMES libthrift.a HINTS /usr/local/lib)


add_executable(KieShop_tool_cellar main.cpp ${thrift-gen} ${handler} ${defined})
target_include_directories(KieShop_tool_cellar PUBLIC
        /Users/sunbo/Downloads/FrameWork/boost_1_73_0
        /usr/local/include
        ../ToolCommon/utility # common utility
        lib/spdlog/include
        )
target_link_libraries(KieShop_tool_cellar PUBLIC ${THRIFT} pthread)
install(TARGETS KieShop_tool_cellar DESTINATION /root/bin/Tool)