#include "dir_managment.h"


directory_struct* directory_connection(char* directory_name){
    directory_struct* connect = (directory_struct*)malloc(sizeof(directory_struct));
    S_concatenate_str(root_const, directory_name); //directory name -> dir-path (Watch directory struct)
    copy(directory_name, connect->dirpath, get_len(directory_name));
    connect->dp = opendir(directory_name);
    return connect;
}



void create_directory(directory_struct* connection){
    mkdir(connection->dirpath, 0700);
    closedir(connection->dp);
    free(connection);
}

void create_directory_procedure(char* directory_name){
    directory_struct* connection = directory_connection(directory_name);
    if(connection->dp != NULL){
        printf("Error: THE FOLLOWING DIRECTORY ALREADY EXISTS");
        free(connection);
        return;
    }
    create_directory(connection);
}
