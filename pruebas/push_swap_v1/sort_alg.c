/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:53:09 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/25 16:02:14 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *b)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < b->size)
	{
		if (b->data[i].index > b->data[max].index)
			max = i;
		i++;
	}
	return (max);
}

void	rotate_b_to_top(t_stack *b, int pos)
{
	if (pos <= b->size / 2)
		while (pos-- > 0)
			rb(b);
	else
		while (pos++ < b->size)
			rrb(b);
}

static void	push_chunks(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;
	int	pushed;
	int	total;

	i = 0;
	pushed = 0;
	total = a->size;
	while (pushed < total)
	{
		if (a->data[0].index <= i)
		{
			pb(a, b);
			rb(b);
			pushed++;
			i++;
		}
		else if (a->data[0].index <= i + chunk_size)
		{
			pb(a, b);
			pushed++;
			i++;
		}
		else
			ra(a);
	}
}

void	sort_alg(t_stack *a, t_stack *b)
{
	int	pos;
	int	chunk_size;

	if (a->size <= 5)
	{
		if (a->size == 2)
			sort_two(a);
		else if (a->size == 3)
			sort_three(a);
		else if (a->size <= 5)
			sort_five(a, b);
		return ;
	}
	if (a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks(a, b, chunk_size);
	push_chunks(a, b, chunk_size);
	while (b->size > 0)
	{
		pos = find_max_index(b);
		rotate_b_to_top(b, pos);
		pa(a, b);
	}
}
