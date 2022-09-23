NAME		= minishell

CC 			= gcc
FLAGS 		= -Wall -Werror -Wextra

LIBC		= ar rc
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
HEADERS 	= ./include/minishell.h
INCS		= -I ./include/


LIB_DIR		= lib
LIBFT_A		= ./lib/libft.a
READLINE =  -L/usr/include -lreadline


GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
END_COLOR	= \033[0;39m

SRC_FILES	= main.c
OBJ_FILES	= ${SRC_FILES:.c=.o}
SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))


all	: $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJ)
	echo "$(GREEN)make $(LIB_DIR)$(END_COLOR)"
	@make -C $(LIB_DIR) 
#	@$(CC) $(OBJ) $(LIBFT_A) -o $(NAME)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT_A) -o $(NAME) $(READLINE)
	@echo "$(GREEN)$(NAME) compiled$(END_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
#	@$(CC) -c $< -o $@ $(INCS)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCS)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean	:
		@rm -rf $(OBJ)
		@make clean -C $(LIB_DIR)
		@echo "$(YELLOW)$(NAME) clean$(END_COLOR)"
fclean	:	clean
		@rm -rf $(NAME)
		@rm -rf $(LIBFT_A)
		@rm -rf $(OBJ_DIR)
		@echo "$(YELLOW)$(NAME) fclean$(END_COLOR)"
re	:	fclean all

.PHONY	:	all clean fclean re