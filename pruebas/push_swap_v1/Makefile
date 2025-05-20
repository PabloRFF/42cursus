NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c init.c operations.c operations_b.c turc_alg.c utils.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	cd libft && $(MAKE)
	$(CC) $(CFLAGS) $(OBJ)  -L ./libft -lft -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	cd libft && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re