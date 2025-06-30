/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:22:33 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/30 16:53:17 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	put_wall(t_game *g, int x, int y)
{
	void	*img;

	if (y == 0 || y == g->height - 1)
		img = g->walls[0];
	else if (x == 0 || x == g->width - 1)
		img = g->walls[1];
	else
		img = g->walls[0];

	if (!img)
	{
		printf("ERROR: Wall image is NULL at (%d,%d)\n", x, y);
		exit(1);
	}
	mlx_put_image_to_window(g->mlx, g->win, img, x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_floor_or_wall(t_game *g, char c, int x, int y)
{
	if (c == '1')
		put_wall(g, x, y);
	else
	{
		if (!g->img_floor)
		{
			printf("ERROR: Floor image is NULL\n");
			exit(1);
		}
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	}
}

static void	render_entity(t_game *g, char c, int x, int y)
{
	if (c == 'P')
	{
		if (!g->player_frames[0])
			exit(printf("ERROR: Player image NULL\n"));
		mlx_put_image_to_window(g->mlx, g->win,
			g->player_frames[0], x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (c == 'C')
	{
		if (!g->img_collectible)
			exit(printf("ERROR: Collectible image NULL\n"));
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (c == 'E')
	{
		if (!g->img_exit)
			exit(printf("ERROR: Exit image NULL\n"));
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	render_tile(t_game *g, int x, int y)
{
	char	c;

	if (!g->mlx || !g->win)
		exit(printf("ERROR: MLX or window NULL\n"));
	if (x < 0 || y < 0 || x >= g->width || y >= g->height)
		exit(printf("ERROR: Out of bounds (%d,%d)\n", x, y));
	if (!g->map || !g->map[y])
		exit(printf("ERROR: Map NULL at row %d\n", y));

	c = g->map[y][x];
	render_floor_or_wall(g, c, x, y);
	render_entity(g, c, x, y);
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
