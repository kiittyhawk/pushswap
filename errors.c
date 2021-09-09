#include "./includes/psw.h"

void	send_message(int flag)
{
	if (flag == 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (flag == 2)
	{
		write(1, "There are identical characters\n", 32);
		exit(0);
	}
	
	if (flag == 3)
	{
		write(1, "Only integers are allowed\n", 26);
		exit(0);
	}
}

void	chck_dup(t_stack **head)
{
	t_stack	*elem;
	t_stack	*iterator;

	elem = *head;
	iterator = elem->next;
	while (elem->next != NULL)
	{
		while (iterator)
		{
			if (elem->value == iterator->value)
				send_message(2);
			iterator = iterator->next;
		}
		elem = elem->next;
		iterator = elem->next;
	}
}
