/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:22:33 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/28 16:33:34 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	render_tile(t_game *g, int x, int y)
{
	char	c;

	c = g->map[y][x];
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img_floor,
			x * TILE_SIZE, y * TILE_SIZE);
	if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img_player,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_collectible,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_exit,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			render_tile(g, x, y);
			x++;
		}
		y++;
	}
}
