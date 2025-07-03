/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:26:32 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 15:41:52 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	close_game(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->walls[0])
		mlx_destroy_image(game->mlx, game->walls[0]);
	if (game->walls[1])
		mlx_destroy_image(game->mlx, game->walls[1]);
	if (game->player_frames[0])
		mlx_destroy_image(game->mlx, game->player_frames[0]);
	if (game->player_frames[1])
		mlx_destroy_image(game->mlx, game->player_frames[1]);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	exit(0);
	return (0);
}
