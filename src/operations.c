/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:40:13 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:40:14 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

t_operations	*create_node_output(char *cmd)
{
	t_operations	*node;

	node = (t_operations *)malloc(sizeof(*node));
	if (!node)
		send_message(1);
	node->cmd = cmd;
	node->next = NULL;
	return (node);
}

void	add_node_output(t_operations **out, t_operations *elem)
{
	t_operations	*tmp;

	tmp = *out;
	if (*out)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		*out = elem;
}

void	output_swap(t_stack **head, t_operations **out, char *stack)
{
	t_operations	*cmd;

	if (!(ft_strncmp(stack, "a", 1)))
		cmd = create_node_output("sa");
	else
		cmd = create_node_output("sb");
	add_node_output(out, cmd);
	swap(head);
}

void	output_rotate(t_stack **head, t_operations **out, char *stack)
{
	t_operations	*cmd;

	if (!(ft_strncmp(stack, "a", 1)))
		cmd = create_node_output("ra");
	else
		cmd = create_node_output("rb");
	add_node_output(out, cmd);
	rotate(head);
}

void	output_push(t_stack **head_to, t_stack **head_from,
		t_operations **out, char *stack)
{
	t_operations	*cmd;

	if (!(ft_strncmp(stack, "a", 1)))
		cmd = create_node_output("pa");
	else
		cmd = create_node_output("pb");
	add_node_output(out, cmd);
	push(head_to, head_from);
}
