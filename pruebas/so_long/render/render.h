/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:21:26 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/30 15:20:24 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../so_long.h"

void	render_map(t_game *game);
void	load_images(t_game *game, int *w, int *h);

#endif