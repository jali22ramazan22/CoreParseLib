#include "coreparselib.h"



int main(void){
    srand(time(NULL));
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
    //--------------------JSONINSIDERS-DEBUG----------------------------------------()
    char title[BUFFER] = "Untitled";
    char text[BUFFER] = "Some sassy text";

    char task_text[BUFFER] = "You need to do it!";
    char must_finished[BUFFER] = "19.06.23";

    note* new_note = create_note_structure(title, text, date_to_str(return_time()));
    task* new_task = create_task_structure(task_text, date_to_str(return_time()), must_finished);

    //--------------------JSONUTILS-DEBUG----------------------------

    ONEFILE_write_note(new_note, NULL);
    printf("Hello world!");
    return 0;
}