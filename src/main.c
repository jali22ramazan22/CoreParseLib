#include "main.h"
char root_const[BUFFER] = "data/";
int main(void){
    char file_name[BUFFER];
    scanf("%s", file_name);
    S_concatenate_str(file_name, root_const);
    printf("%s", root_const);
}
