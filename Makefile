# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-hach <zel-hach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 10:27:09 by bbrahim           #+#    #+#              #
#    Updated: 2022/12/01 13:38:41 by zel-hach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS = cub3D_bonus
CC = CC

define HEADER
 ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄        ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄  
▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░▌      ▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ 
▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌      ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌
▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌               ▐░▌▐░▌       ▐░▌
▐░▌          ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌      ▄▄▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌
▐░▌          ▐░▌       ▐░▌▐░░░░░░░░░░▌      ▐░░░░░░░░░░░▌▐░▌       ▐░▌
▐░▌          ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█░▌      ▀▀▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌
▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌               ▐░▌▐░▌       ▐░▌
▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌      ▄▄▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌
▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌      ▐░░░░░░░░░░░▌▐░░░░░░░░░░▌ 
 ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀        ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀  

endef
export HEADER

# ---------------------------------- Flags ----------------------------------- #
CFLAGS := -Wall -Wextra -Werror -fsanitize=address -static-libsan -Ofast -march=native -fno-signed-zeros -fno-trapping-math
MLX_EFLAGS := -lmlx -framework OpenGL -framework AppKit
MLX_OFLAGS := -Imlx
# ---------------------------------- libs ------------------------------------ #
LIBFT := libs/Libft/libft.a
MLX := libs/mlx/libmlx.a

# ----------------------------- M Source files -------------------------------- #
HEADERS := cub3d macros types
MANDATORY_HEADERS := $(addprefix mandatory/headers/, $(addsuffix .h, $(HEADERS)))

MAIN := mandatory/main.c

PARSSING := parssing read_map get_next_line chk_map chk_texture chk_color init_header init_body chk_body \
			parssing_utils
RAYCASING := raycasting init_data keyevent_hooking move_player \
			draw_wall ddl_algo background texture intersection_horizontal intersection_vertical \
			check_intersection utile_draw_wall check_wall pos_player

SRC := $(addprefix mandatory/src/parssing/, $(addsuffix .c, $(PARSSING))) \
		$(addprefix mandatory/src/raycasting/, $(addsuffix .c, $(RAYCASING)))

# -------------------------------- obj files ---------------------------------- #

# ----------------------------- B Source files -------------------------------- #
HEADERS_BONUS := $(addprefix bonus/headers/, $(addsuffix .h, $(HEADERS)))

MAIN_BONUS := bonus/main.c

PARSSING_BONUS := parssing read_map get_next_line chk_map chk_texture chk_color init_header init_body chk_body \
			parssing_utils
RAYCASING_BONUS := raycasting init_data keyevent_hooking mousevent_hooking move_player \
			draw_wall ddl_algo background texture intersection_horizontal intersection_vertical \
			update_window mini_map check_intersection utile_draw_wall  check_wall

SRC_BONUS := $(addprefix bonus/src/parssing/, $(addsuffix .c, $(PARSSING_BONUS))) \
		$(addprefix bonus/src/raycasting/, $(addsuffix .c, $(RAYCASING_BONUS)))

# -------------------------------- obj b files ---------------------------------- #

OBJ := $(SRC:.c=.o)

OBJ_BONUS := $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(NAME): print_header $(MAIN) $(MANDATORY_HEADERS) $(LIBFT) $(OBJ)
	@echo "Making mandatory dependencies, please wait ..."
	@$(CC) $(CFLAGS) $(MLX_EFLAGS) $(MAIN) $(LIBFT) $(OBJ) -o $(NAME) 
	@echo "${NAME}: Compiled successfully 👍👍"
	
$(BONUS): print_header $(MAIN_BONUS) $(HEADERS_BONUS) $(LIBFT) $(OBJ_BONUS)
	@echo "Making bonus dependencies, please wait ..."
	@$(CC) $(CFLAGS) $(MLX_EFLAGS) $(MAIN_BONUS) $(LIBFT) $(OBJ_BONUS) -o $(BONUS)
	@echo "${BONUS}: Compiled successfully 👍👍"

print_header:
	@echo "\033[0;35m $$HEADER \033[0;30m"

%.o: %.c $(MANDATORY_HEADERS) $(HEADERS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(MLX_OFLAGS) -c $< -o $@

$(LIBFT): $(shell find libs/libft -name "*.c" -type f)
	@$(MAKE) -C libs/libft
	@$(MAKE) bonus -C libs/libft

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@echo "\033[0;30m"
	@$(MAKE) -C libs/mlx/ clean
	@$(MAKE) -C libs/libft/ clean
	@echo "\033[0;30m delete successfully \033[0;30m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@$(MAKE) -C libs/libft/ fclean

re: fclean all

norm:
	@norminette $(MAIN)
	@norminette $(SRC)
	@norminette $(MANDATORY_HEADERS)
	@norminette $(MAIN_BONUS)
	@norminette $(SRC_BONUS)
	@norminette $(HEADERS_BONUS)

.PHONY: all clean fclean re norm