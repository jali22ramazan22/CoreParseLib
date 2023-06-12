#include "main.h"
char root_const[BUFFER] = "data/";
int main(void){
    char file_name[BUFFER];
    scanf("%s", file_name);
    S_concatenate_str(root_const, file_name);
    printf("%s", root_const);
}