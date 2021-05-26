

NAME_C	= checker
NAME_P	= push_swap


CC_FLAGS		= gcc -Wall -Wextra -Werror

DIR_SRC_PS	= src_ps
DIR_SRC_CH	= src_ch
DIR_LIB	= libft
DIR_H	= includes
LIB		= $(addprefix $(DIR_LIB)/, libft.a)

SOURCES_PS	= push_swap.c parse.c move.c filter.c solve.c scout.c\
		  struct_free.c struct_init.c struct_modify.c utils1.c utils2.c
SOURCES_CH	= checker.c parse.c move.c\
		  struct_free.c struct_init.c struct_modify.c utils1.c utils2.c

SRC_PS	= $(addprefix $(DIR_SRC_PS)/, $(SOURCES_PS))
SRC_CH	= $(addprefix $(DIR_SRC_CH)/, $(SOURCES_CH))

OBJ_PS	= $(SRC_PS:.c=.o)
OBJ_CH	= $(SRC_CH:.c=.o)

all:	$(NAME_P) $(NAME_C)

$(LIB):
	@- make -sC $(DIR_LIB)

$(OBJ_PS):	%.o: %.c
	@$(CC_FLAGS) -c -I $(DIR_H) $< -o $@

$(OBJ_CH):	%.o: %.c
	@$(CC_FLAGS) -c -I $(DIR_H) $< -o $@

$(NAME_P):	$(LIB) $(OBJ_PS)
	@$(CC_FLAGS) $(OBJ_PS) $(LIB) -o $(NAME_P)
	@echo "push_swap done"

$(NAME_C):	$(LIB) $(OBJ_CH)
	@$(CC_FLAGS) $(OBJ_CH) $(LIB) -o $(NAME_C)
	@echo "checker done"

clean:
	@make -sC $(DIR_LIB) clean
	@rm -f $(OBJ_CH)
	@rm -f $(OBJ_PS)

fclean:	clean
	@make -sC $(DIR_LIB) fclean
	@rm -f $(NAME_P)
	@rm -f $(NAME_C)

re:		fclean all

.PHONY:	all clean fclean re
