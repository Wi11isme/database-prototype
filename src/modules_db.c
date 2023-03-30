#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu_print.h"
#include "shared.h"
#define LEN 100

void again(int *res, int *depth);

int main() {
    int depth = 1, res = 1;
    double oper = 5;
    char *filename = malloc(LEN * sizeof(char));
    while (oper != 0) {
        if (depth == 1) {
            start_menu();
            rewind(stdin);
            if (scanf("%lf", &oper) && oper == (int)oper)
                depth = 2;
            else
                again(&res, &depth);
        } else if (depth == 2) {
            table_select(filename, &res);
            if (!filename || !res)
                again(&res, &depth);
            else
                depth = 3;
        } else if (depth == 3) {
            if (!operate_menu((int)oper, filename))
                again(&res, &depth);
            else
                depth = 1;
        } else
            again(&res, &depth);
        if (res == 0 && oper != 0) printf("n/a\n");
    }
    free(filename);
    return 0;
}

void again(int *res, int *depth) {
    *res = 0;
    *depth = 1;
}
