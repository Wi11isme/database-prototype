#ifndef MENU_PRINT
#define MENU_PRINT

void start_menu();
char *table_select(int *res);
int operate_menu(int oper, char *filename);
void select(int count_line, char *filename);
int insert(char *filename);

#endif
