/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:51:10 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/02 13:28:42 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	handle_input(int keycode, t_game *g)
{
	if (keycode == 53)
		close_game(g);

	else if (keycode == 119)
		move_player(g, 0, -1);
	else if (keycode == 115)
		move_player(g, 0, 1);
	else if (keycode == 97)
		move_player(g, -1, 0);
	else if (keycode == 100)
		move_player(g, 1, 0);

	return (0);
}
