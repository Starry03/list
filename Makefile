CC = gcc
FLAGS = -Wall -Werror -Wextra
OPT = -O2
NAME = list

all:
	$(CC) $(FLAGS) $(OPT) *.c -o $(NAME)

