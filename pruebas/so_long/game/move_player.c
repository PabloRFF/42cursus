/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:59:35 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 15:47:01 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	handle_tile(t_game *g, int new_x, int new_y)
{
	char	tile;

	tile = g->map[new_y][new_x];
	if (tile == '1')
		return (0);
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
			return (0);
		}
	}
	return (1);
}

void	move_player(t_game *g, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = g->player_x + dx;
	new_y = g->player_y + dy;
	if (new_x < 0 || new_x >= g->width || new_y < 0 || new_y >= g->height)
		return ;
	if (!handle_tile(g, new_x, new_y))
		return ;
	g->map[g->player_y][g->player_x] = '0';
	g->map[new_y][new_x] = 'P';
	g->player_x = new_x;
	g->player_y = new_y;
	g->moves++;
	g->current_frame = (g->current_frame + 1) % 2;
	printf("Moves: %d\n", g->moves);
	render_map(g);
}
