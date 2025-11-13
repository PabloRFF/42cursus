/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:54:50 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 18:54:58 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCT_H
# define GAME_STRUCT_H

# define TILE_SIZE 64

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
	void	*img_floor;
	void	*img_exit;
	void	*img_collectible;
	void	*walls[2];
	void	*player_frames[2];
}	t_game;

#endif
