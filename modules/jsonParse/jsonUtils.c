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

    return note_object;
}


void destruct_note_object(note* note_object) {
    free(note_object->this_title);
    free(note_object->this_text);
    free(note_object->this_createdAt);

    free(note_object);
}

size_t get_notes_count(FILE* file_pointer){
    char p_str[BUFFER];
    fread(p_str, BUFFER, 1, file_pointer);
    struct json_object* parsed_json;
    struct json_object* array;
    parsed_json = json_tokener_parse(p_str);
    json_object_object_get_ex(parsed_json, "notes", &array);
    return getArraySize(array);
}


note** get_all_notes(FILE* file_pointer) {
    note** notes_arr = NULL; //array of notes init
    note* note_temp_pt = NULL;

    char p_str[BUFFER];
    fread(p_str, BUFFER, 1, file_pointer); //reading json file


    struct json_object* parsed_json;
    struct json_object* array;
    struct json_object* note_object;

    struct json_object* title_obj;
    struct json_object* text_obj;
    struct json_object* createdAt_obj;

    parsed_json = json_tokener_parse(p_str);
    json_object_object_get_ex(parsed_json, "notes", &array); //notes array init

    size_t len = json_object_array_length(array); //getting the size of array
    notes_arr = malloc((len+1) * sizeof(note*)); //dynamic allocation of array of notes

    for (size_t i = 0; i < len; ++i) {
        note_object = json_object_array_get_idx(array, i); //getting every note

        //transformation note_object to a combination of separate strings
        json_object_object_get_ex(note_object, "title", &title_obj);
        json_object_object_get_ex(note_object, "text", &text_obj);
        json_object_object_get_ex(note_object, "createdAt", &createdAt_obj);

        const char* title = json_object_get_string(title_obj);
        const char* text = json_object_get_string(text_obj);
        const char* createdAt = json_object_get_string(createdAt_obj);

        //assignment procedures
        note_temp_pt = create_note_object(title, text, createdAt);
        notes_arr[i] = note_temp_pt;
    }
    notes_arr[len] = NULL;
    return notes_arr;
}

void notes_array_destructor(note** notes_arr){
    for(int i = 0; notes_arr[i] != NULL; ++i){
        destruct_note_object(notes_arr[i]);
        //avoiding double-deletion of mem-space
        if(notes_arr[i] == NULL){
            break;
        }
    }
}
