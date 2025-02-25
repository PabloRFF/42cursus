#include <fcntl.h>
#include "get_next_line.h"

static int	read_and_append(int fd, char **buffer)
{
	char	*temp_buffer;
	int		bytes_read;
	char	*new_buf;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (-1);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		temp_buffer[bytes_read] = '\0';
		new_buf = ft_strjoin(*buffer, temp_buffer);
		free(*buffer);
		*buffer = new_buf;
	}
	free(temp_buffer);
	return (bytes_read);
}

static char	*extract_line(char **buffer)
{
	char	*newline;
	char	*line;
	char	*rest;

	newline = ft_strchr(*buffer, '\n');
	if (newline)
	{
		*newline++ = '\n';
		line = ft_strdup(*buffer);
		rest = ft_strdup(newline + 1);
		free(*buffer);
		*buffer = rest;
	}
	else
	{
		line = ft_strdup(*buffer);
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

	buffer = NULL;
	bytes_read = 1;
	while (bytes_read != 0 || !ft_strchr(buffer, '\n'))
	{
		bytes_read = read_and_append(fd, &buffer);
		if (bytes_read <= 0)
			break ;
	}
	if (buffer && *buffer)
		return (extract_line(&buffer));
	return (NULL);
}

int main() {
	int fd = open("archivo.txt", O_RDONLY);
	if (fd == -1) {
		printf("Error abriendo el archivo\n");
		return 1;
	}

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	close(fd);
	return 0;
}