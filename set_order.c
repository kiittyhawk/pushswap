#include "./includes/psw.h"

void	selectionSort(int *num, int size)
{
	int min;
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1) 
	{
		j = i + 1;
		min = i;
		while (j < size)
		{
			if (num[j] < num[min])
				min = j;
			j++;
		}
		temp = num[i];
		num[i++] = num[min];
		num[min] = temp;
	}
}

void	order_set(t_stack **head, int *array, int count)
{
	t_stack	*el;
	int		i;

	el = *head;
	i = 0;
	while (el)
	{
		while (i < count)
		{
			if (el->value == array[i])
			{
				el->order = i + 1;
				break;
			}
			i++;
		}
		i = 0;
		el = el->next;
	}
}

void	array_handler(char **argv, int argc, t_stack **head, int count)
{
	int		*array;
	t_stack	*el;

	array = (int *)malloc(count + 1);
	if(!array)
		send_message(1);
	el = *head;
	if (!(argc > 1))
		send_message(1);
	parse_for_array(argv, array);
	search_err(array, count);
	selectionSort(array, count);
	order_set(&el, array, count);
	*head = el;
}
