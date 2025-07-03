/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:03:15 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 16:19:25 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.moves = 0;
	if (argc != 2)
		return (write(2, "Uso: ./so_long <mapa.ber>\n", 27), 1);
	if (!load_map(&game, argv[1]))
		return (1);
	if (!scan_map(&game))
		return (free_map(game.map), 1);
	if (!validate_map(&game))
		return (free_map(game.map), 1);
	game_init(&game);
	return (0);
}
