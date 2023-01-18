# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 21:26:09 by chanwjeo          #+#    #+#              #
#    Updated: 2023/01/18 20:14:53 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= miniRT

INC_DIR			= -Iincludes -I$(LIBFT_DIR)/include -I$(MLX_DIR)
CFLAGS			= -Wall -Wextra -Werror $(INC_DIR) -g3 -fsanitize=address
# CFLAGS			= -Wall -Wextra -Werror $(INC_DIR)
LDFLAGS			= -L$(LIBFT_DIR) -lft -L. -lmlx

# NOTE : Add Source directory here
# ------------------------------------------------------ #
SRC_DIR			= src

ifeq (,$(findstring test,$(MAKECMDGOALS)))
MAIN_DIR		= $(SRC_DIR)/main/
else
MAIN_DIR		= $(SRC_DIR)/test/
endif

PARSE_DIR		= $(SRC_DIR)/parse/
LIBFT_DIR		= $(SRC_DIR)/libft/
MLX_DIR			= $(SRC_DIR)/mlx/
MATH_DIR		= $(SRC_DIR)/math/

TEST_DIR		= $(SRC_DIR)/test/
MEMORY_DIR		= $(SRC_DIR)/memory/
ERROR_DIR		= $(SRC_DIR)/error/
WINDOW_DIR		= $(SRC_DIR)/window/
RENDER_DIR		= $(SRC_DIR)/render/

# STRING_DIR		= $(SRC_DIR)/string/
# ITERATOR_DIR	= $(SRC_DIR)/iterator/
# LEXER_DIR		= $(SRC_DIR)/lexer/
# EXECUTER_DIR	= $(SRC_DIR)/executer/
# BUILTIN_DIR		= $(SRC_DIR)/builtin/

# Use MLX library
# MLX				= -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# NOTE : Add Source files here
# ------------------------------------------------------ #
MAIN_SRC		= main

PARSE_SRC		= ambient camera colors coordinate cylinder diameter init_info light\
					normal objects parse_rt_file plane sphere utils utils2
MATH_SRC		= vector_dot_cross vector_op absolute clamp compare_values normalize radian
ERROR_SRC		= error
WINDOW_SRC		= init_window key_hook mouse_hook window_hooks

MEMORY_SRC		= free_raytracer free_vector

RENDER_SRC		= camera_set material

# LEXER_SRC		= token_create token_modify \
# 				  scanner_main scanner_create scanner_function_ptr \
# 				  scanner_helper scanner_helper2 scanner_get_token_1 scanner_get_token_2

# EXECUTER_SRC	= executer token_expand token_expand_utils get_full_path subshell \
# 				  redirection redirection_utils exec_command exec_command_utils \
# 				  token_expand_wildcard_main token_expand_wildcard_pattern \
# 				  token_expand_wildcard_helper token_expand_wildcard_helper2

# BUILTIN_SRC		= environ environ_utils environ_helper environ_helper2 cd echo pwd exit

# STRING_SRC		= string_create string_modify string_modify2 string_utils

# ITERATOR_SRC	= iterator_create iterator_modify

# NOTE : Add to SRC here
# ------------------------------------------------------ #
SRC =	$(addsuffix .c, $(addprefix $(MAIN_DIR), $(MAIN_SRC))) \
		$(addsuffix .c, $(addprefix $(MATH_DIR), $(MATH_SRC))) \
		$(addsuffix .c, $(addprefix $(ERROR_DIR), $(ERROR_SRC))) \
		$(addsuffix .c, $(addprefix $(WINDOW_DIR), $(WINDOW_SRC))) \
		$(addsuffix .c, $(addprefix $(RENDER_DIR), $(RENDER_SRC))) \
		$(addsuffix .c, $(addprefix $(PARSE_DIR), $(PARSE_SRC))) \
	#   $(addsuffix .c, $(addprefix $(EXECUTER_DIR), $(EXECUTER_SRC))) \
	#   $(addsuffix .c, $(addprefix $(BUILTIN_DIR), $(BUILTIN_SRC))) \
	#   $(addsuffix .c, $(addprefix $(STRING_DIR), $(STRING_SRC))) \
	#   $(addsuffix .c, $(addprefix $(ITERATOR_DIR), $(ITERATOR_SRC)))
# ------------------------------------------------------ #

OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

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
	@$(MAKE) -C $(LIBFT_DIR) bonus
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
	@echo "$(CUSTOM)Compiling... \t$< $(DEF_COLOR)"
# #-----------------------------------------------------------------------

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) libmlx.dylib
	@$(RM) -r $(OBJ_DIR)
	@echo "$(CUSTOM)miniRT obj files has been deleted.$(DEF_COLOR)"

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@$(RM) libmlx.dylib
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(CUSTOM)miniRT archive files has been deleted.$(DEF_COLOR)"

re: fclean all
	@echo "$(CUSTOM)Cleaned and rebuilt miniRT.$(DEF_COLOR)"

.PHONY: all clean fclean re
