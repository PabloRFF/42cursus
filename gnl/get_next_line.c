/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:09:20 by pablrome          #+#    #+#             */
/*   Updated: 2025/03/04 18:37:31 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

static int	read_and_append(int fd, char **buffer)
{
	char	*temp_buffer;
	int		bytes_read;
	char	*new_buf;

	temp_buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (-1);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		temp_buffer[bytes_read] = '\0';
		new_buf = ft_strjoin(*buffer, temp_buffer);
		if (!new_buf)
		{
			free(temp_buffer);
			return (-1);
		}
		free(*buffer);
		*buffer = new_buf;
	}
	free(temp_buffer);
	return (bytes_read);
}

static char	*extract_line(char **buffer)
{
    char	*line;
    char	*aux;
    int		i = 0;

    while ((*buffer)[i] && (*buffer)[i] != '\n')
        i++;
    if ((*buffer)[i] == '\n')
        line = ft_substr(*buffer, 0, i + 1);
    else
        line = ft_substr(*buffer, 0, i);
    aux = ft_strchr(*buffer, '\n');
    if (aux)
    {
        char *temp = ft_strdup(aux + 1);
		if (!temp)
			return (NULL);
        free(*buffer);
        *buffer = temp;
    }
    else
    {
        free(*buffer);
        *buffer = NULL;
    }
    return (line);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*newline;
	int			bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (free(bufferNULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read_and_append(fd, &buffer);
		if (bytes_read == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	}
	newline = extract_line(&buffer);
	if (newline && newline[0] == '\0')
	{
		free(newline);
		newline = NULL;
	}
	return (newline);
}

// int main(void)
// {
//     int		fd;
//     char	*line;

//     fd = open("archivo.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error abriendo archivo.txt");
//         return (1);
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }