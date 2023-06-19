#ifndef COREPARSELIB_JSONINSIDERS_H
#define COREPARSELIB_JSONINSIDERS_H
#include "../common.h"
#include "../filedir/file_manage.h"
#include "jsonUtils.h"
#define UNTITLED_NOTE "untitled_note.json"
#define UNTITLED_TASK "untitled_task.json"
//ONE-FILE functionality: for ergonomic purposes; if you desire to store all of you note_obj in one file - the following
//functions for you

//gets the note_structure and file_pointer in params
//if note_structure wasn't given (NULL-pointer), the procedure creates untitled note_structure and appends into following file
//this case of empty file_pointer comes to play: if it is NULL pointer it, the untitled file would be created
// file_ptr > filename (It's meant that if you write both params down) the file_ptr will be written
void ONEFILE_write_note(note* finite_note, char* filename);

//gets the filename and automatically puts it in constant path pointed in root_catalogue variable
//procedure creates the untitled file and puts into it the 'notes' array for next actions
void ONEFILE_create_notion_array(char* filename);

//GOVNOCODE (However, JSON parsing function that return all notes in notes array.)
//array ends the null ptr to make iteration without any size information possible.
//EXAMPLE: notes** array -> [Note1, Note2, NULL] -> Note1, Note2, NULL = note structure
note** ONEFILE_get_all_notes(FILE* file_pointer);

//Just a util to return unsigned integer for getting the of notes array
size_t ONEFILE_get_notes_count(FILE* file_pointer);

//deleting dynamically allocated array of note structures
//using another function 'destruct_note_object(note* note_ptr)'
//that separately deletes allocated memory of every element
void notes_array_destructor(note** notes_arr);




//MUL-FILE FUNCTIONALITY: if you want to create note_obj in separate files (Saving the notes always in separated files), the following
//functions for you



//Creating json file for separate note
//Always put created finite_note object, if NULL -> running will be aborted
void MULFILE_write_note(note* finite_note, char* filename);

//Function that called in "MULFILE_write_note" to create the new-untitled file
void MULFILE_create_object_file(char* filename);

//Creating json file for separate task
//Always put created finite_task object, if NULL -> running will be aborted
void MULFILE_write_task(task* finite_task, char* filename);



void MULFILE_write_object_data_path_config(void* object, FILE* file_object_pointer, void(*get_append_JSON_object_info)(void* object,
        char* filepath, char* buffer, FILE* file_config_pointer));



//TASK : CREATE A LINKING FILE WITH ALL TYPES OF OBJECT AND ITS PATHES
// - RECURSIVE FINDER
// - LIST DIRECTORY
// - CREATING LINK_SAVE_FILE (DONE)
// - SAVING ALSO IN JSON FILE AND ARRAYS IN IT WITH ALL OBJECTS (DONE)


// - DELETING OBJ FILE AND FROM CONFIG
// - CHECKING THE EXISTANCE OF FILE


#endif //COREPARSELIB_JSONINSIDERS_H
