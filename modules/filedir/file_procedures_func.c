#include "file_procedures_func.h"
void create_file(char* filename, char* originDir, char* subdirectory_name){
    if(is_obj_exist(filename, originDir)){
        printf("Error: the file already exists\n");
        return;
    }
    char path[BUFFER];
    if(subdirectory_name != NULL){
        char* subdirectory_path = get_obj_path(subdirectory_name, originDir);
        sprintf(path, "%s/%s", subdirectory_path, filename);
        free(subdirectory_path);
    }
    else{
        sprintf(path, "%s/%s", originDir, filename);
    }
    FILE* file_ptr = fopen(path, "w");
    fclose(file_ptr);
}

void create_dir(char* dirname, char* originDir, char* subdirectory_name){
    if(is_obj_exist(dirname, originDir))
        return;
    char path[BUFFER];
    if(subdirectory_name != NULL){
        char* subdirectory_path = get_obj_path(subdirectory_name, originDir);
        sprintf(path, "%s/%s", subdirectory_path, dirname);
        free(subdirectory_path);
    }
    else {
        sprintf(path, "%s/%s", originDir, dirname);
    }
    mkdir(path, 0700);
}

bool is_obj_exist(char* object, char* originDir){
    char *path = get_obj_path(object, originDir);
    bool status = (bool) (path);
    free(path);
    return status;
}


void config_creation(char* originDir){
    create_dir("config", originDir, NULL);
    create_file("config.json", originDir, "config");
    char* filepath = get_obj_path("config.json", originDir);
    FILE* fp = fopen(filepath, "w");

    struct json_object *json_obj = json_object_new_object();

    struct json_object* notes_array = json_object_new_array();
    struct json_object* tasks_array = json_object_new_array();

    json_object_object_add(json_obj, "notes", notes_array);
    json_object_object_add(json_obj, "tasks", tasks_array);

    const char* json_file_input = json_object_to_json_string_ext(json_obj, JSON_C_TO_STRING_PRETTY);
    fprintf(fp, "%s", json_file_input);
    fclose(fp);
}

void data_dir_creation(char* originDir){
    create_dir("data", originDir, NULL);
}