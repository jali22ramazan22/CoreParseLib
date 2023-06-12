cmake_minimum_required(VERSION 3.22.1)
project(Core C)

set(CMAKE_C_STANDARD 11)

add_library(Core SHARED src/main.c src/main.h src/common.h src/file_management.h src/file_management.c)

add_executable(LibCore src/main.c src/file_management.c)