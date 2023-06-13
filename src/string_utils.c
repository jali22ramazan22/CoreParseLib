#include "string_utils.h"
//Function for copying str1 into str2.
//Also takes a parameter of str1 size.
void copy(char* str1, char* str2, int size){
   int i;
   for(i = 0; i < size; ++i){
      str2[i] = str1[i];
   }
   str2[size] = '\0';
}

//another method for combining root and file_name into one string through dynamic allocation of memory
//saves into new string, pointer of it returns this function 
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


//str1 - root_direction, str2 - file_name; it combines into one big string for functions from file_management.c
//saves into str2
//Naive implementation. Works for time O(n)
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