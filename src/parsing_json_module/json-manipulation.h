#ifndef CORE_PARSE_LIB_CREATE_TASK_H
#define CORE_PARSE_LIB_CREATE_TASK_H
#include "../common.h"
#include "../file_dir_module/dir_management.h"
#include "../file_dir_module/file_management.h"
typedef struct{
    char* title;
    char** text;
    char* created_at;
    char* changed_at; 
}note;

typedef struct{
    int year;
    int month;
    int day;
}date;

date return_time(void);

void write_a_note_(note*);
char* date_to_str(const date);





#endif
