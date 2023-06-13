#ifndef CORE_PARSE_LIB_FILE_MANAGMENT_H
#define CORE_PARSE_LIB_FILE_MANAGMENT_H
#include "common.h"

extern char root_const[BUFFER];
FILE* pointer_connection(char* file_name, char* mode);

void S_concatenate_str(char*, const char*);
char* D_concatenate_str(const char*, const char*);

void check_file(char*);
void add_file(char*);
void read_file(char*);
#endif //CORE_PARSE_LIB_FILE_MANAGMENT_H
