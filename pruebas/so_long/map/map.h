/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:41:05 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 16:09:59 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../so_long.h"

int		load_map(t_game *game, char *file);
int		validate_map(t_game *game);
int		check_walls(t_game *game);
int		check_path(t_game *game);
int		scan_map(t_game *game);
void	count_items(t_game *game, int *exits, int *collectibles, int *players);

#endif