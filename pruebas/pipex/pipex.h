/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:16:11 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/12 18:09:52 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>

int		open_output(char *outfile);
int		open_input(char *infile);
void	exit_error(void);
void	check_args(int argc, char *argv[]);
char	*get_path(char *cmd, char **envp);
pid_t	create_process(void);
void	exec_child(char **cmd, int output_fd, int *pip, char **envp);
void	exec_parent(char **cmd, int input_fd, int *pip, char **envp);

#endif