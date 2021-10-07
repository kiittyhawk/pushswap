/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:35:55 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 13:22:28 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"
#include "get_next_line.h"

static void	allfree(t_stack **head, t_stack **head_to)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head);
		free(tmp);
		(*head) = (*head)->next;
	}
	while (*head_to)
	{
		tmp = (*head_to);
		free(tmp);
		(*head_to) = (*head_to)->next;
	}
}

static void	func(t_stack **a, t_stack **b)
{
	char	*line;
	t_stack	*el;

	while (get_next_line(0, &line))
	{
		if (!cmd_is(line, a, b))
			send_message(2);
		free(line);
		line = NULL;
	}
	free(line);
	el = *a;
	if (is_sorted(a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	*a = el;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		count;

	if (argc <= 1)
		send_message(1);
	count = get_count(argv);
	parse_for_stack(argv, &a);
	array_handler_b(argv, count);
	func(&a, &b);
	allfree(&a, &b);
}
