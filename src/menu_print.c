#include "menu_print.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100

void start_menu() {
    printf("  Please choose one operation:\n");
    printf("    0. EXIT\n    1. SELECT\n    2. INSERT\n    3. UPDATE\n    4. DELETE\n");
}

char* table_select(int* res) {
    printf("  Please choose a table:\n");
    printf("    1. Modules\n    2. Levels\n    3. Status events\n");
    int choice;
    char* filename = malloc(LEN * sizeof(char));
    scanf("%d", &choice);
    if (filename) {
        if (choice == 1)
            strcpy(filename, "../materials/master_modules.db");
        else if (choice == 2)
            strcpy(filename, "../materials/master_levels.db");
        else if (choice == 3)
            strcpy(filename, "../materials/master_status_events.db");
        else
            *res = 0;
    } else
        *res = 0;
    return filename;
}

int operate_menu(int oper, char* filename) {
    int res = 1, count_line;
    if (oper == 1) {
        printf("  Insert the number of records or leave empty to output all of them: \n");
        if (scanf("%d", &count_line) && count_line >= 0) {
            select(count_line, filename);
        } else
            res = 0;
    } else if (oper == 2) {
        printf("  Insert the data in structure type : \n");
        if (!insert(filename)) res = 0;
    } else if (oper == 3) {
        printf("  Updated data:\n");
    } else if (oper == 4) {
        printf("  Insert the number of records to delete them.\n");
    }
    return res;
}
