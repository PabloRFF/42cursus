/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:23 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/28 17:24:18 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	str[end - start] = '\0';
	return (str);
}

/* int main(void)
{
	char *s1 = "   xxffxHellxo Worldfxxx   ";
	char *set = " xf";
	char *result;

	result = ft_strtrim(s1, set);
	if (result)
	{
		printf("Original string: '%s'\n", s1);
		printf("Characters to trim: '%s'\n", set);
		printf("Trimmed string: '%s'\n", result);
		free(result);
	}
	else
	{
		printf("MALLOC failed\n");
	}
	return 0;
} */