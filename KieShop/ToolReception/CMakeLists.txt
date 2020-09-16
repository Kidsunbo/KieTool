cmake_minimum_required(VERSION 3.16)
project(KieShop_tool_reception)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")


add_subdirectory(lib)

find_library(THRIFT_LIB NAMES libthrift.a HINTS /usr/local/lib)

aux_source_directory(gen-cpp THRIFT)
aux_source_directory(handler handler)
aux_source_directory(client client)
aux_source_directory(util helper)
aux_source_directory(dto online)

add_executable(KieShop_tool_reception main.cpp ${client} ${handler} ${THRIFT} ${helper} ${online})
target_include_directories(kieShop_tool_reception PUBLIC lib/cinatra/include
        lib/spdlog/include
        lib/nlohmann
        lib/fmt/include
        /Users/sunbo/Downloads/FrameWork/boost_1_73_0
        /usr/local/include)
target_link_libraries(KieShop_tool_reception PUBLIC ${THRIFT_LIB} fmt pthread)

install(TARGETS KieShop_tool_reception DESTINATION /root/bin/Tool)

#add_executable(test test.cpp ${helper})