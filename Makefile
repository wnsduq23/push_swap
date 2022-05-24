# Variable
NAME = push_swap

CC			= cc
CFLAG		= -Wall -Wextra -Werror
INC			= include
LIBFT 		= libft
ARC			= ar -rcs
DEL 		= rm -f

#Sources
SRC_DIR		= src/
OBJ_DIR 	= obj/
SRC_FILES	= main \
			  init free \
			  push_swap \
			  util util_stack
SRCS 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES))) 
OBJS 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES))) 
MAKE_OBJ_DIR	= create_dir

#Rules

all : $(NAME)

$(NAME) : $(OBJS) 
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	$(ARC) $@ $(OBJS) 
	@echo "-----------------push_swap compile finished-----------------"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(MAKE_OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@ -I $(INC)
	@echo "Compiling....... \t$<"

$(MAKE_OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

clean :
	$(DEL) -r $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@echo "push_swap obj files has been deleted------------------------"

fclean : clean
	$(DEL) $(NAME)
	$(DEL) $(LIBFT)/libft.a
	@echo "push_swap archive files has been deleted--------------------" 

re : 
	make fclean
	make all

.PHONY : all clean fclean re
