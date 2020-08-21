cmake_minimum_required(VERSION 3.16)
project(ToolReception)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

find_library(THRIFT_LIB NAMES thrift HINTS /usr/local/lib)

aux_source_directory(gen-cpp THRIFT)
aux_source_directory(handler handler)
aux_source_directory(client client)

add_executable(ToolReception main.cpp ${client} ${handler} ${THRIFT})
target_include_directories(ToolReception PUBLIC lib/cinatra/include
        lib/spdlog/include
        lib/nlohmann
        lib/fmt/include
        /Users/sunbo/Downloads/FrameWork/boost_1_73_0
        /usr/local/include)
target_link_libraries(ToolReception PUBLIC ${THRIFT_LIB} fmt)