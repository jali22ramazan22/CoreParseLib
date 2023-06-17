

#ifndef COREPARSELIB_FILE_MANAGE_H
#define COREPARSELIB_FILE_MANAGE_H
#include "../common.h"
#include "../stringUtils/stringUtils.h"
#define MEDIA_PATH "../TestingDirectory/"
#define DATA_DIR_NAME "data/"
#define CONFIG_DIR_NAME "config/"
#define CONFIG_PATH MEDIA_PATH CONFIG_DIR_NAME
#define DATA_DIR MEDIA_PATH DATA_DIR_NAME

//basic functions/

void create_file(char* filename, char* root_catalogue);

void create_dir(char* dirname, char* root_catalogue);


FILE* openFile(char* filename, char* root_catalogue, char* mode);

char* get_file_path(FILE* file_pointer);

//program functions/procedures
void create_data_dir();

bool is_directory_exist(const char* dirname, const char* root_catalogue);


bool is_exist(char* filename, char* root_catalogue);

bool check_data_dir();

#endif //COREPARSELIB_FILE_MANAGE_H
