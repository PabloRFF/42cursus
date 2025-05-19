/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:26:52 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/19 18:19:02 by pablrome         ###   ########.fr       */
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

void	child_one(char *cmd_str, int input_fd, int *pip, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(cmd_str, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free(path);
		free_split(cmd);
		exit(write(2, "Command not found\n", 18));
	}
	dup2(input_fd, STDIN_FILENO);
	dup2(pip[1], STDOUT_FILENO);
	close(pip[0]);
	close(pip[1]);
	close(input_fd);
	execve(path, cmd, envp);
	perror("execve");
	free(path);
	free_split(cmd);
	exit(1);
}

void	child_two(char *cmd_str, int output_fd, int *pip, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(cmd_str, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free(path);
		free_split(cmd);
		exit(write(2, "Command not found\n", 18));
	}
	dup2(pip[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(pip[0]);
	close(pip[1]);
	close(output_fd);
	execve(path, cmd, envp);
	perror("execve");
	free(path);
	free_split(cmd);
	exit(1);
}

int	create_process(void)
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
	int		pip[2];
	int		input_fd;
	int		output_fd;
	pid_t	pid1;
	pid_t	pid2;

	check_args(argc, argv);
	input_fd = open_input(argv[1]);
	output_fd = open_output(argv[4]);
	if (pipe(pip) < 0)
		return (perror("pipe"), 1);
	pid1 = create_process();
	if (pid1 == 0)
		child_one(argv[2], input_fd, pip, envp);
	pid2 = create_process();
	if (pid2 == 0)
		child_two(argv[3], output_fd, pip, envp);
	close(input_fd);
	close(output_fd);
	close(pip[0]);
	close(pip[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
