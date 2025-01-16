/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:23:30 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/16 16:09:01 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	size_t	l_len;
	
	if (*little == '\0')
		return (char *)big;
	i = 0;
	l_len = ft_strlen(little);
	
	while (i + l_len <= len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (j < l_len && big[i + j] != little[j])
				j++;
			if (j = l_len)
				return (&big[i]);
		}
		i++;
	}
	return (NULL);
}

#include <stdio.h>
#include <string.h>
int main() {
    const char *haystack = "Hello, world!";
    const char *needle = "world";
    size_t len = 10;

    // Usando la función original strnstr
    char *result_original = strnstr(haystack, needle, len);
    
    // Usando tu función personalizada ft_strnstr
    char *result_custom = ft_strnstr(haystack, needle, len);

    // Imprimir resultados
    if (result_original != NULL) {
        printf("strnstr: La subcadena '%s' se encuentra en: %s\n", needle, result_original);
    } else {
        printf("strnstr: La subcadena '%s' no se encuentra en los primeros %zu caracteres.\n", needle, len);
    }

    if (result_custom != NULL) {
        printf("ft_strnstr: La subcadena '%s' se encuentra en: %s\n", needle, result_custom);
    } else {
        printf("ft_strnstr: La subcadena '%s' no se encuentra en los primeros %zu caracteres.\n", needle, len);
    }

    return 0;
}
