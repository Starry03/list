CC = gcc
FLAGS = -Wall -Werror -Wextra
OPT = -O3
NAME = list
PROGRAM_FLAGS = -a -R -d

UNIC = ./UniC/UniC.a -I./UniC

all:
	cd UniC && make re
	$(CC) $(FLAGS) $(OPT) *.c -o $(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) $(PROGRAM_FLAGS)
