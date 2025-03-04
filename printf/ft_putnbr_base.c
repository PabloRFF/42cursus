/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:36:35 by pablrome          #+#    #+#             */
/*   Updated: 2025/03/04 19:37:12 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_putnbr_base(int nbr, char *base)
{
    int len = 0;
    int base_len = 0;
    
    while (base[base_len] != '\0')
        base_len++;
    
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
        len++;
    }
    if (nbr >= base_len)
        len += ft_putnbr_base(nbr / base_len, base);
    
    ft_putchar(base[nbr % base_len]);
    len++;
    
    return (len);
}
