CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = list

all:
	@$(CC) *.c -g -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME)


.PHONY: all
