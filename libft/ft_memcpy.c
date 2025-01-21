/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:31:43 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/15 19:04:43 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	if (dest_str == NULL && src_str == NULL)
		return NULL;
	unsigned char	*d = dest_str;
	unsigned const char	*o = src_str;

	while (n--)
	{
		*d++ = *o++;
	}
	return (dest_str);
	
}