#ifndef CORE_PARSE_LIB_FILE_MANAGMENT_H
#define CORE_PARSE_LIB_FILE_MANAGMENT_H
#include "../common.h"
#include "../string_utils_module/string_utils.h"
static const char confing_path[BUFFER] = "../config/";

//creating file procedure
void create_file(char*);

//Auxillary function for creating the connection to file
//returns a pointer for following functions
FILE* file_connection(char*, const char*);

//check the existance of file
//uses the function "file_connection"
bool exist_check(char*);

void data_creation_procedure(char*);

void config_setting_procedure(void);
#endif //CORE_PARSE_LIB_FILE_MANAGMENT_H
