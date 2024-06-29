NAME 		= push_swap
BONUS		= checker
CC			= gcc
FLAGS 		= -Wall -Wextra -Werror 
SRCS		= actions.c adv_sort_utils.c check_args.c \
			adv_sort.c push_swap.c stack_utils.c sort_stack.c \
			is_sorted.c helpers.c

OBJS		:= $(SRCS:.c=.o)

AR_LIBFT	= libft/libft.a
DIR_LIBFT	= libft

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(DIR_LIBFT) -s
	$(CC) $(FLAGS) $(OBJS) $(AR_LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -s -C $(DIR_LIBFT) clean

fclean: clean
	rm -f $(NAME) checker
	make -s -C $(DIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re