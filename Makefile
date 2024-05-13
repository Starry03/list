CC = gcc
FLAGS = -Wall -Werror -Wextra
OPT = -O2
NAME = list

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME)

all:
	$(CC) $(FLAGS) $(OPT) *.c -o $(NAME)

