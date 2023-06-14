cmake_minimum_required(VERSION 3.22.1)
project(CORE_PARSE_LIB C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(lib/json-c)
set(
        coreparselib.h
        src/file_dir_module/file_management.h
        src/file_dir_module/dir_management.h
        src/string_utils_module/string_utils.h
        src/common.h
        src/parsing_json_module/json-manipulation.h
)
add_library(CORE_PARSE_LIB STATIC
    src/file_dir_module/file_management.c
    src/file_dir_module/dir_management.c
    src/string_utils_module/string_utils.c
    src/parsing_json_module/json-manipulation.h src/parsing_json_module/json-manipulation.c coreparselib.h)
target_link_libraries(CORE_PARSE_LIB PRIVATE json-c)

