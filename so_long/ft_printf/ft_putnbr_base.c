/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:36:35 by pablrome          #+#    #+#             */
/*   Updated: 2025/03/27 17:59:10 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(size_t n, char *base)
{
	size_t		len;
	size_t		base_len;
	char		c;

	len = 0;
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	if (base_len < 2)
		return (0);
	if (n >= (unsigned int)base_len)
		len += ft_putnbr_base(n / base_len, base);
	c = base[n % base_len];
	write(1, &c, 1);
	return (len + 1);
}
