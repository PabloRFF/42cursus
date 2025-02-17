/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:09:00 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/13 14:37:22 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*newline;
	char        *temp_buffer;
	int			bytes_leidos;

	while ((bytes_leidos = read(fd, temp_buffer, BUFFER_SIZE)) > 0)
	{
		newline = ft_strchr(temp_buffer, '\n');
		if(!newline)
		{
			return temp_buffer;
		}
		else
		{
			*newline = '\0';
			return temp_buffer;
			buffer = ft_strdup(newline + 1);
			printf("Restante del buffer: %s\n", buffer);
			break;
		}
	}
	return "";
}

int main() {
	int fd = open("archivo.txt", O_RDONLY);
	if (fd == -1) {
		printf("Error abriendo el archivo\n");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL) {
		printf("Linea:%s\n", line);
		free(line);
	}

	close(fd);
	return 0;
}