# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seheo <seheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 11:09:58 by seheo             #+#    #+#              #
#    Updated: 2022/10/01 14:58:18 by seheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMMANDS & FLAGS
CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
INCLUDE_FLAGS = -I ./include/ -I $(LIBFT_PATH)include/
L_FLAGS = -lreadline
READLINE = -L /Users/$(USER)/.brew/opt/readline/lib
READLINE_INC = -I /Users/$(USER)/.brew/opt/readline/include
RM = rm -f

# EXECUTABLE
NAME = ./minishell
LIBFT_NAME = $(LIBFT_PATH)/libft.a

# PATHS
SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIBFT_PATH = ./lib/
BRAIN_PATH = $(SRC_PATH)brain/
LEXER_UTILS_PATH = $(BRAIN_PATH)utils/lexer_utils/
BRAIN_GETTER_SETTER_PATH = $(BRAIN_PATH)utils/getter_setter/
PARSER_UTILS_PATH = $(BRAIN_PATH)utils/parser_utils/
EXPANDER_UTILS_PATH = $(BRAIN_PATH)utils/expander_utils/

# FILES
SRC = $(SRC_PATH)main.c \
		$(SRC_PATH)util/signal_handler.c $(SRC_PATH)util/error_util.c
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))
LIBFT_SRC = $(LIBFT_PATH)*.c

# COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

# @$(CC) $(CC_FLAGS) $(INCLUDE_FLAGS) $(L_FLAGS) $(LIBFT_NAME) $(OBJ) -o $(NAME)
$(NAME): $(OBJ) $(LIBFT_NAME)
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(OBJ) $(READLINE) $(READLINE_INC) $(CC_FLAGS) $(LIBFT_PATH)/libft.a $(L_FLAGS) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

$(LIBFT_NAME): $(LIBFT_SRC)
	@make -C $(LIBFT_PATH) all

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) $(READLINE_INC) $(INCLUDE_FLAGS) -o $@ -c $<
	@printf $(UP)$(CUT)
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

clean:
	@make -C $(LIBFT_PATH) clean
	@if [ -d "$(OBJ_PATH)" ]; then \
		$(RM) -r $(OBJ_PATH); \
		echo $(R)Cleaning" "[$(OBJ_PATH)]...$(X); \
	fi;

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@if [ -f "$(NAME)" ]; then \
		$(RM) $(NAME); \
		echo $(R)Cleaning" "[$(NAME)]...$(X); \
	fi;

re: fclean all

# TESTING RULES
norm:
	@echo $(G)Checking Norminette...$(X)
	norminette | grep Error | egrep --color '.*Error!|$$'
	@echo $(G)Done$(X)

run: all
	$(NAME)


.PHONY: all, clean, fclean, re, norm
