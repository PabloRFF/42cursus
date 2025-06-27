/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:05:34 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/27 14:40:44 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	count_lines(const char *file)
{
	int		fd;
	int		count;
	char	c;

	fd = open(file, O_RDONLY);
	count = 0;
	while (fd >= 0 && read(fd, &c, 1) > 0)
		if (c == '\n')
			count++;
	close(fd);
	if (fd < 0)
		return (-1);
	else
		return (count + 1);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
