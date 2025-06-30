/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:20:47 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/30 15:50:00 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
// #include "render/render.h"
// #include "map/map.h"
// #include "utils/utils.h"

void	game_init(t_game *g)
{
	int	w;
	int	h;

	g->mlx = mlx_init();
	if (!g->mlx)
		exit(write(2, "Error: mlx_init failed\n", 23));

	g->win = mlx_new_window(
			g->mlx,
			g->width * TILE_SIZE,
			g->height * TILE_SIZE,
			"So Long"
			);

	load_images(g, &w, &h);
	render_map(g);

	mlx_hook(g->win, 17, 0, close_game, g);
	mlx_loop(g->mlx);
}

