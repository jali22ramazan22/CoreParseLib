

#ifndef COREPARSELIB_FILE_MANAGE_H
#define COREPARSELIB_FILE_MANAGE_H
#include "../common.h"
#include "../stringUtils/stringUtils.h"

//basic functions

void create_file(char* filename, char* root_catalogue);
void create_dir(char* dirname, char* root_catalogue);
bool is_exist(char* filename, char* root_catalogue);
FILE* openFile(char* filename, char* root_catalogue, char* mode);

//program functions/procedures

char* create_DATA_dir();

void config_creation(void);


#endif //COREPARSELIB_FILE_MANAGE_H
