/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:39:58 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/07 11:51:40 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

void	send_message(int flag)
{
	if (flag == 1)
		exit(0);
	if (flag == 2)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	chck_dup(int *array, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < count)
	{
		while (j != count)
		{
			if (array[i] == array[j])
				send_message(2);
			j++;
		}
		i++;
		j = i + 1;
	}
}

static int	a_is_sorted(int *array, int count)
{
	int	i;

	i = 0;
	while (i + 1 < count)
	{
		if (array[i] < array[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	a_is_sorted_stack(t_stack **head)
{
	int	i;

	i = 1;
	while (*head)
	{
		if ((*head)->order != i)
			return (0);
		i++;
		(*head) = (*head)->next;
	}
	return (1);
}

void	search_err(int *array, int count)
{
	chck_dup(array, count);
	if (a_is_sorted(array, count) == 1)
		exit (0);
}
