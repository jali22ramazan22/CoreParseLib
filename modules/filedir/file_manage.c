#include "file_manage.h"

void create_file(char* filename, char* root_catalogue){
    char filepath[BUFFER];
    sprintf(filepath, "%s%s", root_catalogue, filename);
    FILE* file_pointer = fopen(filepath, "w");
    if(file_pointer != NULL){
        fclose(file_pointer);

        return;
    }
    fclose(file_pointer);
    printf("File created successfully\n");
}

void create_dir(char* dirname, char* root_catalogue){
    char dir_path[BUFFER];
    sprintf(dir_path, "%s%s", root_catalogue, dirname);

    int status = mkdir(dir_path, 0700);

    if (status == 0){
        printf("Directory created successfully\n");
    }
    else{
        printf("Failed to create directory\n");
    }

}

char* get_file_path(FILE* file_pointer){
    return NULL;
}

FILE* openFile(char* filename, char* root_catalogue, char* mode){
    char filepath[BUFFER];
    sprintf(filepath, "%s%s", root_catalogue, filename);
    FILE* file_pointer = fopen(filepath, mode);
    if(file_pointer == NULL)
        return NULL;
    return file_pointer;
}


bool is_directory_exist(const char* dirname, const char* root_catalogue){
    char dir_path[BUFFER];
    sprintf(dir_path, "%s%s", root_catalogue, dirname);
    DIR* dir = opendir(dir_path);
    if (!dir){
        return false;
    }
    closedir(dir);
    return true;

}
bool is_exist(char* filename, char* root_catalogue){ //FILE
    char filepath[BUFFER];
    sprintf(filepath, "%s%s", root_catalogue, filename);
    FILE* file_pointer = fopen(filepath, "r");
    if(file_pointer == NULL)
        return false;
    return true;
}



bool check_data_dir(){
    if(!is_directory_exist(DATA_DIR_NAME, MEDIA_PATH)){
        printf("Directory %s does not exist\n", DATA_DIR);
        return false;
    }
    return true;
}

void create_data_dir(){
    if(check_data_dir())
        return;
    create_dir("data", MEDIA_PATH);
}

