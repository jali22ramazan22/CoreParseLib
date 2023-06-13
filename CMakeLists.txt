cmake_minimum_required(VERSION 3.22.1)
project(CORE_PARSE_LIB C)

set(CMAKE_C_STANDARD 11)

include_directories(lib/json-c-build)

add_library(CORE_PARSE_LIB STATIC
    coreparselib.h
    src/common.h
    src/file_management.h
    src/file_management.c
    src/string_utils.h
    src/string_utils.c
)

