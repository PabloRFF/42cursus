#include "push_swap.h"

void	swap_elem(t_elem *a, t_elem *b)
{
	t_elem	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void    assign_indices(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->data[i].value > a->data[j].value)
				a->data[i].index++;
			j++;
		}
		i++;
	}
}
void    print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("Stack A:\n");
	while (i < a->size)
	{
		printf("Value: %d, Index: %d\n", a->data[i].value, a->data[i].index);
		i++;
	}
	i = 0;
	printf("Stack B:\n");
	while (i < b->size)
	{
		printf("Value: %d, Index: %d\n", b->data[i].value, b->data[i].index);
		i++;
	}
}
void	sort_array(t_elem *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j].value > arr[j + 1].value)
				swap_elem(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}
