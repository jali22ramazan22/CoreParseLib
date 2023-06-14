#include "../string_utils_module/string_utils.h"
#include "file_management.h"
#include "dir_management.h"
FILE* file_connection(char* filename, const char* mode){
    S_concatenate_str(root_const, filename);
    FILE* fp = fopen(filename, mode);
    return fp;
}

bool exist_check(char* filename) {
    FILE* fp = file_connection(filename, "r");
    if (fp == NULL) {
        return false;
    }
    fclose(fp);
    return true;
}

void create_file(char* filename) {
    FILE* fp = file_connection(filename, "w");
    fclose(fp);
}

void data_creation_procedure(char* filename){
    if (exist_check(filename)){
        printf("Error: THE FILE ALREADY EXISTS");
    }
    else{
        create_file(filename);
    }
}

void config_setting_procedure(void){
    create_directory_procedure(confing_path);
    data_creation_procedure("settings.txt");
}