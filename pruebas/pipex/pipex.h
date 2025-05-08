#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>

int	    open_output();
int	    open_input();
void	exit_error();
int		main(int argc, char *argv[]);

#endif