 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 21:26:09 by seokchoi          #+#    #+#              #
#    Updated: 2023/01/25 19:21:22 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= miniRT

INC_DIR			= -Iincludes -I$(LIBFT_DIR)/include -I$(MLX_DIR)
# CFLAGS			=  $(INC_DIR) -g3 -fsanitize=address -Wall -Wextra -Werror
CFLAGS			= -Wall -Wextra -Werror $(INC_DIR)
LDFLAGS			= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx
SRC_DIR			= src
MAIN_DIR		= $(SRC_DIR)/main/

# LIBRARY DIR
LIBFT_DIR		= $(SRC_DIR)/libft/
MLX_DIR			= $(SRC_DIR)/mlx/

# SRCS DIR
ERROR_DIR		= $(SRC_DIR)/error/
MATH_DIR		= $(SRC_DIR)/math/
PARSE_DIR		= $(SRC_DIR)/parse/
RENDER_DIR		= $(SRC_DIR)/render/
ROTATE_DIR		= $(SRC_DIR)/rotate/
WINDOW_DIR		= $(SRC_DIR)/window/

# NOTE : Add Source files here
ERROR_SRC		= error
MAIN_SRC		= main
MATH_SRC		= vector_dot_cross vector_op vector_op2 vector_op3 vector_op_2 absolute clamp compare_values normalize radian
PARSE_SRC		= ambient camera colors coordinate cylinder diameter init_info light normal objects parse_rt_file plane sphere utils utils2 cone check_option_count
RENDER_SRC		= raytracer hit ray check_ray_collision check_ray_collision_cylinder check_ray_collision_cone phong checker
ROTATE_SRC		= rotate rotate_init parallel_move rotate_minus
WINDOW_SRC		= color draw_image draw_xpm init_window init_xpm key_hook mouse_hook window_hooks print_terminal \
					move_camera move_camera_rotation move_light move_object move_object_rotation move_key init_thread

# NOTE : Add to SRC here
# ------------------------------------------------------ #
SRC =	$(addsuffix .c, $(addprefix $(ERROR_DIR),	$(ERROR_SRC)))	\
		$(addsuffix .c, $(addprefix $(MAIN_DIR),	$(MAIN_SRC)))	\
		$(addsuffix .c, $(addprefix $(MATH_DIR),	$(MATH_SRC)))	\
		$(addsuffix .c, $(addprefix $(PARSE_DIR),	$(PARSE_SRC)))	\
		$(addsuffix .c, $(addprefix $(RENDER_DIR),	$(RENDER_SRC)))	\
		$(addsuffix .c, $(addprefix $(ROTATE_DIR),	$(ROTATE_SRC)))	\
		$(addsuffix .c, $(addprefix $(WINDOW_DIR),	$(WINDOW_SRC)))	\
# ------------------------------------------------------ #

OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

bonus: $(NAME)

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
ORANGE = \033[38;5;208m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
CUSTOM = \033[38;5;135m

$(NAME): $(OBJ)
	@$(MAKE) -j -C $(LIBFT_DIR) bonus
	@$(MAKE) -C $(MLX_DIR) all
	@cp ./src/mlx/libmlx.dylib ./
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@
	@echo "$(CUSTOM)╔══════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(CUSTOM)║         miniRT compile finished.         ║$(DEF_COLOR)"
	@echo "$(CUSTOM)╠══════════════════════════════════════════╣$(DEF_COLOR)"
	@echo "$(CUSTOM)║                                          ║$(DEF_COLOR)"
	@echo "$(CUSTOM)║                        Have fun!         ║$(DEF_COLOR)"
	@echo "$(CUSTOM)╚══════════════════════════════════════════╝$(DEF_COLOR)"

$(OBJ): $(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CUSTOM)Compiling... \t$(word 1,$^) $(DEF_COLOR)"
# #-----------------------------------------------------------------------

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) -r $(OBJ_DIR)
	@echo "$(CUSTOM)miniRT obj files has been deleted.$(DEF_COLOR)"

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean
	@$(RM) libmlx.dylib
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(CUSTOM)miniRT archive files has been deleted.$(DEF_COLOR)"

re:	fclean
	$(MAKE) all
	@echo "$(CUSTOM)Cleaned and rebuilt miniRT.$(DEF_COLOR)"

norm:
	norminette $(LIBFT_DIR)/src $(LIBFT_DIR)/include $(ERROR_DIR) $(MAIN_DIR) $(MATH_DIR) $(PARSE_DIR) $(RENDER_DIR) $(ROTATE_DIR) $(WINDOW_DIR) ./includes $(LIBFT_DIR)/include

.PHONY: all clean fclean re norm
