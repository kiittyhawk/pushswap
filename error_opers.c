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

void	chck_dup(int *array, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (array[i] == array [i + 1])
			send_message(2);
		i++;
	}
}

int	A_is_sorted(int *array, int count)
{
	int	i;

	i = 0;
	while (i + 1 < count)
	{
		if (array[i] < array[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	A_is_sorted_stack(t_stack **head)
{
	int	i;

	i = 0;
	while ((*head)->next->next != NULL)
	{
		if ((*head)->order < (*head)->next->order)
			(*head) = (*head)->next;
		else
			return (0);
	}
	if ((*head)->next->order < (*head)->order)
		return (0);
	return (1);
}

void	search_err(int *array, int count)
{
	chck_dup(array, count);
	if (A_is_sorted(array, count) == 1)
	{
		write(1, "Stack is sorted\n", 16);
		exit (0);
	}
}
