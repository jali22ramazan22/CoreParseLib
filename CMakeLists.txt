cmake_minimum_required(VERSION 3.22.1)
project(CORE_PARSE_LIB C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib/json-c)
set(
        coreparselib.h
        src/file_management.h
        src/dir_management.h
        src/string_utils.h
        src/common.h
)
add_library(CORE_PARSE_LIB STATIC
    src/file_management.c
    src/dir_management.c
    src/string_utils.c
)
target_link_libraries(CORE_PARSE_LIB PRIVATE json-c)

