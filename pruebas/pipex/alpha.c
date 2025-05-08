/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:26:52 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/08 20:39:38 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char *argv[])
{
	int		output_fd;
	int		pipe_fds[2];
	pid_t	process_id;
	char	buffer[1024];
	ssize_t	bytes_read;

	if (argc < 2)
	{
		printf("Numero de argumentos invalido\n");
		return (1);
	}
	if (pipe(pipe_fds) == -1)
	{
		perror("Error creating pipe");
		return (1);
	}
	process_id = fork();
	if (process_id == -1)
	{
		perror("Error during fork");
		return (1);
	}
	if (process_id == 0) // Child process
	{
		close(pipe_fds[0]);
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]);
		execvp(argv[1], &argv[1]);
		perror("Error executing command");
		exit(1);
	}
	else
	{
		close(pipe_fds[1]);
		output_fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (output_fd == -1)
		{
			perror("Error opening output file");
			close(pipe_fds[0]);
			return (1);
		}
		while ((bytes_read = read(pipe_fds[0], buffer, sizeof(buffer) -1)) > 0)
		{
			buffer[bytes_read] = '\0';
			write(output_fd, buffer, bytes_read);
		}
		close(pipe_fds[0]);
		close(output_fd);
		printf("Command output saved to 'salida.txt'.\n");
	}
	return (0);
}