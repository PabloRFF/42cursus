/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:38:50 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/26 13:52:36 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	load_map(t_game *game, char *file)
{
	int	i;
	int	line_length;

	game->height = count_lines(file);
	if (game->height <= 0)
		return (write(2, "Error: Invalid map file\n", 24), 0);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (write(2, "Error: Memory allocation failed\n", 33), 0);
	game->width = (int)ft_strlen(game->map[0]);
	i = 0;
	while (i < game->height)
	{
		line_length = ft_strlen(game->map[i]);
		if (game->map[i][line_length - 1] == '\n')
			line_length--;
		if (line_length != game->width)
			return (write(2, "Error: Wrong map\n", 17), free_map(game->map), 0);
		return (1);
	}
}

int	validate_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' &&
				game->map[i][j] != 'C' && game->map[i][j] != 'E' &&
				game->map[i][j] != 'P')
			{
				return (write(2, "Error: Invalid character in map\n", 32), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

