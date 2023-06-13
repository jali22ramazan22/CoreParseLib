#ifndef CORE_PARSE_LIB_FILE_MANAGMENT_H
#define CORE_PARSE_LIB_FILE_MANAGMENT_H
#include "common.h"
#include "core_string.h"

char root_const[BUFFER] = "data/";
void create_file(char*);
FILE* file_connection(char*, const char*);
bool exist_check(char*);

void data_creation_procedure();
#endif //CORE_PARSE_LIB_FILE_MANAGMENT_H
