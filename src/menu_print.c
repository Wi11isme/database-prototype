#include "menu_print.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared.h"
#define LEN 100

void start_menu() {
    printf("  Please choose one operation:\n");
    printf("    0. EXIT\n    1. SELECT\n    2. INSERT\n    3. UPDATE\n    4. DELETE\n");
}

void table_select(char* filename, int* res) {
    printf("  Please choose a table:\n");
    printf("    1. Modules\n    2. Levels\n    3. Status events\n");
    double choice;
    if (!(scanf("%lf", &choice) && choice == (int)choice))
        *res = 0;
    else {
        if (filename) {
            if ((int)choice == 1)
                strcpy(filename, "../materials/master_modules.db");
            else if ((int)choice == 2)
                strcpy(filename, "../materials/master_levels.db");
            else if ((int)choice == 3)
                strcpy(filename, "../materials/master_status_events.db");
            else
                *res = 0;
        } else
            *res = 0;
    }
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
        update(filename);
    } else if (oper == 4) {
        printf("  Insert the number of records to delete them.\n");
        int n = delete (filename);
        if (n > -1)
            printf("  Line %d was deleted.", n);
        else
            res = 0;
    } else
        res = 0;
    return res;
}