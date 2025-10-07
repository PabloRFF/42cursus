/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:06:42 by pablrome          #+#    #+#             */
/*   Updated: 2025/07/03 19:11:31 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../so_long.h"
# include <stdarg.h>

# define HEX_UP_BASE "0123456789ABCDEF"
# define HEW_LOW_BASE "0123456789abcdef"

int	ft_printf(char const *str, ...);
int	ft_putnbr_base(size_t n, char *base);
int	ft_putnbr_u(unsigned int n);
int	ft_putnbr(int n);
int	ft_putchar(int c);
int	ft_putstr(char *str);

#endif