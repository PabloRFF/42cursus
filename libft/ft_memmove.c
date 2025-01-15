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

void	*ft_memmove(void *dest, void *src, size_t n)
{
	if (dest == NULL || src == NULL)
		return NULL;
	unsigned char	*d = dest;
	unsigned char	*s = src;

	if (d > s && d < s + n)
	{
		d += n;
		s += n;
		while (n--)
		{
			*(--d) = *(--s);
		}
	}
	else
	{
		while (n--)
		{
			*d++ = *s++;
		}		
	}
	return dest;
}

// #include <string.h>  // Para memmove
// #include <stdio.h>
// int main() {
//     char arr1[] = "ABCDEFGHI";  // Arreglo original
//     char arr2[] = "ABCDEFGHI";  // Arreglo original

//     // Queremos mover los 3 primeros caracteres (ABC) a la posición donde está 'E'
//     memmove(arr1 + 4, arr1, 3);  // Copia de arr[0..2] a arr[4..6]

// 	ft_memmove(arr2 + 4, arr2, 3);

//     printf("Resultado original: %s\n", arr1);  // Esperado: "ABCDEFABC"
// 	printf("Resultado mi funcion: %s\n", arr2);  // Esperado: "ABCDEFABC"

//     return 0;
// }