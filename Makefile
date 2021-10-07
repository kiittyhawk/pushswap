NAME = 	push_swap

BONUS_NAME = checker

LIBFT = ./libft/libft.a

PATH_LIB = ./libft/

HEADER = ./includes/psw.h
HEADER_INC = -I./includes/

SRC = $(shell ls ./src/*.c)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $(HEADER_INC) $< -o $@

OBJS = $(patsubst %.c, %.o, $(SRC))

SRC_B = $(shell ls ./bonus/*.c)
OBJS_B = $(patsubst %.c, %.o, $(SRC_B)) $(OBJS)

GNL = ./includes/get_next_line.h

CC	= gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

all:	run_lib $(NAME)

bonus:		run_lib $(BONUS_NAME)

run_lib:	./libft/libft.h
			make -C libft/

$(NAME): 	$(OBJS) $(LIBFT) ./includes/psw.h ./libft/libft.h push_swap.c
			$(CC) $(CFLAGS) $(HEADER_INC) $(LIBFT) $(OBJS) push_swap.c -o $(NAME)

$(BONUS_NAME): 	$(OBJS_B) $(LIBFT) ./includes/psw.h ./libft/libft.h $(GNL)
				$(CC) $(CFLAGS) $(HEADER_INC) $(LIBFT) $(OBJS_B) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
	make -C libft/ clean

fclean: clean
	$(RM) $(OBJS) ./src/push_swap.o push_swap
	$(RM) $(OBJS_B) checker
	make -C libft/ fclean

re: fclean all bonus

.PHONY: all clean fclean re
