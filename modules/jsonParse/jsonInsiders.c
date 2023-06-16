#include "jsonInsiders.h"

//ONE-FILE functionality: for ergonomic purposes; if you desire to store all of you note_obj in one file - the following
//functions for you

void ONEFILE_write_note(note* finite_note, char* filename){
    FILE *file_pointer = NULL;

    if(!check_data_dir())
        return;

    if(filename == NULL){
        ONEFILE_create_notion_array(UNTITLED);
        filename = UNTITLED;
    }
    if(finite_note == NULL){
        return;
    }

    file_pointer = openFile(filename, DATA_DIR, "r");

    if(file_pointer == NULL){
        printf("The file does not exist\n");
        create_file(filename, DATA_DIR);
        file_pointer = openFile(filename, DATA_DIR, "r");
        printf("The file \"%s\" created in \"%s\" instead\n", filename, DATA_DIR);
    }
    struct json_object* parsed_json_file;
    struct json_object* temp_array;
    struct json_object* new_array;
    struct json_object* new_json_file;
    struct json_object* note_object;

    char buffer[BUFFER];
    fread(buffer, BUFFER, 1, file_pointer);
    parsed_json_file = json_tokener_parse(buffer);
    fclose(file_pointer);

    json_object_object_get_ex(parsed_json_file, "notes", &temp_array);
    new_array = cpy_array(temp_array);
    size_t len = getArraySize(new_array);

    note_object = new_note_object(finite_note);

    json_object_array_add(new_array, note_object);

    new_json_file = json_object_new_object();
    json_object_object_add(new_json_file, "notes", new_array);


    file_pointer = openFile(filename, DATA_DIR, "w+");

    const char* input_stream_JSON = json_object_to_json_string_ext(new_json_file, JSON_C_TO_STRING_PRETTY);
    fputs(input_stream_JSON, file_pointer);

    fclose(file_pointer);
}



size_t getArraySize(struct json_object *json_array) {
    if (json_object_is_type(json_array, json_type_array)) {
        return json_object_array_length(json_array);
    }
    return 0;
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
        note_temp_pt = create_note_object(title, text, createdAt);
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
    return getArraySize(array);
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
        MULFILE_create_note_file(UNTITLED);
        filename = UNTITLED;
    }
    file_pointer = openFile(filename, DATA_DIR, "w+");

    struct json_object* json_file = json_object_new_object();
    struct json_object* note_object = new_note_object(finite_note);

    json_object_object_add(json_file, "note" ,note_object);

    const char* file_input = json_object_to_json_string_ext(json_file, JSON_C_TO_STRING_PRETTY);
    fputs(file_input, file_pointer);

    fclose(file_pointer);
}

void MULFILE_create_note_file(char* filename){
    if(filename == NULL)
        return;
    if(is_exist(filename, DATA_DIR))
        return;

    char* filepath[BUFFER];
    sprintf(filepath, "%s%s", MEDIA_PATH, DATA_DIR_NAME);
    create_file(filename, DATA_DIR);
}