/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:31:43 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/03 14:15:45 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	unsigned char		*d;
	unsigned const char	*o;

	d = dest_str;
	o = src_str;
	if (dest_str == NULL && src_str == NULL)
		return (NULL);
	while (n--)
		*d++ = *o++;
	return (dest_str);
}

/* int main()
{
    char src[] = "Hola Mundo";
    char dest[20];
	//Sobreescribe
    ft_memcpy(dest, src, 10);
    printf("Destino después de memcpy: %s\n", dest);

    return 0;
} */