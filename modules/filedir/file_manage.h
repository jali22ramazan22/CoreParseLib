

#ifndef COREPARSELIB_FILE_MANAGE_H
#define COREPARSELIB_FILE_MANAGE_H
#include "../common.h"
#include "../stringUtils/stringUtils.h"
#define MEDIA_PATH "../TestingDirectory/"
#define DATA_DIR_NAME "data/"

#define DATA_DIR MEDIA_PATH DATA_DIR_NAME

//basic functions/

void create_file(char* filename, char* root_catalogue);
void create_dir(char* dirname, char* root_catalogue);
bool is_exist(char* filename, char* root_catalogue);
FILE* openFile(char* filename, char* root_catalogue, char* mode);
bool is_directory_exist(const char* dirname, const char* root_catalogue);
bool check_data_dir();
//program functions/procedures

char* create_DATA_dir();

void config_creation(void);


#endif //COREPARSELIB_FILE_MANAGE_H
