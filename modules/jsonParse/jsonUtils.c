#include "jsonUtils.h"

date return_time(void){
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    date creation_data;

    creation_data.year = localTime->tm_year + 1900;
    creation_data.month = localTime->tm_mon + 1;
    creation_data.day = localTime->tm_mday;
    return creation_data;
}

char* date_to_str(date creation_data){
    char* created_at;
    char buffer[BUFFER];
    snprintf(buffer, BUFFER, "%d.%d.%d", creation_data.day, creation_data.month, creation_data.year);
    created_at = static_to_dynamic_copy(buffer);
    return created_at;
}


note* create_note_structure(const char* title, const char* text, const char* createdAt){
    note* note_object; char date_time_str[BUFFER];
    note_object = malloc(sizeof(note));
    note_object->this_title = static_to_dynamic_copy(title);
    note_object->this_text  = static_to_dynamic_copy(text);
    note_object->this_createdAt = static_to_dynamic_copy(createdAt);
    note_object->id = static_to_dynamic_copy(unique_object_id_generator());
    return note_object;
}



task* create_task_structure(const char* text, const char* createdAt, const char* mustFinished){
    task* task_object; char date_time_str[BUFFER];
    task_object = malloc(sizeof(note));
    task_object->this_text = static_to_dynamic_copy(text);
    task_object->this_created_at = static_to_dynamic_copy((createdAt));
    task_object->this_must_finished = static_to_dynamic_copy((mustFinished));
    task_object->id = static_to_dynamic_copy(unique_object_id_generator());
    return task_object;
}

void destruct_task_structure(task* task_object){
    free(task_object->this_text);
    free(task_object->this_created_at);
    free(task_object->this_must_finished);
    free(task_object->id);
    free(task_object);
}

void destruct_note_structure(note* note_object) {
    free(note_object->this_title);
    free(note_object->this_text);
    free(note_object->this_createdAt);
    free(note_object->id);
    free(note_object);
}

struct json_object* new_JSON_note_object(note* finite_note){
    struct json_object* note_object = json_object_new_object();
    json_object_object_add(note_object, "title", json_object_new_string(finite_note->this_title));
    json_object_object_add(note_object, "text", json_object_new_string(finite_note->this_text));
    json_object_object_add(note_object, "createdAt", json_object_new_string(finite_note->this_createdAt));
    json_object_object_add(note_object, "id", json_object_new_string(finite_note->id));
    destruct_note_structure(finite_note);
    return note_object;
}



struct json_object* new_JSON_task_object(task* finite_task){
    struct json_object* task_object = json_object_new_object();
    json_object_object_add(task_object, "text", json_object_new_string(finite_task->this_text));
    json_object_object_add(task_object, "createdAt", json_object_new_string(finite_task->this_created_at));
    json_object_object_add(task_object, "mustFinished", json_object_new_string(finite_task->this_must_finished));
    json_object_object_add(task_object, "id", json_object_new_string(finite_task->id));
    destruct_task_structure(finite_task);
    return task_object;
}


char* unique_object_id_generator(void){
    //srand(time(NULL)); //preferable to put into main function to get every time another id
    char buffer[BUFFER]; //ALLOWED
    int random_int_part = rand() % 1000000;
    int random_str_part = rand() % 128;

    while(random_str_part > 90 || random_str_part < 65)
        random_str_part = rand() % 128;


    sprintf(buffer, "%d%c", random_int_part, random_str_part);
    char* note_id = static_to_dynamic_copy(buffer);
    return note_id;
}


void config_creation(void){
    create_dir("config", MEDIA_PATH);
    create_file("config.json", CONFIG_PATH);
}


