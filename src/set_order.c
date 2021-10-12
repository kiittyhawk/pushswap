/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:40:22 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:40:23 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

void	selectionSort(int *num, int size)
{
	int	min;
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		min = i;
		while (j < size)
		{
			if (num[j] < num[min])
				min = j;
			j++;
		}
		temp = num[i];
		num[i++] = num[min];
		num[min] = temp;
	}
}

static void	order_set(t_stack **head, int *array, int count)
{
	t_stack	*el;
	int		i;

	el = *head;
	i = 0;
	while (el)
	{
		while (i < count)
		{
			if (el->value == array[i])
			{
				el->order = i + 1;
				break ;
			}
			i++;
		}
		i = 0;
		el = el->next;
	}
}

void	array_handler(char **argv, int argc, t_stack **head, int count)
{
	int		*array;
	t_stack	*el;

	array = (int *)malloc((count + 1) * sizeof(int));
	if (!array)
		send_message(1);
	el = *head;
	if (!(argc > 1))
		send_message(1);
	parse_for_array(argv, array);
	search_err(array, count);
	selectionSort(array, count);
	order_set(&el, array, count);
	*head = el;
	free(array);
}

int	while_handler(int option, t_stack **head_to, t_info *info)
{
	if (option == 1)
	{
		if (info->i < info->len)
			return (1);
		return (0);
	}
	if (option == 2)
	{
		while (*head_to)
		{
			if ((*head_to)->fix == 0 && (*head_to)->flag > 0)
				return (1);
			(*head_to) = (*head_to)->next;
		}
		return (0);
	}
	return (0);
}

void	all_free(t_stack **head, t_stack **head_to, t_info *info)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp);
	}
	while (*head_to)
	{
		tmp = (*head_to);
		(*head_to) = (*head_to)->next;
		free(tmp);
	}
	free(info);
}
