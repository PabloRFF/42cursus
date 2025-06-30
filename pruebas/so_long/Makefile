# **************************************************************************** #
#                                MAKEFILE                                      #
# **************************************************************************** #

NAME = so_long

# ------------------------------
# Directories & Files
# ------------------------------

SRC_DIRS = . game map render events utils
SRCS = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJS = $(patsubst %.c,%.o,$(SRCS))

INC_DIRS = . game map render events utils libft

# ------------------------------
# Libft
# ------------------------------

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# ------------------------------
# Compiler & Flags
# ------------------------------

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror $(addprefix -I, $(INC_DIRS))
MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# ------------------------------
# Rules
# ------------------------------

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

# ------------------------------
# Phony
# ------------------------------

.PHONY: all clean fclean re
