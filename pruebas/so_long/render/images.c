/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:22:29 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 16:18:22 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../events/events.h"

void	load_images(t_game *g, int *w, int *h)
{
	g->img_floor = mlx_xpm_file_to_image(g->mlx,
			"assets/floor.xpm", w, h);
	g->img_exit = mlx_xpm_file_to_image(g->mlx,
			"assets/exit.xpm", w, h);
	g->img_collectible = mlx_xpm_file_to_image(g->mlx,
			"assets/collectible.xpm", w, h);
	g->walls[0] = mlx_xpm_file_to_image(g->mlx,
			"assets/wall_vertical.xpm", w, h);
	g->walls[1] = mlx_xpm_file_to_image(g->mlx,
			"assets/wall_horizontal.xpm", w, h);
	g->player_frames[0] = mlx_xpm_file_to_image(g->mlx,
			"assets/player_0.xpm", w, h);
	g->player_frames[1] = mlx_xpm_file_to_image(g->mlx,
			"assets/player_1.xpm", w, h);
	printf("floor: %dx%d\n", *w, *h);
	printf("wall_horizontal: %dx%d\n", *w, *h);
}
