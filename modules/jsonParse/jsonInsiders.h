#ifndef COREPARSELIB_JSONINSIDERS_H
#define COREPARSELIB_JSONINSIDERS_H
#include "jsonUtils.h"

void write_note(note* finite_note, char* filename, char* originDir, char* subdirectory);

void write_task(task* finite_task, char* filename, char* originDir, char* subdirectory);

void write_object_info_in_config(void* object, char* filepath, char* originDir,void(*get_append_JSON_object_info)(void* object,
        char* filepath, char* buffer, FILE* file_config_pointer));


#endif //COREPARSELIB_JSONINSIDERS_H
