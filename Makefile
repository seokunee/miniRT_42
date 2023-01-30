 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 21:26:09 by chanwjeo          #+#    #+#              #
#    Updated: 2023/01/25 19:21:22 by sunhwang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= miniRT

INC_DIR			= -Iincludes -I$(LIBFT_DIR)/include -I$(MLX_DIR)
CFLAGS			= -Wall -Wextra -Werror $(INC_DIR) #-g3 -fsanitize=address
# CFLAGS			= -Wall -Wextra -Werror $(INC_DIR)
LDFLAGS			= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx
# LDFLAGS			= -L$(LIBFT_DIR) -lft -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
SRC_DIR			= src

ifeq (,$(findstring test,$(MAKECMDGOALS)))
MAIN_DIR		= $(SRC_DIR)/main/
else
MAIN_DIR		= $(SRC_DIR)/test/
endif

# LIBRARY DIR
LIBFT_DIR		= $(SRC_DIR)/libft/
MLX_DIR			= $(SRC_DIR)/mlx/

# SRCS DIR
PARSE_DIR		= $(SRC_DIR)/parse/
MATH_DIR		= $(SRC_DIR)/math/
MEMORY_DIR		= $(SRC_DIR)/memory/
ERROR_DIR		= $(SRC_DIR)/error/
WINDOW_DIR		= $(SRC_DIR)/window/
RENDER_DIR		= $(SRC_DIR)/render/
THREAD_DIR		= $(SRC_DIR)/thread/

# Use MLX library
# MLX				= -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# NOTE : Add Source files here
MAIN_SRC		= main
PARSE_SRC		= ambient camera colors coordinate cylinder diameter init_info light normal objects parse_rt_file plane sphere utils utils2
MATH_SRC		= vector_dot_cross vector_op vector_op2 vector_op3 vector_op_2 absolute clamp compare_values normalize radian
MEMORY_SRC		= free_raytracer free_vector
ERROR_SRC		= error
WINDOW_SRC		= color draw_image init_window key_hook mouse_hook window_hooks
RENDER_SRC		= raytracer hit ray check_ray_collision check_ray_collision_cylinder #render sphere
THREAD_SRC		= init_thread

# BONUS SRC
ifeq (,$(findstring bonus,$(MAKECMDGOALS)))
THREAD_SRC		= init_thread
else
THREAD_SRC		= init_thread_bonus
endif

# NOTE : Add to SRC here
# ------------------------------------------------------ #
SRC =	$(addsuffix .c, $(addprefix $(MAIN_DIR),	$(MAIN_SRC)))	\
		$(addsuffix .c, $(addprefix $(MATH_DIR),	$(MATH_SRC)))	\
		$(addsuffix .c, $(addprefix $(ERROR_DIR),	$(ERROR_SRC)))	\
		$(addsuffix .c, $(addprefix $(WINDOW_DIR),	$(WINDOW_SRC)))	\
		$(addsuffix .c, $(addprefix $(PARSE_DIR),	$(PARSE_SRC)))	\
		$(addsuffix .c, $(addprefix $(THREAD_DIR),	$(THREAD_SRC)))	\
		$(addsuffix .c, $(addprefix $(RENDER_DIR),	$(RENDER_SRC)))	\
# ------------------------------------------------------ #

OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

bonus: $(NAME)

test: $(NAME)

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

#---------------------------------------------------------------------------
#    Macbook compile option  (not include MLX)                             |
#---------------------------------------------------------------------------
# $(NAME): $(OBJ)
# 	@make bonus -C $(LIBFT_DIR)
# 	@$(CC) $(CFLAGS) $(LIBFT_DIR)libft.a $(OBJ) -o $(NAME)
# 	@echo "$(CUSTOM)╔══════════════════════════════════════════╗$(DEF_COLOR)"
# 	@echo "$(CUSTOM)║         miniRT compile finished.         ║$(DEF_COLOR)"
# 	@echo "$(CUSTOM)╠══════════════════════════════════════════╣$(DEF_COLOR)"
# 	@echo "$(CUSTOM)║                                          ║$(DEF_COLOR)"
# 	@echo "$(CUSTOM)║                        Have fun!         ║$(DEF_COLOR)"
# 	@echo "$(CUSTOM)╚══════════════════════════════════════════╝$(DEF_COLOR)"

#-----------------------------------------------------------------------
#    Mac compile option                                                |
#-----------------------------------------------------------------------
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
	norminette $(PARSE_DIR) $(MATH_DIR) $(MEMORY_DIR) $(ERROR_DIR) \
	$(WINDOW_DIR) $(RENDER_DIR) $(THREAD_DIR)

.PHONY: all clean fclean re
