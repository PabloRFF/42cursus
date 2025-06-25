/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:29:24 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/25 14:59:01 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_to_numbers(char *str, t_stack *a)
{
	char	**numbers;
	int		i;

	numbers = ft_split(str, ' ');
	if (!numbers || !numbers[0])
		return (write(1, "Ussage: ./push_swap <n> <n> ...\n", 33), exit(1));
	i = 0;
	while (numbers[i])
	{
		if (!add_number(a, numbers[i]))
		{
			write(2, "Error\n", 6);
			ft_free_matrix(numbers);
			exit(1);
		}
		i++;
	}
	ft_free_matrix(numbers);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	a.size = 0;
	b.size = 0;
	if (argc < 2)
		return (write(1, "Error. Ussage: ./push_swap <n> <n> ...\n", 39), 1);
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
	return (sort_alg(&a, &b), 0);
}
