/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:22:29 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/28 16:25:29 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../events/events.h"

void	load_images(t_game *g, int *w, int *h)
{
	g->img_wall = mlx_xpm_file_to_image(g->mlx,
			"assets/wall.xpm", w, h);
	g->img_floor = mlx_xpm_file_to_image(g->mlx,
			"assets/floor.xpm", w, h);
	g->img_player = mlx_xpm_file_to_image(g->mlx,
			"assets/player.xpm", w, h);
	g->img_exit = mlx_xpm_file_to_image(g->mlx,
			"assets/exit.xpm", w, h);
	g->img_collectible = mlx_xpm_file_to_image(g->mlx,
			"assets/collectible.xpm", w, h);
	if (!g->img_wall || !g->img_floor || !g->img_player
		|| !g->img_exit || !g->img_collectible)
	{
		write(2, "Error: Failed to load images\n", 30);
		close_game(g);
	}
}
