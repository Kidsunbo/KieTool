cmake_minimum_required(VERSION 3.16)
project(KieShop_tool_cellar)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

aux_source_directory(gen-cpp thrift-gen)
aux_source_directory(handler handler)
aux_source_directory(defined defined)
aux_source_directory(database db)

find_library(THRIFT NAMES libthrift.a HINTS /usr/local/lib)
if(APPLE)
    find_library(MYSQL NAMES mysqlcppconn8-static HINTS lib/mysql_dev/lib64)
    find_library(SSL NAMES libssl.a HINTS /usr/local/Cellar/openssl@1.1/1.1.1g/lib)
    find_library(CRYPTO NAMES libcrypto.a HINTS /usr/local/Cellar/openssl@1.1/1.1.1g/lib)
elseif(UNIX AND NOT APPLE)
    find_library(MYSQL NAMES mysqlcppconn8-static HINTS lib/mysql_prod/lib64)
endif()

add_executable(KieShop_tool_cellar main.cpp ${thrift-gen} ${handler} ${defined} ${db})
if(APPLE)
target_include_directories(KieShop_tool_cellar PUBLIC
        /Users/sunbo/Downloads/FrameWork/boost_1_73_0
        /usr/local/include
        lib/KieToolCommon/utility # common utility
        lib/spdlog/include
        lib/mysql_dev/include
        )
target_link_libraries(KieShop_tool_cellar PUBLIC ${MYSQL} ${SSL} ${CRYPTO} resolv ${THRIFT} pthread)
elseif(UNIX AND NOT APPLE)
    target_include_directories(KieShop_tool_cellar PUBLIC
            /usr/local/include
            lib/KieToolCommon/utility # common utility
            lib/spdlog/include
            lib/mysql_prod/include
            )
    target_link_libraries(KieShop_tool_cellar PUBLIC ${MYSQL} libssl.a libcrypto.a dl resolv ${THRIFT} pthread)
endif()

install(TARGETS KieShop_tool_cellar DESTINATION /root/bin/Tool)