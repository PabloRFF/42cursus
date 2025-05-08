/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:26:52 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/08 21:32:09 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_input(char *infile)
{
	int fd;
	
	fd = open(infile, O_RDONLY);
	if(fd < 0)
		exit_error();
	return fd;
}

int	open_output(char *outfile)
{
	int fd;
	
	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd < 0)
		exit_error();	
	return fd;
}

void	exit_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int		main(int argc, char *argv[])
{
	int		output_fd;
	int		input_fd;
	int		pip[2];
	pid_t	pid;

	if (argc < 2)
	{
		printf("Numero de argumentos invalido\n");
		return (1);
	}
	input_fd = open_input(argv[1]);
	output_fd = open_output(argv[4]);
	pipe(pip);
	pid = fork();
	if(pid < 0)
	{
		close(input_fd);
		close(output_fd);
		exit_error();
		//free las cosas importantes
	}
	if (pid == 0) // Hijo
	{
		char **cmd = ft_split(argv[3], ' ');
		close(pip[1]);
		dup2(pip[0], STDIN_FILENO);
		dup2(output_fd, STDOUT_FILENO);
		close(pip[0]);
		close(output_fd);
		execvp(cmd[0], cmd);
	}
	else // Padre
	{
        char **cmd = ft_split(argv[2], ' ');
		close(pip[0]);
		dup2(input_fd, STDIN_FILENO);
		dup2(pip[1], STDOUT_FILENO);
		close(pip[1]);
		close(input_fd);
		execvp(cmd[0], cmd);
	}
	return (0);
}