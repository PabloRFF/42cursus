/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:17:48 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/15 20:18:33 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


size_t	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char )s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char str1[] = "Hola, mundo!";
    char str2[] = "Hola, mundo!";
    char str4[] = "Hola, universo!";

    printf("%d\n", ft_strncmp(str1, str2, 5));
	printf("%d\n", ft_strncmp(str1, str4, 6)); //Deberia ser 0
	printf("%d\n", ft_strncmp(str1, str4, 10)); //Debería no ser 0
	printf("%d\n", strncmp(str1, str4, 10)); //Igual que la previa

    return 0;
}
*/