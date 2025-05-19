/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:16:11 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/19 20:17:05 by pablrome         ###   ########.fr       */
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
void	exit_error(char *msg);
void	check_args(int argc, char *argv[]);
void	free_split(char **array);
char	*get_path(char *cmd, char **envp);
pid_t	create_process(void);
void	child_two(char *cmd_str, int output_fd, int *pip, char **envp);
void	child_one(char *cmd_str, int input_fd, int *pip, char **envp);

#endif