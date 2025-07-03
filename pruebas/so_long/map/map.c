/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:38:50 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 16:18:03 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_min_items(t_game *g)
{
	int	exits;
	int	collectibles;
	int	players;

	exits = 0;
	collectibles = 0;
	players = 0;
	count_items(g, &exits, &collectibles, &players);
	if (exits == 0)
		return (write(2, "Error: No exit in map\n", 23), 0);
	if (collectibles == 0)
		return (write(2, "Error: No collectibles in map\n", 31), 0);
	if (players == 0)
		return (write(2, "Error: No player in map\n", 24), 0);
	if (players > 1)
		return (write(2, "Error: Multiple players in map\n", 32), 0);
	return (1);
}

static int	read_map_lines(t_game *g, int fd)
{
	int		i;
	int		len;

	i = 0;
	while (i < g->height)
	{
		g->map[i] = read_line(fd);
		if (!g->map[i])
			return (write(2, "Error: read fail\n", 17), free_map(g->map), 0);
		len = ft_strlen(g->map[i]);
		if (g->map[i][len - 1] == '\n')
			len--;
		if (i == 0)
			g->width = len;
		else if (len != g->width)
			return (write(2, "Error: wrong size\n", 18), free_map(g->map), 0);
		i++;
	}
	g->map[i] = NULL;
	return (1);
}

int	load_map(t_game *g, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error: cannot open file\n", 25), 0);
	g->height = count_lines(file);
	if (g->height <= 0)
		return (write(2, "Error: empty map\n", 18), close(fd), 0);
	g->map = malloc(sizeof(char *) * (g->height + 1));
	if (!g->map)
		return (write(2, "Error: malloc failed\n", 22), close(fd), 0);
	if (!read_map_lines(g, fd))
		return (close(fd), 0);
	close(fd);
	return (1);
}

static int	check_valid_chars(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->height)
	{
		j = 0;
		while (j < g->width)
		{
			if (g->map[i][j] != '1' && g->map[i][j] != '0' &&
				g->map[i][j] != 'C' && g->map[i][j] != 'E' &&
				g->map[i][j] != 'P')
				return (write(2, "Error: Invalid character in map\n", 32), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!check_valid_chars(game))
		return (0);
	if (!check_min_items(game))
		return (0);
	if (!check_walls(game))
		return (0);
	if (!check_path(game))
		return (0);
	return (1);
}
