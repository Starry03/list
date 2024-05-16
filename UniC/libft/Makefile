CC = gcc
FLAGS = -Wall -Wextra -Werror
CFILES = ft_atoi.c ft_isalpha.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c ft_bzero.c ft_isascii.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c ft_isprint.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_itoa.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_isalnum.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c
OFILES = $(CFILES:.c=.o)
BONUS_CFILES = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c 
BONUS_OFILES = $(BONUS_CFILES:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $^
	ranlib $(NAME)

$(OFILES): %.o: %.c
	$(CC) -c -I. $(FLAGS) -o $@ $< 

clean:
	rm -f $(OFILES) $(BONUS_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OFILES)
	ar rcs $(NAME) $^
	ranlib $(NAME)

$(BONUS_OFILES): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus
