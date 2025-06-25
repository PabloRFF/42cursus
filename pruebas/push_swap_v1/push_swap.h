/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:44:54 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/25 16:06:38 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

# define MAX 1000

typedef struct s_elem
{
	int	value;
	int	index;
}	t_elem;

typedef struct s_stack
{
	t_elem	data[MAX];
	int		size;
}	t_stack;

/* main.c */
int		main(int argc, char **argv);

/* init.c */
bool	is_number(const char *str);
bool	has_duplicate(t_stack *a, int num);
bool	add_number(t_stack *a, const char *arg);

/* operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* little_sort.c */
void	sort_three(t_stack *a);
void	sort_two(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

/*sort_alg.c */
void	sort_alg(t_stack *a, t_stack *b);
int		find_max_index(t_stack *b);
void	rotate_b_to_top(t_stack *b, int pos);

/* utils.c */
void	assign_indices(t_stack *a);
void	print_stacks(t_stack *a, t_stack *b);

#endif
