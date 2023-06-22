#include "coreparselib.h"


extern char* MEDIA_PATH;

int main() {
    MEDIA_PATH = "../testdir";
    note* new_task = create_task_structure("Untitled", "text", date_to_str(return_time()));
    write_task(new_task, "IMPORTANT.json", MEDIA_PATH, NULL);
}
