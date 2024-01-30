CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = list

all:
	@$(CC) *.c -o $(NAME)

.PHONY: all
