#include "./includes/psw.h"

t_stack *init_elem(int num)
{
	t_stack *elem;

	elem = (t_stack*)malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = num;
	elem->flag = 0;
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

t_stack	*make_list(char **argv, t_stack *head)
{
	char	**args;
	int		i;
	int		j;
	int		num;

	i = 1;
	j = 0;
	while (argv[i])
	{
		args = ft_split(argv[i++], ' ');
		while (args[j])
		{
			num = ft_atoi(args[j++]);
			if (!num)
				send_message(1);
			add_elem(&head, init_elem(num));
		}
		j = 0;
	}
	chck_dup(&head);
	free(args);
	return (head);
}

void	search_err(int argc)
{
	if (argc <= 1)
		send_message(1);
}