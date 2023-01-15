NAME = push_swap
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
SRC = a_operations.c\
		array.c\
		b_operations.c\
		check_wassup.c\
		create.c\
		is_sorted.c\
		push_swap_more_utils.c\
		push_swap_utils.c\
		push_swap.c\
		size_count.c\
		more_utils.c\
		sorting_utils.c\
		sorting.c\
		sorting_utils2.c\
		
NAME1 = checker
SRC1 = bonus/checker_a_actions.c\
		bonus/checker_b_actions.c\
		bonus/checker_more_utils.c\
		bonus/checker_more_utils2.c\
		bonus/checker_utils.c\
		bonus/checker.c\
		bonus/get_next_line.c\
		bonus/get_next_line_utils.c\
		bonus/split_b.c\
		bonus/operations_to_do_b.c\
		bonus/final_step_b.c\
		bonus/operation_zaydin.c\
		bonus/utils_b.c\

OBJECTS = ${SRC:.c=.o}

OBJECTS1 = ${SRC1:.c=.o}

all : $(NAME)

$(NAME):	$(OBJECTS)
	gcc $(CFLAGS) $(SRC) -o $(NAME)

bonus : $(NAME1)

$(NAME1):	$(OBJECTS1)
	gcc $(CFLAGS) $(SRC1) -o $(NAME1)

clean:
	$(RM)	$(OBJECTS)	$(OBJECTS1)

fclean:	clean
	$(RM) $(NAME) $(NAME1)

re:clean fclean all

.PHONY: all bonus clean fclean re

