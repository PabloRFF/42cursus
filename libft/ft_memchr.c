/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:23:35 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/15 20:41:37 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t i;

	ptr = s;
	i = 0;

	while (i < n)
	{
		if (ptr[i] == (unsigned char)c) // Si encontramos el caracter, devolvemos su posicion de memoria
		{
			return (void *)(ptr + i);
		}
		i ++;
	}

	return NULL;// En caso de no encontrar nada
}