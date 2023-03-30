COMP = gcc -Wall -Werror -Wextra

all: build_db

build_db:
	$(COMP) shared.c menu_print.c modules_db.c -o ../build/Quest_1

clean:
	rm -rf ../build/Quest_1

rebuild: clean all
