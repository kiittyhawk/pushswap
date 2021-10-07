/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_opers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:40:31 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:40:32 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

t_stack	*init_elem(int num, int flag, int order, int fix)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = num;
	elem->flag = flag;
	elem->order = order;
	elem->fix = fix;
	elem->next = NULL;
	return (elem);
}

void	add_elem(t_stack **head, t_stack *elem)
{
	t_stack	*tmp;

	tmp = *head;
	if (*head)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		*head = elem;
}

void	parse_for_array(char **argv, int *array)
{
	char	**args;
	int		i;
	int		j;
	int		num;
	int		order;

	i = 1;
	order = 0;
	while (argv[i])
	{
		j = 0;
		args = ft_split(argv[i++], ' ');
		while (args[j])
		{
			num = ft_atoi(args[j++]);
			if (!num && num != 0)
				send_message(1);
			array[order++] = num;
		}
		free_array(args);
	}
	array[order] = '\0';
}

void	is_double(char *nmb)
{
	int	i;

	i = 0;
	while (nmb[i])
	{
		if (nmb[i] == '-' && i == 0)
			i++;
		if (!ft_isdigit(nmb[i]))
			send_message(2);
		i++;
	}
}

void	parse_for_stack(char **argv, t_stack **head)
{
	char	**args;
	int		i;
	int		j;
	int		num;

	i = 1;
	while (argv[i])
	{
		j = 0;
		args = ft_split(argv[i++], ' ');
		while (args[j])
		{
			is_large(args[j]);
			is_double(args[j]);
			num = ft_atoi(args[j++]);
			if (!num && num != 0)
				send_message(2);
			add_elem(head, init_elem(num, 0, 0, 0));
		}
		free_array(args);
	}
}
