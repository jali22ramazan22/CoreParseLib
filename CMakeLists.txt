cmake_minimum_required(VERSION 3.25)
project(CoreParseLib C)

set(CMAKE_C_STANDARD 11)

add_executable(CoreParseLib debug.c
        modules/filedir/file_manage.c
        modules/filedir/file_manage.h
        modules/common.h
        modules/stringUtils/stringUtils.c coreparselib.h modules/filedir/file_procedures_func.c modules/filedir/file_procedures_func.h modules/jsonParse/jsonInsiders.c modules/jsonParse/jsonInsiders.h modules/jsonParse/jsonUtils.c modules/jsonParse/jsonUtils.h)

find_package(json-c CONFIG)
target_link_libraries(${PROJECT_NAME} PRIVATE json-c::json-c)