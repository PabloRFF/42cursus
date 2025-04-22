
#include "push_swap.h"

extern int	move_count;

void	pa(t_stack *a, t_stack *b)
{
	int		i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = b->data[0];
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->size--;
	write(1, "pa\n", 3);
	move_count++;
}

void	sb(t_stack *b)
{
	t_elem	tmp;

	if (b->size >= 2)
	{
		tmp = b->data[0];
		b->data[0] = b->data[1];
		b->data[1] = tmp;
		write(1, "sb\n", 3);
		move_count++;
	}
}

void	rb(t_stack *b)
{
	t_elem	tmp;
	int		i;

	if (b->size < 2)
		return ;
	tmp = b->data[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->size - 1] = tmp;
	write(1, "rb\n", 3);
	move_count++;
}

void	rra(t_stack *a)
{
	t_elem	tmp;
	int		i;

	if (a->size < 2)
		return ;
	tmp = a->data[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = tmp;
	write(1, "rra\n", 4);
	move_count++;
}

void	rrb(t_stack *b)
{
	t_elem	tmp;
	int		i;

	if (b->size < 2)
		return ;
	tmp = b->data[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = tmp;
	write(1, "rrb\n", 4);
	move_count++;
}
