cmake_minimum_required(VERSION 3.22.1)
project(CoreParseLib C)

set(CMAKE_C_STANDARD 23
        debug.c)
add_executable(CoreParseLib debug.c
        modules/common.h
        modules/stringUtils/stringUtils.h
        modules/stringUtils/stringUtils.c
        modules/filedir/file_manage.h
        modules/filedir/file_manage.c
        modules/jsonParse/jsonInsiders.h
        modules/jsonParse/jsonInsiders.c
        modules/jsonParse/jsonUtils.h
        modules/jsonParse/jsonUtils.c )

find_package(json-c CONFIG)
target_link_libraries(${PROJECT_NAME} PRIVATE json-c::json-c)
