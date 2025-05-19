/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:58:59 by pablrome          #+#    #+#             */
/*   Updated: 2025/05/19 20:30:23 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	do_pointer(va_list list)
{
	size_t	ptr;
	int		len;

	len = 0;
	ptr = (size_t)va_arg(list, void *);
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		len += 5;
	}
	else
	{
		ft_putstr("0x");
		len += 2;
		len += ft_putnbr_base(ptr, HEW_LOW_BASE);
	}
	return (len);
}

int	read_format(va_list list, const char *str)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len = ft_putchar(va_arg(list, int));
	if (*str == 's')
		len = ft_putstr(va_arg(list, char *));
	if (*str == 'i' || *str == 'd')
		len = ft_putnbr(va_arg(list, int));
	if (*str == 'u')
		len = ft_putnbr_u(va_arg(list, unsigned int));
	if (*str == 'x')
		len = ft_putnbr_base(va_arg(list, unsigned int), HEW_LOW_BASE);
	if (*str == 'X')
		len = ft_putnbr_base(va_arg(list, unsigned int), HEX_UP_BASE);
	if (*str == '%')
		len = ft_putchar('%');
	if (*str == 'p')
		len = do_pointer(list);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list		list;
	int			len;

	len = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += read_format(list, str);
		}
		else
		{
			write(1, str, 1);
			len += 1;
		}
		if (*str)
			str++;
	}
	va_end(list);
	return (len);
}
