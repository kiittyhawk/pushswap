/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:36:27 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 12:59:38 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

int	is_sorted(t_stack **a)
{
	if (*a)
	{
		while ((*a)->next)
		{
			if ((*a)->value > (*a)->next->value)
				return (0);
			(*a) = (*a)->next;
		}
	}
	return (1);
}

int	rrotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*el;

	if (*head)
	{
		tmp = *head;
		el = *head;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		*head = tmp->next;
		tmp->next = NULL;
		(*head)->next = el;
		return (1);
	}
	return (2);
}

int	cmd(t_stack **a, t_stack **b, int flag)
{
	if (*a && *b && ((*a)->next && (*b)->next))
	{
		if (flag == 1)
		{
			swap_ch(a);
			swap_ch(b);
		}
		if (flag == 2)
		{
			rotate_ch(a);
			rotate_ch(b);
		}
		if (flag == 3)
		{
			rrotate(a);
			rrotate(b);
		}
	}
	return (2);
}

int	cmd_is(char *line, t_stack **a, t_stack **b)
{
	if (!(ft_strcmp(line, "sa")))
		return (swap_ch(a));
	if (!(ft_strcmp(line, "sb")))
		return (swap_ch(b));
	if (!(ft_strcmp(line, "ss")))
		return (cmd(a, b, 1));
	if (!(ft_strcmp(line, "pa")))
		return (push_ch(a, b));
	if (!(ft_strcmp(line, "pb")))
		return (push_ch(b, a));
	if (!(ft_strcmp(line, "ra")))
		return (rotate_ch(a));
	if (!(ft_strcmp(line, "rb")))
		return (rotate_ch(b));
	if (!(ft_strcmp(line, "rrr")))
		return (cmd(a, b, 3));
	if (!(ft_strcmp(line, "rra")))
		return (rrotate(a));
	if (!(ft_strcmp(line, "rrb")))
		return (rrotate(b));
	if (!(ft_strcmp(line, "rr")))
		return (cmd(a, b, 2));
	else
		return (0);
}
