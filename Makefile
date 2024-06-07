CC = gcc
FLAGS = -Wall -Werror -Wextra
OPT = -O3
NAME = list
PROGRAM_FLAGS =
SRC = $(wildcard *.c)

UNIC = ./UniC/UniC.a -I./UniC

all:
	$(CC) $(FLAGS) $(OPT) $(SRC) -o $(NAME) $(UNIC)

uniC:
	cd UniC && make re

install: uniC
	$(CC) $(FLAGS) $(OPT) $(SRC) -o $(NAME) $(UNIC) -D ICON_PATH='"//usr//local//share//list//icons.txt"'

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) $(PROGRAM_FLAGS)

clean:
	cd UniC && make clean
	rm -f $(NAME)

re: clean all

.PHONY: clean re install valgrind all uniC
