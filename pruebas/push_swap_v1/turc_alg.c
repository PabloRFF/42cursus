/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turc_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:53:09 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/23 17:57:35 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		while (i++ < pos)
			rb(b);
	else
		while (i++ < b->size - pos)
			rrb(b);
}

static int	find_best_push_position(t_stack *a, int current_max)
{
	int	i;
	int	j;

	i = 0;
	j = a->size - 1;
	while (i <= j)
	{
		if (a->data[i].index <= current_max)
			return (i);
		if (a->data[j].index <= current_max)
			return (j);
		i++;
		j--;
	}
	return (-1);
}

static void	move_to_top_a(t_stack *a, int pos)
{
	int	i;

	i = 0;
	if (pos <= a->size / 2)
		while (i++ < pos)
			ra(a);
	else
		while (i++ < a->size - pos)
			rra(a);
}

static void	push_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int	pushed;
	int	current_max;
	int	pos;

	current_max = chunk_size - 1;
	pushed = 0;
	while (a->size > 0)
	{
		pos = find_best_push_position(a, current_max);
		if (pos == -1)
		{
			current_max += chunk_size;
			continue;
		}
		move_to_top_a(a, pos);
		pb(a, b);
		pushed++;
		if (b->size > 1 && b->data[0].index < current_max - (chunk_size / 2))
			rb(b);
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
