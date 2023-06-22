#ifndef COREPARSELIB_JSONUTILS_H
#define COREPARSELIB_JSONUTILS_H
#include "../common.h"
#include "../filedir/file_procedures_func.h"
#include "../filedir/file_manage.h"
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
    char* id;
}task;



typedef struct{
    int year;
    int month;
    int day;
}date;
//-------------------------------STRUCTURE-PROCEDURES---------------------------
char* unique_object_id_generator(void);

note* create_note_structure(const char* title, const char* text, const char* createdAt);


task* create_task_structure(const char* text, const char* createdAt, const char* mustFinished);

void destruct_task_structure(task* task_object);

//custom destructor of dynamically allocated note_structure
void destruct_note_structure(note* note_object);

//uses the time.h module to get local time
date return_time(void);

//function-transformator to get the string-value of date_time
char* date_to_str(date creation_data);

//--------------------------------------------------------------------

//transform "note" structure to json_note structure
struct json_object* new_JSON_note_object(note* finite_note);

struct json_object* new_JSON_task_object(task* finite_task);




void get_append_JSON_task_info(void* object_pointer, char* filepath, char* buffer, FILE* file_config_pointer);


void get_append_JSON_note_info(void* object_pointer, char* filepath, char* buffer, FILE* file_config_pointer);

struct json_object* new_JSON_task_info_object(task* finite_task, char* filepath);

struct json_object* new_JSON_note_info_object(note* finite_note, char* filepath);
#endif //COREPARSELIB_JSONUTILS_H
