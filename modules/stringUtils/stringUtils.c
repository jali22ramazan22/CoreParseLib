#include "stringUtils.h"

int get_length(const char* string){
    if(string == NULL)
        return 0;
    int i = 0;
    for(; string[i] != '\0'; ++i);
    return i;
}

void copy(char* src, char* dst){
    if(src == NULL || dst == NULL){
        printf("Error: one of the strings does not exist");
        return;
    }
    int len = get_length(src);
    for(int i = 0; i < len; ++i){
        dst[i] = src[i];
    }
    dst[len] = '\0';
}

bool detect_stop(char symbol){
    for(int i = 0; i < 9; ++i){
        if(symbol == stop_words[i]){
            return true;
        }
    }
    return false;
}

char* concatenateStr(char* basic_str, char* add_str){
    if(basic_str == NULL || add_str == NULL){
        printf("Error: one of the strings does not exist");
        return NULL;
    }
    int len1 = get_length(basic_str);
    int len2 = get_length(add_str);
    char* new_str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));

    if (new_str == NULL) {
        printf("Error: memory allocation failed");
        return NULL;
    }

    for(int i = 0; i < len1; ++i){
        new_str[i] = basic_str[i];
    }
    for(int j = 0; j < len2; ++j){
        new_str[j + len1] = add_str[j];
    }

    new_str[len1 + len2] = '\0';
    return new_str;
}


char** str_parser(char* string){
    int state = OUT;
    int i = 0;
    int word_cnt = 0;
    int str_len = strlen(string);

    char **word_collection = NULL;
    char *word = NULL;

    for (int j = 0; j < str_len; ++j) {
        char c = string[j];

        if (detect_stop(c)) {
            if (i > 0) {
                word = malloc(sizeof(char) * (i + 1));
                strncpy(word, string + j - i, i);
                word[i] = '\0';
                word_collection = realloc(word_collection, sizeof(char*) * (word_cnt + 1));
                word_collection[word_cnt++] = word;
                i = 0;
            }

            state = OUT;
        } else if (state == OUT) {
            state = IN;
        }

        if (!detect_stop(c)) {
            string[i] = tolower(c);
            i++;
        }
    }

    word_collection[word_cnt] = NULL;

    return word_collection;
}


char* static_to_dynamic_copy(const char* static_string){
    if (static_string == NULL) {
        printf("Error: input string does not exist");
        return NULL;
    }
    int size = get_length(static_string);
    char* str_ptr = (char*)malloc(sizeof(char) * (size + 1));
    if (str_ptr == NULL) {
        printf("Error: memory allocation failed");
        return NULL;
    }
    copy(static_string, str_ptr);
    str_ptr[size] = '\0';
    return str_ptr;
}

bool str_cmp(char* str1, char* str2){
    int len1, len2;
    len1 = get_length(str1);
    len2 = get_length(str2);
    if(len1 != len2)
        return false;
    if(str1 == NULL || str2 == NULL) {
        printf("Error: string does not exist");
        return false;
    }
    for(int i = 0; i < len1; ++i){
        if(str1[i] != str2[i])
            return false;
    }

    return true;

}