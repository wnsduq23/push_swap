# Variable
NAME_M 		= push_swap
NAME_B		= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
INC			= .
LIBFT 		= libft
ARC			= ar -rcs
DEL 		= rm -f

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources
#------mandatory------
SRC_M_FILES	= main \
			  init \
			  util \
			  cmd_reverse \
			  cmd_rreverse \
			  cmd_push \
			  cmd_swap \
			  sort sort_util \
			  sort_rotate sort_rotate_util \
			  array array_util \

SRCS 		= $(addsuffix .c, $(SRC_M_FILES))
OBJS 		= $(SRCS:%.c=%.o)
OBJ_MKDIR	= create_dir

#------BONUS------
SRC_B_FILES	= checker_bonus \
			  init \
			  util \
			  array array_util \
			  cmd_swap_bonus \
			  cmd_push_bonus \
			  cmd_rr_bonus \
			  cmd_r_bonus \
			  sort_rotate_bonus sort_rotate_util \
			  sort_util_bonus
			  
SRCS_B		= $(addsuffix .c, $(SRC_B_FILES))
OBJS_B		= $(SRCS_B:%.c=%.o)

#Rules

ifdef BONUS
	NAME		= $(NAME_B)
	OBJ_RESULT	= $(OBJS_B)
else
	NAME = $(NAME_M)
	OBJ_RESULT	= $(OBJS)
endif

all : $(NAME)

$(NAME): $(OBJ_RESULT)
	@make bonus -C $(LIBFT)
	@mv $(LIBFT)/libft.a .
	@$(CC) $(CFLAGS) $^ libft.a -o $@
ifdef BONUS
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
	@echo "$(YELLOW)|      Push_Swap bonus compile finished.      |$(DEF_COLOR)"
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
else
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
	@echo "$(YELLOW)|    Push_Swap mandatory compile finished.    |$(DEF_COLOR)"
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
endif

bonus :
	@make BONUS=1

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(INC)
	@echo "Compiling....... \t$<"

clean :
	$(DEL) libft.a
	$(DEL) $(OBJS) $(OBJS_B)
	@make fclean -C $(LIBFT)
	@echo "push_swap obj files has been deleted------------------------"

fclean : clean
	$(DEL) $(NAME_M)
	$(DEL) $(NAME_B)

	@echo "push_swap archive files has been deleted--------------------" 

re : 
	make fclean
	make all

.PHONY : all clean fclean re
