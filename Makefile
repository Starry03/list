CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = list

all:
	$(CC) $(FLAGS) *.c -g -o $(NAME)

