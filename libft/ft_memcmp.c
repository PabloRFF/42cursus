/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:40:10 by pablrome          #+#    #+#             */
/*   Updated: 2025/02/03 14:15:54 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char	*s1;
	unsigned const char	*s2;
	size_t				i;

	s1 = str1;
	s2 = str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/* int main()
{
	int result;
	char str1[] = "Hola Mundo";
    char str2[] = "Hola Mundo!";
    result = ft_memcmp(str1, str2, sizeof(str1));

    printf("Comparando '%s' y '%s':\n", str1, str2);
    if (result == 0)
        printf("Las cadenas son iguales.\n");
    else
        printf("Diferentes, diferencia: %d\n", result);
	return 0;
} */
