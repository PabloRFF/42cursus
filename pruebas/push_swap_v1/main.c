/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:29:24 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/19 20:24:59 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	g_move_count = 0;

void	argv_to_numbers(char *str, t_stack *a)
{
	char	**numbers;
	int		i;

	numbers = ft_split(str, ' ');
	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
	{
		if (!add_number(a, numbers[i]))
		{
			write(2, "Error\n", 6);
			free(numbers);
			return ;
		}
		i++;
	}
	free(numbers);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	a.size = 0;
	b.size = 0;
	if (argc < 2)
	{
		printf("Error: No arguments provided.\n");
		return (1);
	}
	i = 1;
	if (argc == 2)
		argv_to_numbers(argv[1], &a);
	else
	{
		while (i < argc)
		{
			if (!add_number(&a, argv[i]))
				return (write(2, "Error\n", 6), 1);
			i++;
		}
	}
	assign_indices(&a);
	turco(&a, &b);
	return (printf("Total movimientos: %d\n", g_move_count), 0);
}
