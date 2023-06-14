#ifndef CORE_PARSE_LIB_CORE_STRING_H
#define CORE_PARSE_LIB_CORE_STRING_H
#include "../common.h"
#define IN 1 
#define OUT 0
const char stop_words[] = {' ', '\t', '\n', '\r'};
//Function for copying str1 into str2.
//Also takes a parameter of str1 size.
void copy(char*, char*, int);

//str1 - root_direction, str2 - file_name; it combines into one big string for functions from file_management.c
//saves into str2
//Naive implementation. Works for time O(n)
void S_concatenate_str(char*, char*);

///another method for combining root and file_name into one string through dynamic allocation of memory
//saves into new string, pointer of it returns this function 
char* D_concatenate_str(const char*, const char*);

//returns size of string
int get_len(char*);

//divides input str into array of strings consisting separate words or symbols
//dynamic allocation of memory. There's a need of freeing heap memory
char** str_parser(const char*);

char* static_to_dynamic_copy(char*);

#endif //CORE_PARSE_LIB_CORE_STRING_H
