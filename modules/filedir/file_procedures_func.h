#ifndef COREPARSELIB_FILE_PROCEDURES_FUNC_H
#define COREPARSELIB_FILE_PROCEDURES_FUNC_H
#include "../common.h"
#include "file_manage.h"
void create_file(char* filename, char* originDir, char* subdirectory_name);

void create_dir(char* dirname, char* originDir, char* subdirectory_name);

bool is_obj_exist(char* filename, char* originDir);

void config_creation(char* originDir);

void data_dir_creation(char* originDir);


#endif //COREPARSELIB_FILE_PROCEDURES_FUNC_H
