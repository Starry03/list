CC = gcc
FLAGS = -Wall -Werror -Wextra
OPT = -O2
NAME = list
PROGRAM_FLAGS = -a -R -d -V

all:
	$(CC) $(FLAGS) $(OPT) *.c -o $(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) $(PROGRAM_FLAGS)
