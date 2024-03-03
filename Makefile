CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = list

build:
	@$(CC) *.c -g -o $(NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME)

all:
	@make build
	@make valgrind

.PHONY: all build valgrind
