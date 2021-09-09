#include "./includes/psw.h"

int	search_max(t_stack **head)
{
	t_stack	*el;
	int		max;

	el = *head;
	max = INT32_MIN;
	while (el)
	{
		if (el->value > max)
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
		if (el->value < min)
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
	while (el->next != NULL)
	{
		i++;
		el = el->next;
	}
	return (i);
}

void	sort_stackb(t_stack **head_to, t_stack **head, int next)
{
	int		mid;
	t_stack	*tmp;
	int		max;
	int		len;
	int		i;

	tmp = *head_to;
	max = search_max(head_to);
	mid = ((max - next) / 2 + next);
	len = get_len(head_to);
	i = 0;
	while (i <= len)
	{
		if (tmp->value <= mid || tmp->value == max)
		{
			tmp->flag++;
			push(head, &tmp);
		}
		else
			rotate(&tmp);
		i++;
	}
	*head_to = tmp;
}

void	sort_minmax(t_stack **head, t_stack **head_to, int argc, int next)
{
	int		mid;
	int		max;
	t_stack	*el;
	int		i;

	el = *head;
	i = 1;
	max = search_max(&el);
	mid = ((max / 2) + next);
	while (i != argc)
	{
		if (el->value <= mid)
			push(head_to, &el);
		else
			rotate(&el);
		i++;
	}
	*head = el;
}

void	sort(t_stack **head, t_stack **head_to, int argc)
{
	int		next;
	t_stack	*elem;
	int		i;

	next = search_min(head);
	elem = *head;
	i = 0;
	if (i++ == 0)
		sort_minmax(head, head_to, argc, next);
	if (elem->value == next)
	{
		elem->flag = 1024;
		rotate(&elem);
		next++;
		*head = elem;
	}
	if (elem->next->value == next)
	{
		swap(&elem->value, &elem->next->value);
		*head = elem;
	}
	while (*head_to)
	{
		sort_stackb(head_to, head, next);
		elem = *head;
		if (elem->value == next)
		{
			rotate(&elem);
			elem->flag = 1024;
			next++;
		}
		*head = elem;
	}
	sort(head, head_to, argc);
}

void	print_list(t_stack **head, t_stack **head_to)
{
	t_stack	*el;

	el = *head;
	while (el)
	{
		printf("%d\n", el->value);
		el = el->next;
	}
}

int main(int argc, char **argv)
{
	t_stack *head, *head_to;
	t_stack	*el;
	int		next;

	next = 1;
	search_err(argc);
	head = make_list(argv, head);
	sort(&head, &head_to, argc);
	print_list(&head, &head_to);
}
