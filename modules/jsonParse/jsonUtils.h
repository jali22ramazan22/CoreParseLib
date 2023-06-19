

#ifndef COREPARSELIB_JSONUTILS_H
#define COREPARSELIB_JSONUTILS_H
#include "../common.h"
#include "../stringUtils/stringUtils.h"
#include "../filedir/file_manage.h"
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
    char* id;
}task;



typedef struct{
    int year;
    int month;
    int day;
}date;



//dynamic allocation and creation of note structure
note* create_note_structure(const char* title, const char* text, const char* createdAt);


task* create_task_structure(const char* text, const char* createdAt, const char* mustFinished);

void destruct_task_structure(task* task_object);


struct json_object* new_JSON_task_object(task* finite_task);

struct json_object* new_JSON_task_info_object(task* finite_task, char* filepath);

//returns unsigned int of json array size
size_t getArraySize(struct json_object* json_array);

//custom destructor of dynamically allocated note_structure
void destruct_note_structure(note* note_object);

//uses the time.h module to get local time
date return_time(void);

//function-transformator to get the string-value of date_time
char* date_to_str(date creation_data);



//transform "note" structure to json_note structure
struct json_object* new_JSON_note_object(note* finite_note);

struct json_object* new_JSON_note_info_object(note* finite_note, char* filepath);
//generator for id of id, assigns every object pseudo-randomly generated key(id);
//has format  int_arr + char
// Example: 1210387F
char* unique_object_id_generator(void);


void config_creation(void);


void get_append_JSON_task_info(void* object_pointer, char* filepath, char* buffer, FILE* file_config_pointer);


void get_append_JSON_note_info(void* object_pointer, char* filepath, char* buffer, FILE* file_config_pointer);
#endif //COREPARSELIB_JSONUTILS_H
