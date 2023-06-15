#include "coreparselib.h"



int main(void){
    //----------------------------stringUtils-DEBUG----------------------------------------

    /*DELETE_THIS_STR

    printf("/STARTING TESTCASE SCENARIOS\\\n");
    sleep(1);
    char BASIC_STR[BUFFER] = "Here's your cup of tea";
    char ADD_STR[BUFFER] = " and I forgot your donut";


    printf("%d -> 22\n", get_length(BASIC_STR));
    sleep(1);
    char* NEW_STR = concatenateStr(BASIC_STR, ADD_STR);

    printf("%s -> Here's your cup of tea and I forgot your donut\n", NEW_STR);
    free(NEW_STR);
    sleep(1);
    //--------FILEDIR-DEBUG------------------------------------------------------------
    config_creation();
    sleep(1);

    DELETE_THIS_STR*/

    //--------------------JSONINSIDERS-DEBUG----------------------------------------


    FILE* fp = openFile("notes.json", "../TestingDirectory/data/" , "a+");
    create_DATA_dir();
    config_creation();
    write_a_note(NULL, fp);
    return 0;
}