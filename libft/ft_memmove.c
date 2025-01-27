/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:33:50 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/15 19:08:03 by pablrome         ###   ########.fr       */
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

    // Test non-overlapping
    ft_memmove(buffer2, buffer1, strlen(buffer1) + 1);
    printf("Non-overlapping: %s\n", buffer2);

    // Test overlapping (src before dest)
    ft_memmove(buffer1 + 7, buffer1, 6); // Move "Hello" to "World!"
    printf("Overlapping (src before dest): %s\n", buffer1);

    // Reset buffer1
    strcpy(buffer1, "Hello, World!");

    // Test overlapping (dest before src)
    ft_memmove(buffer1, buffer1 + 7, 6); // Move "World!" to "Hello"
    printf("Overlapping (dest before src): %s\n", buffer1);

    return 0;
} */