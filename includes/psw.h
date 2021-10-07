/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:36:52 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/07 11:52:11 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_H
# define PSW_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				flag;
	int				order;
	int				fix;
	int				len;
	struct s_stack	*next;
}					t_stack;

typedef struct s_info
{
	int		mid;
	int		flag;
	int		max;
	int		next;
	int		min;
	int		len;
	int		i;
}			t_info;

typedef struct s_operations
{
	char				*cmd;
	struct s_operations	*next;
}						t_operations;

void	send_message(int flag);
t_stack	*init_elem(int num, int flag, int order, int fix);
void	add_elem(t_stack **head, t_stack *elem);
void	swap(t_stack **head);
void	rotate(t_stack **head);
void	push(t_stack **head_to, t_stack **head_from);
void	parse_for_array(char **argv, int *array);
void	search_err(int *array, int count);
int		get_len(t_stack **head);
void	array_handler(char **argv, int argc, t_stack **head, int count);
int		get_count(char **argv);
void	selection_sort(int *num, int size);
void	parse_for_stack(char **argv, t_stack **head);
t_info	*init_struct(void);
int		a_is_sorted_stack(t_stack **head);
void	push_swap(t_stack **head, t_stack **head_to, t_info *info);
int		search_max(t_stack **head);
int		search_min(t_stack **head);
int		search_max_order(t_stack **head);
void	step_1(t_stack **head, t_stack **head_to,
			t_info *info, t_operations **output);
void	step_2(t_stack **head_to, t_stack **head,
			t_info *info, t_operations **output);
void	step_3(t_stack **head, t_stack **head_to,
			t_info *info, t_operations **output);
void	sort_elem3(t_stack **head, int count);
void	sort_elem5(t_stack **head, t_stack **head_to, t_info *info);
int		get_mid(int option, t_info *info);
int		while_handler(int option, t_stack **head_to, t_info *info);
void	all_free(t_stack **head, t_stack **head_to, t_info *info);
void	output_handler(t_operations *out);
void	output_swap(t_stack **head, t_operations **out, char *stack);
void	output_rotate(t_stack **head, t_operations **out, char *stack);
void	output_push(t_stack **head_to, t_stack **head_from,
			t_operations **out, char *stack);
void	swap_ab(t_stack **head, char stack);
void	rotate_ab(t_stack **head, char stack);
void	push_ab(t_stack **head_to, t_stack **head_from, char stack);
void	rrotate_ab(t_stack **head, char stack);
void	piece(t_info *info, t_stack **head_to);
void	free_array(char **array);
void	is_large(char *nmb);
void	is_double(char *nmb);

// void	parse(t_stack **a, char **argv);
// void	find_err(t_stack **a);
int		is_sorted(t_stack **a);
int		rrotate(t_stack **head);
int		cmd(t_stack **a, t_stack **b, int flag);
int		cmd_is(char *line, t_stack **a, t_stack **b);
void	print_list(t_stack **head, t_stack **head_to);
int		swap_ch(t_stack **head);
int		rotate_ch(t_stack **head);
int		push_ch(t_stack **head_to, t_stack **head_from);
void	array_handler_b(char **argv, int count);
void	chck_dup(int *array, int count);

#endif