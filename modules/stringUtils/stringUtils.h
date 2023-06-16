#ifndef COREPARSELIB_STRINGUTILS_H
#define COREPARSELIB_STRINGUTILS_H
#define IN 1
#define OUT 0
#include "../common.h"
static const char stop_words[3] = {' ', '.', '/'};

//return the size of string
int get_length(const char* string);

//Following function implements basic_str + add_str action

char* concatenateStr(char* basic_str, char* add_str);

//src -> dst
void copy(char* src, char* dst);

//"hello world" -> {"hello", "world"}
char** str_parser(char* string);

//if " " == symbol -> true
bool detect_stop(char symbol);

char* static_to_dynamic_copy(const char* static_string);

#endif //COREPARSELIB_STRINGUTILS_H
