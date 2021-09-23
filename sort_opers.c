#include "./includes/psw.h"

void	step_1(t_stack **head, t_stack **head_to, t_info *info)
{
	int	i;
	int	len;

	i = 0;
	len = get_len(head);
	info->max = search_max_order(head);
	info->mid = ((info->max / 2) + info->next);
	while (i < len && (*head)->flag != 1024)
	{
		if ((*head)->order <= info->mid)
			push(head_to, head, 'b');
		else
			rotate(head, 'a');
		i++;
	}
}

void	step_2(t_stack **head_to, t_stack **head, t_info *info)
{
	int		i;
	int		len;

	while (*head_to)
	{
		i = 0;
		len = get_len(head_to);
		info->max = info->mid;
		info->mid = ((info->max - info->next) / 2 + info->next);
		info->flag++;
		while (i < len)
		{
			if ((*head_to)->order >= info->mid || (*head_to)->order == info->next)
			{
				(*head_to)->flag = info->flag;
				push(head, head_to, 'a');
				elem_is_next(head, info);
			}
			else
				rotate(head_to, 'b');
			elem_is_next(head, info);
			i++;
		}
		// elem_is_next(head, info);
	}
	// elem_is_next(head, info);
}

void	step_3(t_stack **head, t_stack **head_to, t_info *info)
{
	int		flag;

	flag = (*head)->flag;
	while (flag > 0 && flag != 1024)
	{
		// printf("flag - %d\n", (*head)->flag);
		while (*head)
		{
			if ((*head)->order == info->next)
				elem_is_next(head, info);
			if ((*head)->flag == flag)
				push(head_to, head, 'b');
			else
				break;
		}
		step_2(head_to, head, info);
		elem_is_next(head, info);
		flag = (*head)->flag;
	}
}

void	sort_elem3(t_stack **head, int count)
{
	t_stack	*el;
	int max;

	el = *head;
	max = search_max(&el);
	if (count == 1)
		return ;
	else if (count == 2)
	{
		if (el->value > el->next->value)
			swap(&el, 'a');
		return ;
	}
	else if (count == 3)
	{
		if (el->value == max)
			rotate(&el, 'a');
		if (el->next->value == max)
			rrotate(&el, 'a');
		if (el->value > el->next->value)
			swap(&el, 'a');
	}
	*head = el;
}

void	sort_elem5(t_stack **head, t_stack **head_to, int count, t_info *info)
{
	t_stack	*el;
	int		i;

	el = *head;
	i = 0;
	info->min = search_min(&el);
	info->max = search_max(&el);
	while (get_len(head_to) < 2)
	{
		if (el->value == info->min || el->value == info->max)
			push(head_to, &el, 'b');
		else
			rotate(&el, 'a');
	}
	sort_elem3(&el, get_len(&el));
	push(&el, head_to, 'a');
	push(&el, head_to, 'a');
	if (el->value == info->max)
		rotate(&el, 'a');
	else
	{
		swap(&el, 'a');
		rotate(&el, 'a');
	}
	*head = el;
}
