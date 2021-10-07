/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_opers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:40:01 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:40:02 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

int	search_max_order(t_stack **head)
{
	t_stack	*el;
	int		max;

	el = *head;
	max = 0;
	while (el)
	{
		if (el->order > max && !el->fix)
			max = el->order;
		el = el->next;
	}
	return (max);
}

int	search_max(t_stack **head)
{
	t_stack	*el;
	int		max;

	el = *head;
	max = INT32_MIN;
	while (el)
	{
		if (el->value > max && !el->fix)
			max = el->value;
		el = el->next;
	}
	return (max);
}

int	search_min(t_stack **head)
{
	t_stack	*el;
	int		min;

	el = *head;
	min = INT32_MAX;
	while (el)
	{
		if (el->value < min && !el->fix)
			min = el->value;
		el = el->next;
	}
	return (min);
}

int	get_len(t_stack **head)
{
	int		i;
	t_stack	*el;

	i = 0;
	el = *head;
	while (el)
	{
		i++;
		el = el->next;
	}
	return (i);
}

int	get_mid(int option, t_info *info)
{
	int	mid;

	if (option == 1)
	{
		mid = ((info->max / 2) + info->next);
	}
	else
		mid = ((info->max - info->next) / 2 + info->next);
	return (mid);
}
