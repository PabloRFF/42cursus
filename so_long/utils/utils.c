/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:05:34 by pablrome          #+#    #+#             */
/*   Updated: 2025/06/30 16:09:51 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_LINE_LEN 1024
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

static int	read_char(int fd, char *c)
{
	int	bytes;

	bytes = read(fd, c, 1);
	if (bytes <= 0)
		return (0);
	return (1);
}

static int	fill_buffer(char *buf, int fd)
{
	int		i;
	char	c;

	i = 0;
	while (i < MAX_LINE_LEN - 1)
	{
		if (!read_char(fd, &c))
			break ;
		buf[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	buf[i] = '\0';
	return (i);
}

char	*read_line(int fd)
{
	char	buffer[MAX_LINE_LEN];
	char	*line;
	int		len;
	int		i;

	len = fill_buffer(buffer, fd);
	if (len == 0)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
