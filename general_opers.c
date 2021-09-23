#include "./includes/psw.h"

int	search_max_order(t_stack **head)
{
	t_stack	*el;
	int		max;

	el = *head;
	max = INT32_MIN;
	while (el)
	{
		if (el->order > max && el->flag != 1024)
			max = el->order;
		el = el->next;
	}
	// free(el);
	return (max);
}

int	search_max(t_stack **head)
{
	t_stack	*el;
	int		max;

	el = *head;
	max = INT32_MIN;
	while (el)
	{
		if (el->value > max && el->flag != 1024)
			max = el->value;
		el = el->next;
	}
	// free(el);
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
		if (el->value < min && el->flag != 1024)
			min = el->value;
		el = el->next;
	}
	// free(el);
	return (min);
}

int	get_len(t_stack **head)
{
	int		i;
	t_stack	*el;

	i = 0;
	el = *head;
	while (el)
	{
		i++;
		el = el->next;
	}
	// free(el);
	return (i);
}

void	elem_is_next(t_stack **head, t_info *info)
{
	if ((*head)->order == info->next)
	{
		(*head)->flag = 1024;
		rotate(head, 'a');
		info->next++;
	}
	if ((*head)->next != NULL && (*head)->next->order == info->next)
	{
		swap(head, 'a');
		elem_is_next(head, info);
	}
}
