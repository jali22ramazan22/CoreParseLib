#include "file_management.h"


FILE* pointer_connection(char* file_name, char* mode){
    FILE *fp; 
    if((fp = fopen(file_name, mode)) == NULL){
        printf("Error: cannot open the file");
        return NULL;
    }
    return fp;
}

void check_file(char* file_name){
    char* file_root = D_concatenate_str(root_const, file_name);
    FILE* fp = pointer_connection(file_root, "r");
    if(fp == NULL)
        return;
    fclose(fp);
}

void add_file(char* file_name){
    
    char* file_root = D_concatenate_str(root_const, file_name);
    FILE *fp = pointer_connection(file_root, "a");
    if(fp == NULL)
        return;
    fclose(fp);
}

void read_file(char* file_name){
    char* file_root = D_concatenate_str(root_const, file_name);
    FILE *fp = pointer_connection(file_root, "r");
    if (fp == NULL) {
        return;
    }
    
    char _display_buffer_[BUFFER];
    while (fgets(_display_buffer_, BUFFER, fp) != NULL) {
        printf("%s", _display_buffer_);
    }
    
    fclose(fp);
}
