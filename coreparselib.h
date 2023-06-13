#ifndef CORE_PARSE_LIB_CORE_PARSE_LIB_H
#define CORE_PARSE_LIB_CORE_PARSE_LIB_H
#include "src/file_management.h"
#include "src/common.h"
#include "src/core_string.h"
extern bool exist_check(char* filename);
extern void data_creation_procedure(char* filename);
extern FILE* file_connection(char* filename, const char* mode);
#endif //CORE_PARSE_LIB_CORE_PARSE_LIB_H
