cmake_minimum_required(VERSION 3.22.1)
project(CORE_PARSE_LIB C)

set(CMAKE_C_STANDARD 11)


include_directories(lib/json-c-build)


add_library(CORE_PARSE_LIB STATIC
    src/coreparselib.h
  src/common.h
  src/file_management.h
  src/file_management.c
)

add_executable(LibCore

  src/file_management.c
  src/core_string.c
  src/core_string.h
  src/file_management.h
  src/coreparselib.h
)

target_link_libraries(LibCore PRIVATE CORE_PARSE_LIB)
