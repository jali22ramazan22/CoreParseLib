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

    //--------------------JSONINSIDERS-DEBUG----------------------------------------()
    char title[BUFFER] = "Untitled";
    char text[BUFFER] = "Some sassy text";

    note* new_note = create_note_object(title, text, date_to_str(return_time()));
    FILE* fp = openFile(UNTITLED, DATA_DIR, "a+");
    write_note(new_note, fp, NULL);
    //--------------------JSONUTILS-DEBUG----------------------------

    /*
    note** notes = get_all_notes(fp);
    for(int i = 0; notes[i] != NULL; ++i){
        printf("%s\n", notes[i]->this_text);
    }
    notes_array_destructor(notes);
    */


    return 0;
}