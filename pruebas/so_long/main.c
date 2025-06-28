/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:03:15 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/28 16:34:02 by pablrome         ###   ########.fr       */
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

	if (argc != 2 || !check_extension(argv[1]))
		return (write(2, "Error\nUso: ./so_long mapa.ber\n", 31), 1);
	if (!load_map(&game, argv[1]))
		return (1);
	if (!validate_map(&game))
		return (free_map(game.map), 1);
	game_init(&game);
	return (0);
}
