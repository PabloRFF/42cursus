/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:59:35 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/02 17:07:00 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_player(t_game *g, int dx, int dy)
{
	int		new_x = g->player_x + dx;
	int		new_y = g->player_y + dy;
	char	tile;

	if (new_x < 0 || new_x >= g->width || new_y < 0 || new_y >= g->height)
		return ;

	tile = g->map[new_y][new_x];

	if (tile == '1')
		return ;

	if (tile == 'C')
	{
		g->collected++;
		g->map[new_y][new_x] = '0';
		printf("Collectibles: %d/%d\n", g->collected, g->collectibles);
	}

	if (tile == 'E')
	{
		if (g->collected == g->collectibles)
		{
			printf("¡Has ganado! Todos los coleccionables recogidos.\n");
			close_game(g);
		}
		else
		{
			printf("¡Aún quedan coleccionables!\n");
			return ;
		}
	}

	g->map[g->player_y][g->player_x] = '0';
	g->map[new_y][new_x] = 'P';
	g->player_x = new_x;
	g->player_y = new_y;
	g->moves++;
	g->current_frame = (g->current_frame + 1) % 2;
	printf("Moves: %d\n", g->moves);

	render_map(g);
}
