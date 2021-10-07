/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:40:27 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:40:28 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

void	step_1(t_stack **head, t_stack **head_to,
			t_info *info, t_operations **output)
{
	int	i;
	int	len;

	i = 0;
	len = get_len(head);
	info->max = search_max_order(head);
	info->mid = get_mid(1, info);
	while (i < len && !(*head)->fix)
	{
		if ((*head)->order <= info->mid)
			output_push(head_to, head, output, "b");
		else
			output_rotate(head, output, "a");
		i++;
	}
}

void	step_2(t_stack **head_to, t_stack **head,
		t_info *info, t_operations **output)
{
	while (*head_to)
	{
		piece(info, head_to);
		while (while_handler(1, head_to, info))
		{
			if ((*head_to)->order == info->next)
			{
				info->next++;
				(*head_to)->fix = 1;
				(*head_to)->flag = -1;
				output_push(head, head_to, output, "a");
				output_rotate(head, output, "a");
			}
			else if ((*head_to)->order >= info->mid)
			{
				(*head_to)->flag = info->flag;
				output_push(head, head_to, output, "a");
			}
			else
				output_rotate(head_to, output, "b");
			info->i++;
		}
	}
}

void	step_3(t_stack **head, t_stack **head_to,
		t_info *info, t_operations **output)
{
	int	flag;

	while (!(*head)->fix && (*head)->flag > 0)
	{
		flag = (*head)->flag;
		while ((*head)->flag == flag)
		{
			if ((*head)->order == info->next)
			{
				info->next++;
				(*head)->flag = -1;
				(*head)->fix = 1;
				output_rotate(head, output, "a");
			}
			else
				output_push(head_to, head, output, "b");
		}
		step_2(head_to, head, info, output);
	}
}

void	sort_elem3(t_stack **head, int count)
{
	t_stack	*el;
	int		max;

	el = *head;
	max = search_max(&el);
	if (count == 1)
		return ;
	else if (count == 2)
	{
		if (el->value > el->next->value)
			swap_ab(&el, 'a');
		return ;
	}
	else if (count == 3)
	{
		if (el->value == max)
			rotate_ab(&el, 'a');
		if (el->next->value == max)
			rrotate_ab(&el, 'a');
		if (el->value > el->next->value)
			swap_ab(&el, 'a');
	}
	*head = el;
}

void	sort_elem5(t_stack **head, t_stack **head_to, t_info *info)
{
	t_stack	*el;
	int		i;

	el = *head;
	i = 0;
	info->min = search_min(&el);
	info->max = search_max(&el);
	while (get_len(head_to) < 2)
	{
		if (el->value == info->min || el->value == info->max)
			push_ab(head_to, &el, 'b');
		else
			rotate_ab(&el, 'a');
	}
	sort_elem3(&el, get_len(&el));
	push_ab(&el, head_to, 'a');
	push_ab(&el, head_to, 'a');
	if (el->value == info->max)
		rotate_ab(&el, 'a');
	else
	{
		swap_ab(&el, 'a');
		rotate_ab(&el, 'a');
	}
	*head = el;
}
