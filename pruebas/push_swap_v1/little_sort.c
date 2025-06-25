/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:41:10 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/25 16:06:37 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	f;
	int	s;
	int	t;

	f = a->data[0].value;
	s = a->data[1].value;
	t = a->data[2].value;
	if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t && f > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}

void	sort_two(t_stack *a)
{
	if (a->data[0].value > a->data[1].value)
		sa(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	max_index;

	while (a->size > 3)
	{
		if (a->data[0].index <= 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while (b->size > 0)
	{
		max_index = find_max_index(b);
		rotate_b_to_top(b, max_index);
		pa(a, b);
	}
}
