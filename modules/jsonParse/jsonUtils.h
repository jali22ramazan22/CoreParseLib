

#ifndef COREPARSELIB_JSONUTILS_H
#define COREPARSELIB_JSONUTILS_H
#include "../common.h"
#include "../stringUtils/stringUtils.h"

typedef struct{
    char* this_title;
    char* this_text;
    char* this_createdAt;
    char* id;
}note;

typedef struct{
    char* this_text;
    char* this_created_at;
    char* this_must_finished;
}task;

typedef struct{
    char* this_note_title;
    char* this_note_id;
    char* this_tag;
    char* this_notePath;
}tag;

typedef struct{
    int year;
    int month;
    int day;
}date;

//dynamic allocation and creation of note structure
note* create_note_object(const char* title, const char* text, const char* createdAt);

//returns unsigned int of json array size
size_t getArraySize(struct json_object* json_array);

//custom destructor of dynamically allocated note_structure
void destruct_note_object(note* note_object);

//uses the time.h module to get local time
date return_time(void);

//function-transformator to get the string-value of date_time
char* date_to_str(date creation_data);

//gets as param temporary array, it is meant that if you read the JSON file and encountered
//custom array you can copy all objects into new array
struct json_object* cpy_array(struct json_object* temp_array);

//transform "note" structure to json_note structure
struct json_object* new_note_object(note* finite_note);

char* unique_note_id_generator(void);



#endif //COREPARSELIB_JSONUTILS_H
