/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:29:09 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/23 18:22:02 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

bool	has_duplicate(t_stack *a, int num)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i].value == num)
			return (true);
		i++;
	}
	return (false);
}

bool	add_number(t_stack *a, const char *arg)
{
	long	n;

	if (!is_number(arg))
		return (false);
	//n = strtol(arg, NULL, 10);
	n = (long)ft_atoi(arg);
	if (n < INT_MIN || n > INT_MAX)
		return (false);
	if (has_duplicate(a, (int)n))
		return (false);
	a->data[a->size].value = (int)n;
	a->data[a->size].index = -1;
	a->size++;
	return (true);
}
