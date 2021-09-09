#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_stack
{
	int				value;
	int				flag;
	struct s_stack	*next;
}				t_stack;


# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../Libft/libft.h"

void	send_message(int flag);
t_stack *init_elem(int num);
void	add_elem(t_stack **head, t_stack *elem);
void	swap(int *a, int *b);
void	rotate(t_stack **head);
void	rrotate(t_stack **head);
void	push(t_stack **head_to, t_stack **head_from);
void	chck_dup(t_stack **head);
t_stack	*make_list(char **argv, t_stack *head);
void	search_err(int argc);

#endif
