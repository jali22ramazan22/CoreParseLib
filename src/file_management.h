#ifndef TO_DO_LIST_FILE_MANAGMENT_H
#define TO_DO_LIST_FILE_MANAGMENT_H
#define BUFFER 1024
#include "common.h"

extern char root_const[BUFFER];
FILE* pointer_connection(char* file_name, char* mode);

void S_concatenate_str(char*, const char*);
char* D_concatenate_str(const char*, const char*);

void check_file(char*);
void add_file(char*);
void read_file(char*);
#endif //TO_DO_LIST_FILE_MANAGMENT_H
