# Variable
NAME 		= push_swap
NAME_B		= checker
CC			= cc
CFLAG		= -Wall -Wextra -Werror
INC			= include
LIBFT 		= libft
ARC			= ar -rcs
DEL 		= rm -f

#Sources
#------mandatory------
SRC_DIR		= src/
OBJ_DIR 	= obj/
SRC_FILES	= main \
			  init free \
			  push_swap \
			  util util_stack
SRCS 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES))) 
OBJS 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES))) 
OBJ_MKDIR	= create_dir

#------BONUS------
SRC_B_DIR	=src_b/
OBJ_B_DIR	= obj_b/
SRC_B_FILES	= checker \

SRCS_B		= $(addprefix $(SRC_B_DIR), $(addsuffix .c, $$(SRC_B_FILES)))
OBJS_B		= $(addprefix $(OBJ_B_DIR), $(addsuffix .o, $$(SRC_B_FILES)))

#Rules

ifdef WITH_BONUS
	TARGET = $(NAME_B)
else
	TARGET = $(NAME)
endif

all : $(TARGET)

$(NAME) : $(OBJS) 
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@mv libft.a $(NAME)
	$(ARC) $@ $(OBJS) 
	@echo "-----------------push_swap compile finished-----------------"

$(NAME_B) : $(OBJS_B)
	$(ARC) $@ $(OBJS_B)
	@echo "-----------------checker compile finished-----------------"

bonus :
	@make WITH_BONUS=1 all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_MKDIR)
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
