#include "coreparselib.h"



int main(void){
    srand(time(NULL)); //it should be in main project

    //--------FILEDIR-DEBUG------------------------------------------------------------


    get_file_path("package.json");


    //--------------------JSONINSIDERS-DEBUG----------------------------------------()
    char title[BUFFER] = "Some_important";
    char text[BUFFER] = "some text";

    char task_text[BUFFER] = "You need to do it!";
    char must_finished[BUFFER] = "19.06.23";

    note* new_note = create_note_structure(title, text, date_to_str(return_time()));
    task* new_task = create_task_structure(task_text, date_to_str(return_time()), must_finished);


    //--------------------JSONUTILS-DEBUG----------------------------

    printf("Hello world!");
    return 0;
}