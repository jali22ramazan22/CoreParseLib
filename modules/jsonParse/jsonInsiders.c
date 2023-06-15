#include "jsonInsiders.h"


void write_a_note(note* NOTE_PTR, FILE* file_pointer){
    char str_title[BUFFER] = "Untitled2";
    char str_text[BUFFER] = "Custom text for checking it out";

    if (NOTE_PTR == NULL){
        NOTE_PTR = (note*)malloc(sizeof(note) * 1);
        NOTE_PTR->createdAt = date_to_str(return_time());

        str_title[strcspn(str_title, "\n")] = '\0';
        str_text[strcspn(str_text, "\n")] = '\0';

        NOTE_PTR->title = static_to_dynamic_copy(str_title);
        NOTE_PTR->text = static_to_dynamic_copy(str_text);
    }

    if (file_pointer == NULL){
        printf("Do you really want to create a file? [Y/n]");
        char answer;
        scanf(" %c", &answer);

        if(tolower(answer) == 'n')
            return;
        char filename[BUFFER];

        create_file("sample2.json", "../TestingDirectory/");
        file_pointer = openFile("sample2.json", "../TestingDirectory/", "a");
    }

    struct json_object* JSON_note = json_object_new_object();
    struct json_object* JSON_title = json_object_new_string(NOTE_PTR->title);
    struct json_object* JSON_text = json_object_new_string(NOTE_PTR->text);
    struct json_object* JSON_creation_date = json_object_new_string(NOTE_PTR->createdAt);

    json_object_object_add(JSON_note, "title", JSON_title);
    json_object_object_add(JSON_note, "text", JSON_text);
    json_object_object_add(JSON_note, "created_at", JSON_creation_date);

    fprintf(file_pointer, "%s\n", json_object_to_json_string_ext(JSON_note, JSON_C_TO_STRING_PRETTY));
    fclose(file_pointer);
    json_object_put(JSON_note);
    free(NOTE_PTR);
}

void create_notion_list(char* filename){
    if(filename == NULL){
        char* filename = "notion.json";
    }
    create_file(filename, DATA_DIR);
    FILE* file_pointer = openFile(filename, DATA_DIR, "a+");
    struct json_object* object = json_object_new_object();
    struct json_object* id_note = json_object_new_array();
    
    fclose(file_pointer);
}

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