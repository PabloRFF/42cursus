#include "push_swap.h"

static int	find_max_index(t_stack *b)
{
	int	i;
	int	max;

	max = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->data[i].index > b->data[max].index)
			max = i;
		i++;
	}
	return (max);
}

static void	rotate_b_to_top(t_stack *b, int pos)
{
	int	i;

	i = 0;
	if (pos <= b->size / 2)
	{
		while (i++ < pos)
			rb(b);
	}
	else
	{
		while (i++ < b->size - pos)
			rrb(b);
	}
}

static void	push_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int	total;
	int	current_max;
	int	pushed;

	total = a->size;
	current_max = chunk_size - 1;
	pushed = 0;
	while (a->size > 0)
	{
		if (a->data[0].index <= current_max)
		{
			pb(a, b);
			pushed++;
			if (b->size > 1 && b->data[0].index < current_max - (chunk_size / 2))
				rb(b);
		}
		else
			ra(a);
		if (pushed >= current_max + 1 && current_max < total - 1)
			current_max += chunk_size;
	}
}

void	turco(t_stack *a, t_stack *b)
{
	int	pos;
	int	chunk_size;

	chunk_size = (a->size <= 100) ? 15 : 30;
	push_chunks(a, b, chunk_size);
	while (b->size > 0)
	{
		pos = find_max_index(b);
		rotate_b_to_top(b, pos);
		pa(a, b);
	}
}
