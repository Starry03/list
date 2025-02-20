CC = gcc
FLAGS = -Wall -Werror -Wextra
OPT = -O3
NAME = list
PROGRAM_FLAGS =
SRC_DIR = ./src/
INC_DIR = ./include/
SRC = $(SRC_DIR)*.c
INC = -I$(INC_DIR)

UNIC = ./UniC/unic.a -I./UniC/

all: uniC
	$(CC) $(FLAGS) $(INC) $(OPT) $(SRC) -o $(NAME) $(UNIC)

uniC:
	make -C UniC

install42:
	$(CC) $(FLAGS) $(INC) $(OPT) $(SRC) -o $(NAME) $(UNIC) -D ICON_PATH='"//nfs//homes//astarran//Desktop//list//icons.txt"'

install: uniC
	$(CC) $(FLAGS) $(INC) $(OPT) $(SRC) -o $(NAME) $(UNIC) -D ICON_PATH='"//usr//local//share//list//icons.txt"'

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) $(PROGRAM_FLAGS)

clean:
	cd UniC && make clean
	rm -f $(NAME)

re: clean all

.PHONY: clean re install valgrind all uniC
