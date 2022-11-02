# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 10:27:09 by bbrahim           #+#    #+#              #
#    Updated: 2022/11/02 13:08:49 by bbrahim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = CC

# ---------------------------------- Flags ----------------------------------- #
CFLAGS := -Wall -Wextra -Werror -fsanitize=address -static-libsan
MLX_EFLAGS := -lmlx -framework OpenGL -framework AppKit
MLX_OFLAGS := -Imlx

# ---------------------------------- libs ------------------------------------ #
LIBFT := libs/Libft/libft.a
MLX := libs/mlx/libmlx.a

# ----------------------------- M Source files -------------------------------- #
HEADERS := cub3d macros types
MANDATORY_HEADERS := $(addprefix mandatory/headers/, $(addsuffix .h, $(HEADERS)))

MAIN := mandatory/main.c

PARSSING := parssing read_map chk_map
RAYCASING := raycasting

SRC := $(addprefix mandatory/src/parssing/, $(addsuffix .c, $(PARSSING))) \
		$(addprefix mandatory/src/raycasting/, $(addsuffix .c, $(RAYCASING)))

# -------------------------------- obj files ---------------------------------- #
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MAIN) $(MANDATORY_HEADERS) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(MLX_EFLAGS) $(MAIN) $(LIBFT) $(OBJ) -o $(NAME)

%.o: $(SRC)/%.c $(MANDATORY_HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_OFLAGS) -c $< -o $@

$(LIBFT): $(shell find libs/libft -name "*.c" -type f)
	@$(MAKE) -C libs/libft

clean:
	rm -f $(OBJ)
	$(MAKE) -C libs/mlx/ clean
	$(MAKE) -C libs/libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libs/libft/ fclean

re: fclean all

norm:
	@norminette $(MAIN)
	@norminette $(SRC)
	@norminette $(MANDATORY_HEADERS)

.PHONY: all clean fclean re norm