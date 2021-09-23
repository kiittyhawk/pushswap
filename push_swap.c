#include "./includes/psw.h"

t_info	*init_struct()
{
	t_info *info;

	info = (t_info*)malloc(sizeof(t_info));
	if(!info)
		send_message(1);
	info->flag = 0;
	info->next = 1;
	info->max = 0;
	info->mid = 0;
	return(info);
}

void	print_list(t_stack **head, t_stack **head_to)
{
	t_stack	*el;
	t_stack *elem;

	el = *head;
	elem = *head_to;
	printf("%s\n", "Stack A");
	while (el)
	{
		printf("%d - %d - %d\n", el->value, el->flag, el->order);
		el = el->next;
	}
	printf("\n%s\n", "Stack B");
	while (elem)
	{
		printf("%d - %d- %d\n", elem->value, elem->flag, elem->order);
		elem = elem->next;
	}
}

void	sort(t_stack **head, t_stack **head_to, t_info *info)
{
	t_stack	*el;
	int		len;
	// int i = 0, count = 2;

	el = *head;
	len = get_len(&el);
	while (A_is_sorted_stack(&el) != 1)
	{
		step_1(head, head_to, info);
		// print_list(head, head_to);
		step_2(head_to, head, info);
		// elem_is_next(head, info);
		// print_list(head, head_to);
		step_3(head, head_to, info);
		// print_list(head, head_to);
		el = *head;
	}
	head = &el;
}

int main(int argc, char **argv)
{
	t_stack *head;
	t_stack	*head_to;
	t_info	*info;
	int		count;
	
	info = init_struct();
	count = get_count(argv);
	parse_for_stack(argv, &head);
	array_handler(argv, argc, &head, count);
	if (count <= 3)
		sort_elem3(&head, count);
	else if (count <= 5)
		sort_elem5(&head, &head_to, count, info);
	else
		sort(&head, &head_to, info);
	// print_list(&head, &head_to);
	free(info);
	free(head_to);
	return (0);
}
