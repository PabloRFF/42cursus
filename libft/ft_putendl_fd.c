#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	len;
	int i;

	if (!s)
		return ;
	if (fd < 0)
		return ;
	i = 0;
	len = ft_strlen(s);
	while(i < len)
	{
		write(fd, &s[i], 1);
		i ++;
	}
	write(fd, "\n", 1);
}