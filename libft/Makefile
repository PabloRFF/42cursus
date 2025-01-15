CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME = libft.a

$(NAME): $(OBJ)
    ar rcs $(NAME) $(OBJ)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
all: $(NAME)
