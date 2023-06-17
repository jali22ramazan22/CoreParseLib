#include "jsonInsiders.h"

//ONE-FILE functionality: for ergonomic purposes; if you desire to store all of you note_obj in one file - the following
//functions for you

void ONEFILE_write_note(note* finite_note, char* filename) {
    FILE *file_pointer;

    if (!check_data_dir()){
        sleep(1);
        create_data_dir();
        filename = UNTITLED_NOTE;
        ONEFILE_create_notion_array(filename);
    }
    if(filename == NULL){
        filename = UNTITLED_NOTE;
        ONEFILE_create_notion_array(filename);
    }

    file_pointer = openFile(filename, DATA_DIR, "r+");

    fseek(file_pointer, 0, SEEK_END);
    long file_size = ftell(file_pointer);
    char* buffer = malloc(sizeof(char)*(file_size + 1));

    if(buffer == NULL){
        fclose(file_pointer);
        return;
    }
    fseek(file_pointer, 0, SEEK_SET);
    size_t read_size = fread(buffer, 1, file_size, file_pointer);
    if (ferror(file_pointer)) {
        printf("Error:");
        fclose(file_pointer);
        free(buffer);
        return;
    }
    struct json_object* parsed_json = json_tokener_parse(buffer);
    struct json_object* notes_array;
    if(json_object_object_get_ex(parsed_json, "notes", &notes_array)){
        struct json_object* note_object = new_JSON_note_object(finite_note);
        json_object_array_put_idx(notes_array, json_object_array_length(notes_array), note_object);
        fseek(file_pointer, 0, SEEK_SET);
        fprintf(file_pointer, "%s", json_object_to_json_string_ext(parsed_json, JSON_C_TO_STRING_PRETTY));
    }
    fclose(file_pointer);
    free(buffer);
    json_object_put(parsed_json);
}


void ONEFILE_create_notion_array(char* filename){
    if(filename == NULL)
        return;
    if(is_exist(filename, DATA_DIR))
        return;
    create_file(filename, DATA_DIR);
    FILE* file_pointer = openFile(filename, DATA_DIR, "a+");

    struct json_object* object = json_object_new_object();
    struct json_object* note_array = json_object_new_array();

    json_object_object_add(object, "notes", note_array);
    const char* json_str = json_object_to_json_string_ext(object, JSON_C_TO_STRING_PRETTY);
    fprintf(file_pointer, "%s", json_str);
    json_object_put(object);

    fclose(file_pointer);
}



note** ONEFILE_get_all_notes(FILE* file_pointer) {
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
        note_temp_pt = create_note_structure(title, text, createdAt);
        notes_arr[i] = note_temp_pt;
    }
    notes_arr[len] = NULL;
    return notes_arr;
}

size_t ONEFILE_get_notes_count(FILE* file_pointer){
    char p_str[BUFFER];
    fread(p_str, BUFFER, 1, file_pointer);
    struct json_object* parsed_json;
    struct json_object* array;
    parsed_json = json_tokener_parse(p_str);
    json_object_object_get_ex(parsed_json, "notes", &array);
    return json_object_array_length(array);
}


void notes_array_destructor(note** notes_arr){
    for(int i = 0; notes_arr[i] != NULL; ++i){
        destruct_note_structure(notes_arr[i]);
        //avoiding double-deletion of mem-space
        if(notes_arr[i] == NULL){
            break;
        }
    }
}

//MUL-FILE FUNCTIONALITY: if you want to create note_obj in separate files (Saving the notes always in separated files), the following
//functions for you



//existing file and rewriting note logic (rewrite current note)
//existing file and lack of note (nothing to do)
//non-existing file and note (create a file and write inside the note)
//non-existing file and lack of note (nothing to do)
void MULFILE_write_note(note* finite_note, char* filename){
    FILE* file_pointer;
    if(!check_data_dir())
        return;
    if(finite_note == NULL)
        return;
    if(filename == NULL){
        MULFILE_create_object_file(UNTITLED_NOTE);
        filename = UNTITLED_NOTE;
    }
    file_pointer = openFile(filename, DATA_DIR, "w+");

    struct json_object* json_file = json_object_new_object();
    struct json_object* note_object = new_JSON_note_object(finite_note);

    json_object_object_add(json_file, "note" ,note_object);

    const char* file_input = json_object_to_json_string_ext(json_file, JSON_C_TO_STRING_PRETTY);
    fputs(file_input, file_pointer);

    fclose(file_pointer);
}

void MULFILE_create_object_file(char* filename){
    if(filename == NULL)
        return;
    if(is_exist(filename, DATA_DIR))
        return;

    char* filepath[BUFFER];
    sprintf(filepath, "%s%s", MEDIA_PATH, DATA_DIR_NAME);
    create_file(filename, DATA_DIR);
}



void MULFILE_write_task(task* finite_task, char* filename){
    FILE* file_pointer;
    if(finite_task == NULL)
        return;
    if(filename == NULL){
        MULFILE_create_object_file(UNTITLED_TASK);
        filename = UNTITLED_TASK;
    }

    file_pointer = openFile(filename, DATA_DIR, "w+");

    struct json_object* json_file = json_object_new_object();
    struct json_object* task_object = new_JSON_task_object(finite_task);

    json_object_object_add(json_file, "task", task_object);

    const char* file_input = json_object_to_json_string_ext(json_file, JSON_C_TO_STRING_PRETTY);
    fputs(file_input, file_pointer);
    json_object_put(json_file);
    fclose(file_pointer);
}


