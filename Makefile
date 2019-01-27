NAME_CHECK = checker
NAME_SWAP = push_swap



CHECKER		=	checker
PUSH_SWAP	=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g #-fsanitize=address

_C_SRCS		= checker_src/ps_00_checker_main.c \
			  checker_src/ps_01_parse_and_init.c \
			  checker_src/ps_02_struct_tools.c \
			  checker_src/ps_02bis_struct_tools.c \
			  checker_src/ps_03_instructions.c \
			  checker_src/ps_04_calcul.c \
			  checker_src/ps_04bis_calcul.c \
			  checker_src/ps_04ter_calcul.c \
			  checker_src/ps_0x_debug.c \
			  checker_src/ps_0x_checker_utils.c

_PS_SRCS	= push_swap_src/ps_00_push_swap_main.c \
			  push_swap_src/ps_01_parse_and_init.c \
			  push_swap_src/ps_02_struct_tools.c \
			  push_swap_src/ps_02bis_struct_tools.c \
			  push_swap_src/ps_03_resolve.c \
			  push_swap_src/ps_03a_resolve_small.c \
			  push_swap_src/ps_03b_resolve_medium.c \
			  push_swap_src/ps_03c_resolve_recursive.c \
			  push_swap_src/ps_03d_resolve_actualize.c \
			  push_swap_src/ps_03d_sesolve_actualize.c \
			  push_swap_src/ps_03e_resolve_recurs_tools.c \
			  push_swap_src/ps_03f_resolve_tools.c \
			  push_swap_src/ps_03g_resolve_tools2.c \
			  push_swap_src/ps_03h_resolve_big.c \
			  push_swap_src/ps_04_calcul.c \
			  push_swap_src/ps_04bis_calcul.c \
			  push_swap_src/ps_04ter_calcul.c \
			  push_swap_src/ps_04quatro_calcul.c \
			  push_swap_src/ps_0x_debug.c \
			  push_swap_src/ps_0x_checker_utils.c

_LIBFT		=	libft.a

SRCS_DIR	=	sources
LIB_DIR		=	libft
PS_SRCS		=	$(addprefix $(SRCS_DIR)/, $(_PS_SRCS))
C_SRCS		=	$(addprefix	$(SRCS_DIR)/, $(_C_SRCS))
LIBFT		=	$(addprefix $(LIB_DIR), $(_LIBFT))

C_OBJS		=	$(C_SRCS:.c=.o)
PS_OBJS		=	$(PS_SRCS:.c=.o)

all:	$(CHECKER) $(PUSH_SWAP) $(LIBFT)

$(CHECKER) : $(C_OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(C_OBJS) -L$(LIB_DIR) -lft
	@echo "$(CHECKER) : $(_GREEN)Done$(_END)"

$(PUSH_SWAP): $(PS_OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(PS_OBJS) -L$(LIB_DIR) -lft
	@echo "$(PUSH_SWAP) : $(_GREEN)Done$(_END)"

$(LIBFT):
	@make -C $(LIB_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

clean:
	@make fclean -C $(LIB_DIR)
	@/bin/rm -f $(C_OBJS) $(PS_OBJS)
	@echo "push_swap clean : $(_GREEN)Done$(_END)"

fclean: clean
	@/bin/rm -f $(CHECKER) $(PUSH_SWAP)
	@echo "push_swap fclean : $(_GREEN)Done$(_END)"

re:
	@make fclean
	@make

.PHONY: all clean fclean re
