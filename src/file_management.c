#include "file_management.h"

//Auxillary function for creating the connection to file
//returns a pointer for following functions
FILE* file_connection(char* filename, const char* mode){
    S_concatenate_str(root_const, filename);
    FILE* fp = fopen(filename, mode);
    return fp;
}
//check the existance of file
//uses the function "file_connection"
bool exist_check(char* filename) {
    FILE* fp = file_connection(filename, "r");
    if (fp == NULL) {
        return false;
    }
    fclose(fp);
    return true;
}
//creating file procedure
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

