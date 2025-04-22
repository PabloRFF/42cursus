#include "push_swap.h"

extern int	move_count;

void	sa(t_stack *a)
{
	t_elem	tmp;

	if (a->size >= 2)
	{
		tmp = a->data[0];
		a->data[0] = a->data[1];
		a->data[1] = tmp;
		write(1, "sa\n", 3);
		move_count++;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int		i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = a->data[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->size--;
	write(1, "pb\n", 3);
	move_count++;
}

void	ra(t_stack *a)
{
	t_elem	tmp;
	int		i;

	if (a->size < 2)
		return ;
	tmp = a->data[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->size - 1] = tmp;
	write(1, "ra\n", 3);
	move_count++;
}
