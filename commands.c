#include "./includes/psw.h"

void	swap(t_stack **head, char stack)
{
	t_stack	*el;

	el = *head;
	el->value += el->next->value;
	el->next->value = el->value - el->next->value;
	el->value -= el->next->value;
	el->order += el->next->order;
	el->next->order = el->order - el->next->order;
	el->order -= el->next->order;
	el->flag += el->next->flag;
	el->next->flag = el->flag - el->next->flag;
	el->flag -= el->next->flag;
	if (stack == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	rotate(t_stack **head, char stack)
{
	t_stack	*tmp;
	t_stack	*el;

	tmp = *head;
	el = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = init_elem(el->value, el->flag, el->order);
	*head = el->next;
	free(el);
	if (stack == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rrotate(t_stack **head, char stack)
{
	t_stack	*tmp;
	t_stack	*el;

	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	el = init_elem(tmp->next->value, tmp->next->flag, tmp->next->order);
	tmp->next = NULL;
	el->next = *head;
	*head = el;
	free(el);
	if (stack == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	push(t_stack **head_to, t_stack **head_from, char stack)
{
	t_stack	*to;
	t_stack	*from;
	t_stack	*tmp;

	from = *head_from;
	to = *head_to;
	if (!from)
		send_message(1);
	tmp = from;
	from = from->next;
	*head_from = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*head_to = to;
	}
	else
	{
		tmp->next = to;
		*head_to = tmp;
	}
	if (stack == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
