#ifndef CORE_PARSE_LIB_DIR_MANAGMENT_H
#define CORE_PARSE_LIB_DIR_MANAGMENT_H
#include "common.h"
#include "string_utils.h"
typedef struct {
    char dirpath[BUFFER];
    DIR* dp;
    
}directory_struct;

//The function that returns the structure of directory pointer and path
//Takes as param directory name and turns into full path by root_path constant and uses string_utils.h
directory_struct* directory_connection(char*);

//creating directory that takes as param pointer on struct
//the creation makes dir changeable, readable and also deletes dynamic data from pointer on struct
void create_directory(directory_struct* );

//the procedure that combines two functions "create_dir", "dir_connection"
void create_directory_procedure(char*);

#endif //CORE_PARSE_LIB_DIR_MANAGMENT_H