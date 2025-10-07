/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:47:15 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 19:13:43 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	scan_map(t_game *g)
{
	int	y;
	int	x;

	g->collectibles = 0;
	g->collected = 0;
	y = 0;
	while (y < g->height)
	{
		if (!g->map[y])
			return (write(2, "Error: Null line in map\n", 24), 0);
		x = 0;
		while (g->map[y][x] && x < g->width)
		{
			if (g->map[y][x] == 'P')
			{
				g->player_x = x;
				g->player_y = y;
			}
			else if (g->map[y][x] == 'C')
				g->collectibles++;
			x++;
		}
		y++;
	}
	return (1);
}

static char	**copy_map(t_game *g)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (g->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < g->height)
	{
		copy[i] = ft_strdup(g->map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_path(t_game *game)
{
	char	**map_copy;
	int		start_x;
	int		start_y;
	int		i;
	int		j;

	map_copy = copy_map(game);
	if (!map_copy)
		return (write(2, "Error: malloc failed\n", 22), 0);
	start_x = game->player_x;
	start_y = game->player_y;
	flood_fill(map_copy, start_x, start_y);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
				return (ft_printf("FAIL:No solution\n"), free_map(map_copy), 0);
			j++;
		}
		i++;
	}
	return (free_map(map_copy), 1);
}

int	check_walls(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->width)
	{
		if (g->map[0][i] != '1' || g->map[g->height - 1][i] != '1')
			return (write(2, "Error: map not closed (top/bottom)\n", 36), 0);
		i++;
	}
	i = 1;
	while (i < g->height - 1)
	{
		if (g->map[i][0] != '1' || g->map[i][g->width - 1] != '1')
			return (write(2, "Error: map not closed (sides)\n", 31), 0);
		i++;
	}
	return (1);
}
