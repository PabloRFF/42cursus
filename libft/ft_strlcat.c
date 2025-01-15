/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:19:15 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/15 20:16:08 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len ;
	unsigned int	src_len ;
	unsigned int	i ;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	i = 0;
	while (src[i] != '\0' && dest_len + i < size -1)
	{
		dest[dest_len + i] = src[i];
		i ++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>

// int main() {
//  char dest[20] = "Hola, ";
// 	char src[] = "mundo!";

// 	int longitud = ft_strlcat(dest, src, 12);
// 	printf("%s\n", dest); 
// 	printf("Longitud: %d\n", longitud);
// }