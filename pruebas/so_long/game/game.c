/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:20:47 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/28 16:20:55 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	game_init(t_game *game)
{
	int	img_w;
	int	img_h;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit(write(2, "Error: mlx_init failed\n", 23));

	game->win = mlx_new_window(
			game->mlx,
			game->width * TILE_SIZE,
			game->height * TILE_SIZE,
			"So Long"
			);

	load_images(game, &img_w, &img_h);
	render_map(game);

	mlx_key_hook(game->win, handle_input, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
