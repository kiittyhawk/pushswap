/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:40:36 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:40:37 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

t_info	*init_struct(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		send_message(1);
	info->flag = 0;
	info->next = 1;
	info->max = 0;
	info->mid = 0;
	return (info);
}

static void	free_output(t_operations **output)
{
	t_operations	*tmp;

	while (*output)
	{
		tmp = *output;
		*output = (*output)->next;
		free(tmp);
	}
}

void	push_swap(t_stack **head, t_stack **head_to, t_info *info)
{
	t_stack			*el;
	t_operations	*output;

	el = *head;
	output = NULL;
	while (A_is_sorted_stack(&el) != 1)
	{
		step_1(head, head_to, info, &output);
		step_2(head_to, head, info, &output);
		step_3(head, head_to, info, &output);
		el = *head;
	}
	all_free(head, head_to, info);
	output_handler(output);
	free_output(&output);
}

int	main(int argc, char **argv)
{
	t_stack	*head;
	t_stack	*head_to;
	t_info	*info;
	int		count;

	if (argc <= 1)
		send_message(1);
	info = init_struct();
	count = get_count(argv);
	parse_for_stack(argv, &head);
	array_handler(argv, argc, &head, count);
	if (count <= 3)
		sort_elem3(&head, count);
	else if (count <= 5)
		sort_elem5(&head, &head_to, info);
	else
		push_swap(&head, &head_to, info);
}
