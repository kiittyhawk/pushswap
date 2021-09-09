#include "./includes/psw.h"

void	swap(int *a, int *b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

void	rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*el;

	tmp = *head;
	el = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = init_elem(el->value);
	*head = el->next;
	free(el);
}

void	rrotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*el;

	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	el = init_elem(tmp->next->value);
	tmp->next = NULL;
	el->next = *head;
	*head = el;
	free(el);
}

void	push(t_stack **head_to, t_stack **head_from)
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
}
