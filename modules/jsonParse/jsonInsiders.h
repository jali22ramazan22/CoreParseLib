#ifndef COREPARSELIB_JSONINSIDERS_H
#define COREPARSELIB_JSONINSIDERS_H
#include "../common.h"
#include "../filedir/file_manage.h"
#include "jsonUtils.h"
#define DATA_DIR "../TestingDirectory/data/"
#define UNTITLED "untitled_note.json"


//gets the note_structure and file_pointer in params
//if note_structure wasn't given (NULL-pointer), the procedure creates untitled note_structure and appends into following file
//this case of empty file_pointer comes to play: if it is NULL pointer it, the untitled file would be created
void write_note(note* finite_note, FILE* file_pointer, char* filename);




//gets the filename and automatically puts it in constant path pointed in root_catalogue variable
//procedure creates the untitled file and puts into it the 'notes' array for next actions
void create_notion_array(char* filename);

#endif //COREPARSELIB_JSONINSIDERS_H
