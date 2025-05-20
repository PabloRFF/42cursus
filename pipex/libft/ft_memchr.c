/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:23:35 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/03 14:27:42 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i ++;
	}
	return (NULL);
}

/* int main()
{
	char *str= "Holamellamopablo";
	int find = 'm';
	size_t n = 5;

	printf("A partir de %c = %s\n", find, (char *)ft_memchr(str, find, n));
	return 0;
} */