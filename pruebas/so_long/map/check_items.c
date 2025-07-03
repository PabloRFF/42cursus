/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:08:00 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 16:09:32 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_items(t_game *g, int *exits, int *collectibles, int *players)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			if (g->map[i][j] == 'E')
				(*exits)++;
			else if (g->map[i][j] == 'C')
				(*collectibles)++;
			else if (g->map[i][j] == 'P')
			{
				(*players)++;
				g->player_x = j;
				g->player_y = i;
			}
			j++;
		}
		i++;
	}
}
