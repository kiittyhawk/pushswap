/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:40:17 by jgyles            #+#    #+#             */
/*   Updated: 2021/10/06 10:40:18 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

static int	is_rr(char *s1, char *s2)
{
	if ((!ft_strncmp(s1, "ra", 2) && !ft_strncmp(s2, "rb", 2))
		|| (s2 && !ft_strncmp(s2, "ra", 2) && !ft_strncmp(s1, "rb", 2)))
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}

static int	is_pa_pb(char *s1, char *s2)
{
	if ((s2 && !ft_strncmp(s1, "pa", 2) && !ft_strncmp(s2, "pb", 2))
		|| (s2 && !ft_strncmp(s2, "pa", 2) && !ft_strncmp(s1, "pb", 2)))
		return (1);
	return (0);
}

void	output_handler(t_operations *out)
{
	char	*cmd1;
	char	*cmd2;

	while (out->next)
	{
		cmd1 = out->cmd;
		cmd2 = out->next->cmd;
		if (is_rr(cmd1, cmd2))
			out = out->next;
		else if (is_pa_pb(cmd1, cmd2))
			out = out->next;
		else
		{
			write(1, out->cmd, 2);
			write(1, "\n", 1);
		}
		out = out->next;
	}
	write(1, out->cmd, 2);
	write(1, "\n", 1);
}

void	piece(t_info *info, t_stack **head_to)
{
	info->i = 0;
	info->len = get_len(head_to);
	info->max = search_max_order(head_to);
	info->mid = get_mid(2, info);
	info->flag++;
}

int	get_count(char **argv)
{
	int		i;
	int		j;
	char	**args;
	int		count;

	i = 1;
	j = 0;
	count = 0;
	while (argv[i])
	{
		args = ft_split(argv[i++], ' ');
		while (args[j++])
			count++;
		j = 0;
		free_array(args);
	}
	return (count);
}
