#include "string_utils.h"
extern const char stop_words[];

void copy(char* str1, char* str2, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        str2[i] = str1[i];
    }
    str2[i] = '\0';
}

bool detect_stop(char symbol){
    for(int i = 0; i < 4; ++i){
        if(stop_words[i] == symbol){
            return true;
        }
    }
    return false;
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



void S_concatenate_str(char* str1, char* str2){ 
   char temp[BUFFER];
   int len1, len2;
   len1 = len2 = 0;
   
   for(; str1[len1] != '\0'; ++len1);
   for(; str2[len2] != '\0'; ++len2);
   int common = len1 + len2;
   int i, j;
   
   copy(str2, temp, len2);
   for(i = 0; i < len2; ++i){
      str2[i+len1] = temp[i];
   }
   
   for(j = 0; j < len1; ++j){
      str2[j] = str1[j];
   }
   str2[common] = '\0';

}


int get_len(char* str){
   int i = 0;
   for(; str[i] != '\0'; ++i);
   return i;
}


char** str_parser(const char* input_string){
   int state = OUT;
   int i = 0;
   int word_cnt = 0;

   const int max_word_length = 50;
   const int max_word_count = 10;

   char string[max_word_length];
   char** word_collection = malloc(sizeof(char*)*(max_word_count + 1));
   char* word = NULL;

   for(int j = 0; j <= max_word_count; j++){
        word_collection[j] = NULL;
    }

   for(int j = 0; j < strlen(input_string); j++){
        char c = input_string[j];

        if(detect_stop(c)){
            if (i > 0) {
                word = malloc(sizeof(char) * (i + 1));
                strncpy(word, string, i);
                word[i] = '\0';
                word_collection[word_cnt++] = word;
                i = 0;

                if(word_cnt >= max_word_count){
                    break;
                }
            }

            state = OUT;
        } 
        else if(state == OUT){
            state = IN;
        }

        if(!detect_stop(c)){
            string[i] = tolower(c);
            i++;
        }
    }

    word_collection[word_cnt] = NULL;

    return word_collection;
}


char* static_to_dynamic_copy(char* buffer){
    char* str_ptr;
    int size = get_len(buffer);
    str_ptr = (char*)malloc(sizeof(char)*size);
    copy(buffer, str_ptr, size);
    return str_ptr;
}