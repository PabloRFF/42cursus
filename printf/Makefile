CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I.
SRC = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putnbr.c ft_putnbr_u.c ft_putstr.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) main.o

fclean: clean
	rm -f $(NAME) tester

re: fclean all