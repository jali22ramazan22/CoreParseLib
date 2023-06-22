

#ifndef COREPARSELIB_FILE_MANAGE_H
#define COREPARSELIB_FILE_MANAGE_H
#include "../common.h"
#include "../stringUtils/stringUtils.h"
#define CURRENT_DIR "."
#define PARENT_DIR ".."
extern char* MEDIA_PATH;



FILE* openFile(char* filename, char* originDir, char* mode);

char* get_obj_path(char* filename, char* dirname);



#endif //COREPARSELIB_FILE_MANAGE_H
