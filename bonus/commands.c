/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:36:01 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:36:04 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

int	swap_ch(t_stack **head)
{
	t_stack	*el;

	if ((*head)->next)
	{
		el = *head;
		el->value += el->next->value;
		el->next->value = el->value - el->next->value;
		el->value -= el->next->value;
		el->order += el->next->order;
		el->next->order = el->order - el->next->order;
		el->order -= el->next->order;
		el->flag += el->next->flag;
		el->next->flag = el->flag - el->next->flag;
		el->flag -= el->next->flag;
		return (1);
	}
	return (2);
}

int	rotate_ch(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*el;

	if (*head)
	{
		tmp = *head;
		el = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = init_elem(el->value, el->flag, el->order, el->fix);
		*head = el->next;
		free(el);
	}
	return (1);
}

int	push_ch(t_stack **head_to, t_stack **head_from)
{
	t_stack	*to;
	t_stack	*from;
	t_stack	*tmp;

	from = *head_from;
	to = *head_to;
	if (!from)
		send_message(2);
	tmp = from;
	from = from->next;
	*head_from = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*head_to = to;
	}
	else
	{
		tmp->next = to;
		*head_to = tmp;
	}
	return (1);
}
