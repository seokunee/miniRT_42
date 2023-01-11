# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 21:26:09 by chanwjeo          #+#    #+#              #
#    Updated: 2023/01/11 09:53:58 by chanwjeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= miniRT
CC				= cc

# CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS			= -Wall -Wextra -Werror
INCLUDE			= includes

# NOTE : Add Source directory here
# ------------------------------------------------------ #
SRC_DIR			= src
MAIN_DIR		= $(SRC_DIR)/main/
PARSE_DIR		= $(SRC_DIR)/parse/

LIBFT_DIR		= $(SRC_DIR)/libft/
MLX_DIR			= $(SRC_DIR)/mlx/

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

PARSE_SRC		= init_info

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
		$(addsuffix .c, $(addprefix $(PARSE_DIR), $(PARSE_SRC))) \
	#   $(addsuffix .c, $(addprefix $(LEXER_DIR), $(LEXER_SRC))) \
	#   $(addsuffix .c, $(addprefix $(EXECUTER_DIR), $(EXECUTER_SRC))) \
	#   $(addsuffix .c, $(addprefix $(BUILTIN_DIR), $(BUILTIN_SRC))) \
	#   $(addsuffix .c, $(addprefix $(STRING_DIR), $(STRING_SRC))) \
	#   $(addsuffix .c, $(addprefix $(ITERATOR_DIR), $(ITERATOR_SRC)))

# ------------------------------------------------------ #

OBJ_DIR = obj/
OBJ = $(SRC:c=o)

all: $(NAME)

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
	@mkdir -p $(OBJ_DIR)
	@make bonus -C $(LIBFT_DIR)
	@make -C $(MLX_DIR) all
	@cp ./src/mlx/libmlx.dylib ./
	@$(CC) $(CFLAGS) $(LIBFT_DIR)libft.a -L. -lmlx $(OBJ) -o $(NAME)
	@mv $(OBJ) $(OBJ_DIR)
	@echo "$(CUSTOM)╔══════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(CUSTOM)║         miniRT compile finished.         ║$(DEF_COLOR)"
	@echo "$(CUSTOM)╠══════════════════════════════════════════╣$(DEF_COLOR)"
	@echo "$(CUSTOM)║                                          ║$(DEF_COLOR)"
	@echo "$(CUSTOM)║                        Have fun!         ║$(DEF_COLOR)"
	@echo "$(CUSTOM)╚══════════════════════════════════════════╝$(DEF_COLOR)"

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "$(CUSTOM)Compiling... \t$< $(DEF_COLOR)"
# #-----------------------------------------------------------------------

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -f libmlx.dylib
	@rm -rf $(OBJ_DIR)
	@echo "$(CUSTOM)miniRT obj files has been deleted.$(DEF_COLOR)"

fclean:
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -f libmlx.dylib
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "$(CUSTOM)miniRT archive files has been deleted.$(DEF_COLOR)"

re: fclean all
	@echo "$(CUSTOM)Cleaned and rebuilt miniRT.$(DEF_COLOR)"

.PHONY: all clean fclean re
