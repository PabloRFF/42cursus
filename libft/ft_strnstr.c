/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:23:30 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/28 17:15:52 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	while (big[i] != '\0' && i + l_len <= len)
	{
		j = 0;
		while (j < l_len && big[i + j] == little[j])
			j++;
		if (j == l_len)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/* int main()
{
	const char *big = "Hello, World!";
	const char *little = "World";
	size_t len = 13;
	//char *result = ft_strnstr(big, little, len);
	char *result_two = ft_strnstr(NULL, "fake", 3);

	if (result_two)
		printf("Found: %s\n", result_two);
	else
		printf("Not found\n");

	return 0;
} */
