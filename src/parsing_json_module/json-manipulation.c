#include "json-manipulation.h"

void write_a_note(note* NOTE_PTR){
    char text[BUFFER];
    char title[BUFFER];
    if(NOTE_PTR == NULL){
        NOTE_PTR = (note*)malloc(sizeof(note)*1);
        NOTE_PTR->created_at = date_to_str(return_time());
        scanf("%s", text);

        scanf("%s", title);
    }

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


char* date_to_str(const date creation_data){
    char* created_at;
    char buffer[BUFFER];
    snprintf(buffer, BUFFER, "%d.%d.%d", creation_data.day, creation_data.month, creation_data.year);
    created_at = static_to_dynamic_copy(buffer);
    return created_at;
}