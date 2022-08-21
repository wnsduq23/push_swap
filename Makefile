# Variable
NAME 		= push_swap
NAME_B		= checker
CC			= cc
CFLAG		= -Wall -Wextra -Werror -g
INC			= .
LIBFT 		= libft
ARC			= ar -rcs
DEL 		= rm -f

#Sources
#------mandatory------
SRC_FILES	= main \
			  init \
			  util \
			  cmd_reverse \
			  cmd_rreverse \
			  cmd_push \
			  cmd_swap \
			  sort sort_util \
			  sort_rotate sort_rotate_util \
			  array array_util \

SRCS 		= $(addsuffix .c, $(SRC_FILES))
OBJS 		= $(SRCS:%.c=%.o)
OBJ_MKDIR	= create_dir

#------BONUS------
# SRC_B_DIR	=src_b/
# OBJ_B_DIR	= obj_b/
# SRC_B_FILES	= checker \
#
# SRCS_B		= $(addprefix $(SRC_B_DIR), $(addsuffix .c, $$(SRC_B_FILES)))
# OBJS_B		= $(addprefix $(OBJ_B_DIR), $(addsuffix .o, $$(SRC_B_FILES)))

#Rules

# ifdef WITH_BONUS
#     TARGET = $(NAME_B)
# else
#     TARGET = $(NAME)
# endif

all : $(NAME)

$(NAME) : $(OBJS) 
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	$(CC) $(CFLAG) $(OBJS) libft.a -o $(NAME)
	@echo "-----------------push_swap compile finished-----------------"

# $(NAME_B) : $(OBJS_B)
#     $(ARC) $@ $(OBJS_B)
#     @echo "-----------------checker compile finished-----------------"

# bonus :
#     @make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(INC)
	@echo "Compiling....... \t$<"

clean :
	$(DEL) $(OBJS)
	@make clean -C $(LIBFT)
	@echo "push_swap obj files has been deleted------------------------"

fclean : clean
	$(DEL) $(NAME)
	$(DEL) $(OBJS)
	$(DEL) $(LIBFT)/libft.a
	$(DEL) libft.a
	@echo "push_swap archive files has been deleted--------------------" 

re : 
	make fclean
	make all

.PHONY : all clean fclean re
