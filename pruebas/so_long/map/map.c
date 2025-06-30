/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:38:50 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/30 16:10:23 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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
	if (!check_walls(game))
		return (0);
	if (!check_path(game))
		return (0);
	return (1);
}

