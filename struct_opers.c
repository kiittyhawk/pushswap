#include "./includes/psw.h"

t_stack *init_elem(int num, int flag, int order)
{
	t_stack *elem;

	elem = (t_stack*)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = num;
	elem->flag = flag;
	elem->order = order;
	elem->next = NULL;
	return (elem);
}

void	add_elem(t_stack **head, t_stack *elem)
{
	t_stack *tmp;

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
		free(args);
	}
	return (count);
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
		free(args);
	}
	array[order] = '\0';
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
			num = ft_atoi(args[j++]);
			if (!num && num != 0)
				send_message(1);
			add_elem(head, init_elem(num, 0, 0));
		}
		free(args);
	}
}

