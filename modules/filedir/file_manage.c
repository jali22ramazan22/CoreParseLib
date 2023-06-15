#include "file_manage.h"

void create_file(char* filename, char* root_catalogue){
    char* filepath = concatenateStr(root_catalogue, filename);
    FILE* file_pointer = fopen(filepath, "w");
    if(file_pointer != NULL){
        fclose(file_pointer);
        free(filepath);
        return;
    }
    fclose(file_pointer);
    printf("File created successfully\n");
    free(filepath);
}

void create_dir(char* dirname, char* root_catalogue){
    char* dir_path = concatenateStr(root_catalogue, dirname);
    int status = mkdir(dir_path, 0700);

    if (status == 0){
        printf("Directory created successfully\n");
    }
    else{
        printf("Failed to create directory\n");
    }

    free(dir_path);
}

char* create_DATA_dir(){
    char* standart = (char*)malloc(sizeof(char)*10);
    copy("../TestingDirectory/data", standart);
    create_dir("data", "../TestingDirectory/");
    return standart;
}

void config_creation(void){
    create_dir("config", "../TestingDirectory/");
    create_file("settings.txt", "../TestingDirectory/config/");
    FILE* file_pointer = fopen("../TestingDirectory/config/settings.txt", "a+");
    if(file_pointer == NULL){
        return;
    }
    char* data;
    fputs((data = create_DATA_dir()), file_pointer);
    fclose(file_pointer);
    free(data);
}

bool is_exist(char* filename, char* root_catalogue){
    char* filepath = concatenateStr(root_catalogue, filename);
    FILE* file_pointer = fopen(filepath, "r");
    if(file_pointer == NULL)
        return false;
    return true;
}

FILE* openFile(char* filename, char* root_catalogue, char* mode){
    char* filepath = concatenateStr(root_catalogue, filename);
    FILE* file_pointer = fopen(filepath, mode);
    if(file_pointer == NULL)
        return NULL;
    free(filepath);
    return file_pointer;
}