/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:26:52 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/12 19:24:58 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int argc, char *argv[])
{
	(void)argv;
	if (argc != 5)
	{
		write(2, "Error: Invalid number of arguments\n", 36);
		exit(1);
	}
}

void	exec_child(char **cmd, int output_fd, int *pip, char **envp)
{
	char	*path;

	path = get_path(cmd[0], envp);
	if (path == NULL)
	{
		perror("Command not found");
		exit(1);
	}
	close(pip[1]);
	dup2(pip[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(pip[0]);
	close(output_fd);
	execve(path, cmd, envp);
	perror("execve");
	exit(1);
}

void	exec_parent(char **cmd, int input_fd, int *pip, char **envp)
{
	char	*path;

	path = get_path(cmd[0], envp);
	if (path == NULL)
	{
		perror("Command not found");
		exit(1);
	}
	close(pip[0]);
	dup2(input_fd, STDIN_FILENO);
	dup2(pip[1], STDOUT_FILENO);
	close(pip[1]);
	close(input_fd);
	execve(path, cmd, envp);
	perror("execve");
	exit(1);
}

pid_t	create_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Error al crear el proceso");
		exit(1);
	}
	return (pid);
}

int	main(int argc, char *argv[], char **envp)
{
	int		output_fd;
	int		input_fd;
	int		pip[2];
	pid_t	pid;
	char	**cmd;

	check_args(argc, argv);
	input_fd = open_input(argv[1]);
	output_fd = open_output(argv[4]);
	pipe(pip);
	pid = create_process();
	if (pid == 0)
	{
		cmd = ft_split(argv[3], ' ');
		exec_child(cmd, output_fd, pip, envp);
		free(cmd);
	}
	else
	{
		cmd = ft_split(argv[2], ' ');
		exec_parent(cmd, input_fd, pip, envp);
		free(cmd);
	}
	return (0);
}
