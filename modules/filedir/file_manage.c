#include "file_manage.h"
char* MEDIA_PATH = NULL;



FILE* openFile(char* filename, char* originDir, char* mode){
    char* path = get_obj_path(filename, originDir);
    FILE* fp = fopen(path, mode);
    free(path);
    return fp;
}

char* get_obj_path(char* filename, char* dirname) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return NULL;
    }
    struct dirent* filedir_obj;
    while ((filedir_obj = readdir(dir)) != NULL) {
        if (!str_cmp(filedir_obj->d_name, "..") && !str_cmp(filedir_obj->d_name, ".")) {
            char path[BUFFER];
            if (filedir_obj->d_type == DT_DIR) {
                sprintf(path, "%s/%s", dirname, filedir_obj->d_name);
                char* file_path = get_obj_path(filename, path);
                if (file_path != NULL) {
                    return file_path;
                }
            }
            if (str_cmp(filename, filedir_obj->d_name)){
                char* file_path = static_to_dynamic_copy(path);
                sprintf(file_path, "%s/%s", dirname, filedir_obj->d_name);
                return file_path;
            }
        }
    }
    closedir(dir);
    return NULL;
}


