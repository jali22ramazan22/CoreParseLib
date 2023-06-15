#ifndef COREPARSELIB_JSONINSIDERS_H
#define COREPARSELIB_JSONINSIDERS_H
#include "../common.h"
#include "../filedir/file_manage.h"
#define DATA_DIR "../TestingDirectory/data/"

typedef struct{
    char* title;
    char* text;
    char* createdAt;
}note;

typedef struct{
    int year;
    int month;
    int day;
}date;


date return_time(void);
void write_a_note(note*, FILE* file_pointer);
char* date_to_str(date);


#endif //COREPARSELIB_JSONINSIDERS_H
