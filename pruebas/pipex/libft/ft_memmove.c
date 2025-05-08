/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:33:50 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/03 14:56:47 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s && d < (s + n))
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

/* 
#include <string.h>

int main(void)
{
    char buffer1[50] = "Hello, World!";
    char buffer2[50];

    ft_memmove(buffer2, buffer1, strlen(buffer1) + 1);
    printf("Non-overlapping: %s\n", buffer2);

    // Solapamiento
    ft_memmove(buffer1 + 7, buffer1, 6);
    printf("Overlapping (src before dest): %s\n", buffer1);

    // Reseteamos la cadena original
    strcpy(buffer1, "Hello, World!");

    // Solapamiento
    ft_memmove(buffer1, buffer1 + 7, 6);
    printf("Overlapping (dest before src): %s\n", buffer1);

    return 0;
} */