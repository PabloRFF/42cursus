/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:09:50 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/16 15:18:52 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (char *)(str + i);
		i++;
	}

	if (c == '\0')
		return ((char *)(str + i)); 
	return NULL;
}