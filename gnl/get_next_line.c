/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:41:37 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/13 14:28:08 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdlib.h>
// #include <string.h>

// #define BUFFER_SIZE 15

// static char	*handle_newline_case(char **buffer, char *newline)
// {
// 	size_t	line_len = newline - *buffer + 1;
// 	char	*line = malloc(line_len + 1);
// 	char	*remaining;

// 	if (!line)
// 	{
// 		free(*buffer);
// 		*buffer = NULL;
// 		return (NULL);
// 	}
// 	strncpy(line, *buffer, line_len);
// 	line[line_len] = '\0';
// 	remaining = strdup(newline + 1);
// 	free(*buffer);
// 	*buffer = remaining;
// 	return (line);
// }

// static char	*handle_eof_case(char **buffer)
// {
// 	char	*line;

// 	if (*buffer == NULL || (*buffer)[0] == '\0')
// 	{
// 		free(*buffer);
// 		*buffer = NULL;
// 		return (NULL);
// 	}
// 	line = *buffer;
// 	*buffer = NULL;
// 	return (line);
// }

// static char	*read_loop(int fd, char **buffer, ssize_t *bytes_read)
// {
// 	char	temp[BUFFER_SIZE + 1];
// 	char	*newline;

// 	newline = NULL;
// 	while ((newline = strchr(*buffer, '\n')) == NULL)
// 	{
// 		*bytes_read = read(fd, temp, BUFFER_SIZE);
// 		if (*bytes_read <= 0)
// 			break ;
// 		temp[*bytes_read] = '\0';
// 		char *new_buffer = realloc(*buffer, strlen(*buffer) + *bytes_read + 1);
// 		if (!new_buffer)
// 		{
// 			free(*buffer);
// 			*buffer = NULL;
// 			return (NULL);
// 		}
// 		*buffer = new_buffer;
// 		strcat(*buffer, temp);
// 	}
// 	return (newline);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	ssize_t		bytes_read;
// 	char		*newline;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!buffer && !(buffer = strdup("")))
// 		return (NULL);
// 	bytes_read = 0;
// 	newline = read_loop(fd, &buffer, &bytes_read);
// 	if (bytes_read == -1)
// 	{
// 		free(buffer);
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	if (newline)
// 		return (handle_newline_case(&buffer, newline));
// 	else
// 		return (handle_eof_case(&buffer));
// }

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 15

// Lee los datos del archivo en bloques de BUFFER_SIZE
static ssize_t read_file(int fd, char **buffer)
{
    char temp[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    bytes_read = read(fd, temp, BUFFER_SIZE);
    if (bytes_read <= 0)
        return bytes_read;
    temp[bytes_read] = '\0';
    *buffer = realloc(*buffer, strlen(*buffer) + bytes_read + 1);
    if (!*buffer)
        return -1;
    strcat(*buffer, temp);
    return bytes_read;
}

// Extrae una línea del buffer hasta el salto de línea
static char *extract_line(char **buffer)
{
    char *line;
    char *newline_pos = strchr(*buffer, '\n');

    if (newline_pos)
    {
        *newline_pos = '\0';
        line = strdup(*buffer);
        memmove(*buffer, newline_pos + 1, strlen(newline_pos + 1) + 1);
    }
    else
    {
        line = strdup(*buffer);
        free(*buffer);
        *buffer = NULL;
    }
    return line;
}

// Función principal que lee la siguiente línea del archivo
char *get_next_line(int fd)
{
    static char *buffer = NULL;
    ssize_t bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    if (!buffer && !(buffer = strdup("")))
        return NULL;

    while (1)
    {
        bytes_read = read_file(fd, &buffer);
        if (bytes_read <= 0)
            return (bytes_read == 0 && buffer && buffer[0] != '\0') ? extract_line(&buffer) : NULL;
        if (strchr(buffer, '\n'))
            return extract_line(&buffer);
    }
}


#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error abriendo el archivo");
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