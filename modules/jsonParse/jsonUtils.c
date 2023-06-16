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


struct json_object* cpy_array(struct json_object* temp_array){
    struct json_object* new_arr = json_object_new_array();
    size_t lenArr = getArraySize(temp_array);

    int i = 0;
    struct json_object* temp_note_object;
    for(; i < lenArr; ++i){
        temp_note_object = json_object_array_get_idx(temp_array, i);
        json_object_array_add(new_arr, temp_note_object);
    }
    return new_arr;
}


note* create_note_object(const char* title, const char* text, const char* createdAt){
    note* note_object; char date_time_str[BUFFER];
    note_object = malloc(sizeof(note));
    note_object->this_title = static_to_dynamic_copy(title);
    note_object->this_text  = static_to_dynamic_copy(text);
    note_object->this_createdAt = static_to_dynamic_copy(createdAt);
    note_object->id = static_to_dynamic_copy(unique_note_id_generator());
    return note_object;
}


void destruct_note_object(note* note_object) {
    free(note_object->this_title);
    free(note_object->this_text);
    free(note_object->this_createdAt);
    free(note_object->id);
    free(note_object);
}

struct json_object* new_note_object(note* finite_note){
    struct json_object* note_object = json_object_new_object();
    json_object_object_add(note_object, "title", json_object_new_string(finite_note->this_title));
    json_object_object_add(note_object, "text", json_object_new_string(finite_note->this_text));
    json_object_object_add(note_object, "createdAt", json_object_new_string(finite_note->this_createdAt));
    json_object_object_add(note_object, "id", json_object_new_string(finite_note->id));
    destruct_note_object(finite_note);
    return note_object;
}


char* unique_note_id_generator(void){
    //srand(time(NULL)); //preferable to put into main function to get every time another id
    char buffer[BUFFER];
    int random_int_part = rand() % 1000000;
    int random_str_part = rand() % 128;

    while(random_str_part > 90 || random_str_part < 65)
        random_str_part = rand() % 128;


    sprintf(buffer, "%d%c", random_int_part, random_str_part);
    char* note_id = static_to_dynamic_copy(buffer);
    return note_id;
}
