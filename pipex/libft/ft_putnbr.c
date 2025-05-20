/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:58:41 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/19 20:34:54 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
		len += 2;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
	len++;
	return (len);
}
