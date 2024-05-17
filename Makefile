CC = gcc
FLAGS = -Wall -Werror -Wextra
OPT = -O3
NAME = list
PROGRAM_FLAGS =

UNIC = ./UniC/UniC.a -I./UniC

all:
	cd UniC && make re
	$(CC) $(FLAGS) $(OPT) *.c -o $(NAME) $(UNIC)

install:
	cd UniC && make re
	$(CC) $(FLAGS) $(OPT) *.c -o $(NAME) $(UNIC) -D ICON_PATH='"//usr//local//share//list//icons.txt"'

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) $(PROGRAM_FLAGS)

clean:
	cd UniC && make clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean re install valgrind all
