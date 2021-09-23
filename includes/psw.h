#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_stack
{
	int				value;
	int				flag;
	int				order;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_info
{
	int		mid;
	int		flag;
	int		max;
	int		next;
	int		min;
}				t_info;

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../Libft/libft.h"

void	send_message(int flag);
t_stack *init_elem(int num, int flag, int order);
void	add_elem(t_stack **head, t_stack *elem);
void	swap(t_stack **head, char stack);
void	rotate(t_stack **head, char stack);
void	rrotate(t_stack **head, char stack);
void	push(t_stack **head_to, t_stack **head_from, char stack);
void	chck_dup(int *array, int count);
void	parse_for_array(char **argv, int *array);
void	search_err(int *array, int count);
int		A_is_sorted(int *array, int count);
int		get_len(t_stack **head);
void	array_handler(char **argv, int argc, t_stack **head, int count);
int		get_count(char **argv);
void	selectionSort(int *num, int size);
void	parse_for_stack(char **argv, t_stack **head);
t_info	*init_struct();
int		A_is_sorted_stack(t_stack **head);
void	elem_is_next(t_stack **head, t_info *info);
void	sort(t_stack **head, t_stack **head_to, t_info *info);
int		search_max(t_stack **head);
int		search_min(t_stack **head);
int		search_max_order(t_stack **head);
void	step_1(t_stack **head, t_stack **head_to, t_info *info);
void	step_2(t_stack **head_to, t_stack **head, t_info *info);
void	step_3(t_stack **head, t_stack **head_to, t_info *info);
void	sort_elem3(t_stack **head, int count);
void	sort_elem5(t_stack **head, t_stack **head_to, int count, t_info *info);

#endif