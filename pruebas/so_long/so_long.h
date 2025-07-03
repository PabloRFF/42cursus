/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:41:38 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 16:21:41 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_game	t_game;
# define TILE_SIZE 64
# include "map/map.h"
# include "game/game.h"
# include "render/render.h"
# include "events/events.h"
# include "utils/utils.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		moves;
	int		collectibles;
	int		collected;
	int		player_x;
	int		player_y;
	int		current_frame;

	// Imágenes:
	void	*img_floor;
	void	*img_exit;
	void	*img_collectible;
	void	*walls[2];
	void	*player_frames[2];
}	t_game;

#endif