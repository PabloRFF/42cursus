/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:34:44 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/20 12:39:03 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_input(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		exit_error("Error opening input file");
	return (fd);
}

int	open_output(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit_error("Error opening output file");
	return (fd);
}

void	exit_error(char *msg)
{
	if (msg)
	{
		ft_printf("%s\n", msg);
		exit(1);
	}
	else
		ft_putstr_fd("Error\n", 2);
}

void	free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*temp;
	int		i;
	int 	no_path = 0;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i] || ft_strchr(cmd, '/'))
		no_path = 1;
	else
		paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (!no_path && paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	if(no_path)
		return (ft_strdup(cmd));
	i = -1;
	ft_free_matrix(paths);
	return (0);
}
