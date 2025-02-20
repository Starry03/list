DIRS := algebra algorithms datastructures libft utils
SRCS := $(shell find $(DIRS) -name '*.c')
OBJS := $(SRCS:.c=.o)
LIB := unic.a
CC := gcc
CFLAGS := -I. -Wall -Wextra -Werror
LINK := -lm
UniC := ./$(LIB)

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(LINK) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(LIB)

re: fclean all

valgrind:
	$(CC) $(CFLAGS) main.c $(UniC) -o main && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main

# examples
EXAMPLES_SRC = examplegraph.c
graphdraw:
	$(CC) $(CFLAGS) examples/$(EXAMPLES_SRC) examples/graphdraw.c $(UniC) -o examples/graphdraw && examples/graphdraw

.PHONY: all clean fclean re valgrind graphdraw
