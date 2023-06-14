#ifndef CORE_PARSE_LIB_CORE_PARSE_LIB_H
#define CORE_PARSE_LIB_CORE_PARSE_LIB_H
#include "src/file_dir_module/file_management.h"
#include "src/common.h"
#include "src/string_utils_module/string_utils.h"
#include "src/file_dir_module/dir_management.h"
//--------------------------FILE-MANAGMENT MODULE------------------------------------

//---------Auxillary functions/procedures of file_managment module---------------
extern bool exist_check(char* filename);
extern FILE* file_connection(char* filename, const char* mode);
extern void create_file(char* filename);


//--------MAIN functions/procedures of file_managment module----------
extern void data_creation_procedure(char* filename);


//--------------------------DIR-MANAGMENT MODULE------------------------------------
extern void create_directory_procedure(char* directory_name);

#endif //CORE_PARSE_LIB_CORE_PARSE_LIB_H
