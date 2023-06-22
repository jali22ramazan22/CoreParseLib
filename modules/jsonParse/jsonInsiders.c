#include "jsonInsiders.h"

void write_note(note* finite_note, char* filename, char* originDir, char* subdirectory){
    if(subdirectory == NULL){
        subdirectory = "data";
    }
    if(finite_note == NULL)
        return;

    create_file(filename, originDir, subdirectory);
    char* filepath = get_obj_path(filename, originDir);
    FILE* fp = fopen(filepath, "w");

    struct json_object* obj = json_object_new_object();
    struct json_object* note_object = new_JSON_note_object(finite_note);
    write_object_info_in_config(finite_note, filepath, originDir, &get_append_JSON_note_info);
    json_object_object_add(obj, "note", note_object);

    const char* json_input = json_object_to_json_string_ext(obj, JSON_C_TO_STRING_PRETTY);
    fprintf(fp, "%s", json_input);

    destruct_note_structure(finite_note);
    fclose(fp);

}


void write_task(task* finite_task, char* filename, char* originDir, char* subdirectory){
    if(subdirectory == NULL){
        subdirectory = "data";
    }
    if(finite_task == NULL)
        return;

    create_file(filename, originDir, subdirectory);
    char* filepath = get_obj_path(filename, originDir);
    FILE* fp = fopen(filepath, "w");

    struct json_object* obj = json_object_new_object();
    struct json_object* task_object = new_JSON_task_object(finite_task);

    json_object_object_add(obj, "task", task_object);

    const char* json_input = json_object_to_json_string_ext(obj, JSON_C_TO_STRING_PRETTY);
    fprintf(fp, "%s", json_input);
    write_object_info_in_config(finite_task, filepath, originDir, &get_append_JSON_task_info);

    destruct_task_structure(finite_task);
    fclose(fp);
}

void write_object_info_in_config(void* object, char* filepath, char* originDir, void(*get_append_JSON_object_info)(void* object,
        char* filepath, char* buffer, FILE* file_config_pointer)){
    FILE* file_config_pointer;
    if(!is_obj_exist("config.json", originDir))
        config_creation(originDir);

    char* config_path = get_obj_path("config.json", originDir);
    file_config_pointer = fopen(config_path, "r+");
    if(file_config_pointer == NULL){
        printf("Error: config does not exist.\n"
               "Created instead.");
        return;
    }

    fseek(file_config_pointer, 0, SEEK_END);
    long file_size = ftell(file_config_pointer);
    char* buffer = malloc(sizeof(char)*(file_size + 1));
    if(buffer == NULL){
        fclose(file_config_pointer);
        return;
    }
    fseek(file_config_pointer, 0, SEEK_SET);
    fread(buffer, 1, file_size, file_config_pointer);
    if (ferror(file_config_pointer)) {
        printf("Error:");
        fclose(file_config_pointer);
        free(buffer);
        return;
    }

    get_append_JSON_object_info(object, filepath,buffer, file_config_pointer);
    free(filepath);
    fclose(file_config_pointer);
}