#include "jsonInsiders.h"



void write_note(note* finite_note, FILE* file_pointer, char* filename) {
    if(filename == NULL)
        filename = UNTITLED;
    // Check if finite_note is NULL, create a new note object if it is
    if (finite_note == NULL) {
        finite_note = create_note_object("Untitled", "", date_to_str(return_time()));
    }

    // Check if file_pointer is NULL, create a new file if it is
    if (file_pointer == NULL) {
        create_notion_array(filename);
        file_pointer = openFile(filename, DATA_DIR, "a+");
        if (file_pointer == NULL) {
            printf("Error: Unable to open file.\n");
            return;
        }
    }

    char p_str[BUFFER];
    fread(p_str, BUFFER, 1, file_pointer);
    struct json_object* parsed_json;

    struct json_object* note_array; //new array that will be rewritten in JSON file
    struct json_object* temp_array; //temporary array for reading current JSON file notes array
    struct json_object* note_object; //the new note object

    struct json_object* new_object = json_object_new_object();

    // Parse the JSON string from the file
    parsed_json = json_tokener_parse(p_str);

    // Get the "notes" array from the parsed JSON
    json_object_object_get_ex(parsed_json, "notes", &temp_array);
    note_array = cpy_array(temp_array);

    size_t size = getArraySize(note_array);

    // Create a new note object and add its properties
    note_object = json_object_new_object();
    json_object_object_add(note_object, "title", json_object_new_string(finite_note->this_title));
    json_object_object_add(note_object, "text", json_object_new_string(finite_note->this_text));
    json_object_object_add(note_object, "createdAt", json_object_new_string(finite_note->this_createdAt));
    json_object_object_add(note_object, "id", json_object_new_int((int)(size)));

    // Add the note object to the note array
    json_object_array_add(note_array, note_object);

    // Add the note array to the new object
    json_object_object_add(new_object, "notes", note_array);

    // Close the file
    fclose(file_pointer);

    // Open the file in write mode and delete older content of the file
    file_pointer = openFile(filename, DATA_DIR, "w");

    // Convert the new object to a JSON string
    const char* updated_json_string = json_object_to_json_string_ext(new_object, JSON_C_TO_STRING_PRETTY);

    // Write the JSON string to the file
    fputs(updated_json_string, file_pointer);

    // Clean up the resources
    destruct_note_object(finite_note);
    fclose(file_pointer);
}



size_t getArraySize(struct json_object *json_array) {
    if (json_object_is_type(json_array, json_type_array)) {
        return json_object_array_length(json_array);
    }
    return 0;
}

void create_notion_array(char* filename){
    if(filename == NULL)
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


