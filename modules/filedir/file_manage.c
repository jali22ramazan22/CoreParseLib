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

char* create_DATA_dir(){
    //MEDIAPATH + data
    char DATA_PATH[BUFFER];
    sprintf(DATA_PATH, "%s%s", MEDIA_PATH, "data/");

    char* saving_path = (char*)malloc(sizeof(char)*10);
    copy(DATA_PATH, saving_path);

    create_dir("data", MEDIA_PATH);
    return saving_path;
}

void config_creation(void){
    //MEDIA_PATH + config/ + settings.txt
    create_dir("config", MEDIA_PATH);
    char CONFIG_PATH[BUFFER];
    sprintf(CONFIG_PATH, "%s%s", MEDIA_PATH, "config/");
    create_file("settings.txt", CONFIG_PATH);
    sprintf(CONFIG_PATH, "%s%s", CONFIG_PATH, "settings.txt");

    FILE* file_pointer = fopen(CONFIG_PATH, "a+");
    if(file_pointer == NULL){
        return;
    }
    char* data;
    fputs((data = create_DATA_dir()), file_pointer);
    fclose(file_pointer);
    free(data);
}

bool is_exist(char* filename, char* root_catalogue){
    char filepath[BUFFER];
    sprintf(filepath, "%s%s", root_catalogue, filename);
    FILE* file_pointer = fopen(filepath, "r");
    if(file_pointer == NULL)
        return false;
    return true;
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

bool check_data_dir(){
    if(!is_directory_exist(DATA_DIR_NAME, MEDIA_PATH)){
        printf("Directory %s does not exist\n", DATA_DIR);
        return false;
    }
    return true;
}