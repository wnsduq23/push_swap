# Variable
NAME = push_swap

CC			= gcc
CFLAG		= -Wall -Wextra -Werror
INC			= include
SRC_DIR		= src/
OBJ_DIR 	= obj/
LIBFT 		= libft
SRCS 		= 
OBJS 		= S
DEL 		= rm -f
#Sources

#Rules

all : $(NAME)

$(NAME) : $(OBJS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c

clean : $(OBJS)
	$(DEL) -r $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean : clean
	$(DEL) 
re : 
