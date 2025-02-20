CC = gcc
FLAGS = -Wall -Werror -Wextra
OPT = -O3
NAME = list
PROGRAM_FLAGS =
SRC_DIR = ./src/
INC_DIR = ./include/
SRC = $(SRC_DIR)*.c
INC = -I$(INC_DIR)
DEFINES = -D ICON_PATH='"//usr//local//share//list//icons.txt" -D LOG_PATH='"//usr//local//share//list//changes.txt"'
UNIC = ./UniC/unic.a -I./UniC/

all: uniC
	$(CC) $(FLAGS) $(INC) $(OPT) $(SRC) -o $(NAME) $(UNIC)

uniC:
	make -C UniC

install_no_root: uniC
	$(CC) $(FLAGS) $(INC) $(OPT) $(SRC) -o $(NAME) $(UNIC) $(DEFINES)

install: uniC
	$(CC) $(FLAGS) $(INC) $(OPT) $(SRC) -o $(NAME) $(UNIC) $(DEFINES)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) $(PROGRAM_FLAGS)

clean:
	cd UniC && make clean
	rm -f $(NAME)

re: clean all

.PHONY: clean re install valgrind all uniC
