cmake_minimum_required(VERSION 3.17)
project(ToolReception)

set(CMAKE_CXX_STANDARD 17)

add_executable(ToolReception main.cpp)
target_include_directories(ToolReception PUBLIC lib/cinatra/include /Users/sunbo/Downloads/FrameWork/boost_1_73_0)