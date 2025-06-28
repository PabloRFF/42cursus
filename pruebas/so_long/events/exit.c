/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:26:32 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/28 16:27:30 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	close_game(t_game *game)
{
	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	exit(0);
}
