/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:06:42 by pablrome          #+#    #+#             */
/*   Updated: 2025/03/27 17:56:47 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define HEX_UP_BASE "0123456789ABCDEF"
# define HEW_LOW_BASE "0123456789abcdef"

int	ft_printf(char const *str, ...);

int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putnbr_base(size_t n, char *base);
int	ft_putnbr_u(unsigned int n);

#endif