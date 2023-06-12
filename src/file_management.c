#include "file_management.h"


FILE* pointer_connection(char* file_name, char* mode){
    FILE *fp; 
    if((fp = fopen(file_name, mode)) == NULL){
        printf("Error: cannot open the file");
        return NULL;
    }
    return fp;
}

char* D_concatenate_str(const char* str1, const char* str2){ //dynamic concatenation
		int len1, len2;
		len1 = len2 = 0;
		for(; str1[len1] != '\0'; ++len1);
		for(; str2[len2] != '\0'; ++len2);

		char* res_str = (char*)malloc(sizeof(char) * (len1 + len2));
		
		for(int i = 0; str1[i] != '\0'; ++i){
			res_str[i] = str1[i];
		}
		for(int j = 0; str2[j] != '\0'; ++j){
			res_str[len1++] = str2[j];
		}
		res_str[len1] = '\0';
		return res_str;
}

void S_concatenate_str(char* origin, const char* add){ //static concatenation (Let all strings with buffer size - 1024)
	int len1, len2;
	len1 = len2 = 0;
	for(; origin[len1] != '\0'; ++len1);
	for(; add[len2] != '\0'; ++len2);
	int common = len1 + len2 + 1;
	for()

}

void check_file(char* file_name){
    char* file_root = D_concatenate_str(root_const, file_name);
    FILE* fp = pointer_connection(file_root, "r");
    if(fp == NULL)
        return;
    fclose(fp);
}

void add_file(char* file_name){
    
    char* file_root = D_concatenate_str(root_const, file_name);
    FILE *fp = pointer_connection(file_root, "a");
    if(fp == NULL)
        return;
    fclose(fp);
}

void read_file(char* file_name){
    char* file_root = D_concatenate_str(root_const, file_name);
    FILE *fp = pointer_connection(file_root, "r");
    if (fp == NULL) {
        return;
    }
    
    char _display_buffer_[BUFFER];
    while (fgets(_display_buffer_, BUFFER, fp) != NULL) {
        printf("%s", _display_buffer_);
    }
    
    fclose(fp);
}
