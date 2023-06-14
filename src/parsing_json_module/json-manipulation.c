#include "json-manipulation.h"

void write_a_note(note* NOTE_PTR){
    char str_text[BUFFER];
    char str_title[BUFFER];
    if(NOTE_PTR == NULL){
        NOTE_PTR = (note*)malloc(sizeof(note)*1);
        NOTE_PTR->created_at = date_to_str(return_time());
        scanf("%s", str_text);
        scanf("%s", str_title);
        NOTE_PTR->title = static_to_dynamic_copy(str_title);
        NOTE_PTR->text = static_to_dynamic_copy(str_text);
    }
    /*
    struct json_object* JSON_note = json_object_new_object();
    struct json_object* JSON_title = json_object_new_string(NOTE_PTR->title);
    struct json_object* JSON_text = json_object_new_string(NOTE_PTR->text);
    struct json_object* JSON_creation_date = json_object_new_string(NOTE_PTR->created_at);


    data_creation_procedure("notes.json");
    */
}

date return_time(void){
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    date creation_data;
    
    creation_data.year = localTime->tm_year;
    creation_data.month = localTime->tm_mon;
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