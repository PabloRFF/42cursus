/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:09:20 by pablrome          #+#    #+#             */
/*   Updated: 2025/03/11 14:42:29 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (ptr);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

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
	char	*aux;
	char	*line;
	int		i;
	char	*temp;

	i = 0;
	while ((*buffer)[i] != '\0' && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		line = ft_substr(*buffer, 0, i + 1);
	else
		line = ft_substr(*buffer, 0, i);
	aux = ft_strchr(*buffer, '\n');
	if (aux)
	{
		temp = ft_strdup(aux + 1);
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

	bytes_read = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(sizeof(char), 1);
	if (!buffer)
		return (NULL);
	while (bytes_read != 0 && buffer && !ft_strchr(buffer, '\n'))
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
		return (free(newline), (NULL));
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