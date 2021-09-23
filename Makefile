SRCS	= includes/psw.h Libft/libft.a *.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

INCLUDE	= -I./includes

CC		= gcc
RM		= rm -f

AR		= ar rcs

CFLAGS	= -Wall -Wextra -Werror

# .c.o:
# 			${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o} 

# ${NAME}:	${OBJS}
# 			${AR} ${NAME} $?

# all:		${NAME}
	
# clean:
# 			${RM} ${OBJS}

# fclean:		clean
# 			${RM} ${NAME}

# re:			fclean all

all:
			${CC} -g ${SRCS}

.PHONY:		all clean fclean re libftprintf.a
