/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:20:39 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/14 18:27:31 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int	i;
	unsigned char *ptr;
	ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if(i < n)
			ptr[i] = c;
		i++;
	}
	
	return str;
}