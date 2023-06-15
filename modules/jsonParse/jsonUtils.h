

#ifndef COREPARSELIB_JSONUTILS_H
#define COREPARSELIB_JSONUTILS_H
#include "../common.h"
#include "../stringUtils/stringUtils.h"

typedef struct{
    char* this_title;
    char* this_text;
    char* this_createdAt;
    int id;
}note;

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

//GOVNOCODE (However, JSON parsing function that return all notes in notes array.)
//array ends the null ptr to make iteration without any size information possible.
//EXAMPLE: notes** array -> [Note1, Note2, NULL] -> Note1, Note2, NULL = note structure
note** get_all_notes(FILE* file_pointer);

//deleting dynamically allocated array of note structures
//using another function 'destruct_note_object(note* note_ptr)'
//that separately deletes allocated memory of every element
void notes_array_destructor(note** notes_arr);

//Just a util to return unsigned integer for getting the of notes array
size_t get_notes_count(FILE* file_pointer);

#endif //COREPARSELIB_JSONUTILS_H
