#include "shared.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu_print.h"

void select(int count_line, char* filename) {
    FILE* file = fopen(filename, "rb");
    if (filename[20] == 'm') {
        modules line;
        if (count_line == 0) {
            while (fread(&line, sizeof(modules), 1, file))
                printf("%d %s %d %d %d\n", line.id_mod, line.mod_name, line.level_num, line.cell_num,
                       line.flag_del);
        } else
            for (int i = 0; i < count_line; i++) {
                fread(&line, sizeof(modules), 1, file);
                printf("%d %s %d %d %d\n", line.id_mod, line.mod_name, line.level_num, line.cell_num,
                       line.flag_del);
            }
    } else if (filename[20] == 'l') {
        levels line;
        if (count_line == 0) {
            while (fread(&line, sizeof(levels), 1, file))
                printf("%d %d %d\n", line.level_num, line.cell_count, line.flag_secr);
        } else
            for (int i = 0; i < count_line; i++) {
                fread(&line, sizeof(levels), 1, file);
                printf("%d %d %d\n", line.level_num, line.cell_count, line.flag_secr);
            }
    } else if (filename[20] == 's') {
        status_events line;
        if (count_line == 0) {
            while (fread(&line, sizeof(status_events), 1, file))
                printf("%d %d %d %s %s\n", line.id_event, line.id_mod, line.status, line.stat_date,
                       line.stat_time);
        } else
            for (int i = 0; i < count_line; i++) {
                fread(&line, sizeof(status_events), 1, file);
                printf("%d %d %d %s %s\n", line.id_event, line.id_mod, line.status, line.stat_date,
                       line.stat_time);
            }
    }
    fclose(file);
}

int insert(char* filename) {
    int res = 1;
    FILE* file = fopen(filename, "ab");
    if (filename[20] == 'm') {
        modules line;
        if (!scanf("%255d %30s %255d %255d %255d", &line.id_mod, line.mod_name, &line.level_num,
                   &line.cell_num, &line.flag_del))
            res = 0;
        else
            fwrite(&line, sizeof(modules), 1, file);
    } else if (filename[20] == 'l') {
        levels line;
        if (!scanf("%255d %255d %255d\n", &line.level_num, &line.cell_count, &line.flag_secr))
            res = 0;
        else
            fwrite(&line, sizeof(levels), 1, file);
    } else if (filename[20] == 's') {
        status_events line;
        if (!scanf("%255d %255d %255d %11s %9s\n", &line.id_event, &line.id_mod, &line.status, line.stat_date,
                   line.stat_time))
            res = 0;
        fwrite(&line, sizeof(status_events), 1, file);
    }
    fclose(file);
    return res;
}

void update(char* filename) { select(0, filename); }

void delete (char* filename) {
    FILE* file = fopen(filename, "w");
    fclose(file);
}