#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu_print.h"

typedef struct data {
    int id_mod;
    char mod_name[30];
    int level_num;
    int cell_num;
    int flag_del;
} modules;

typedef struct data1 {
    int level_num;
    int cell_count;
    int flag_secr;
} levels;

typedef struct data2 {
    int id_event;
    int id_mod;
    int status;
    char stat_date[11];
    char stat_time[9];
} status_events;

void select(int count_line, char* filename);
int insert(char* filename);
void update(char* filename);
int delete (char* filename);

#endif