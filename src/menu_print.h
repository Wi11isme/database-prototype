#ifndef MENU_PRINT
#define MENU_PRINT

void start_menu();
void table_select(char *filename, int *res);
int operate_menu(int oper, char *filename);
void select(int count_line, char *filename);
int insert(char *filename);

#endif
