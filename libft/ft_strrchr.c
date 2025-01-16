/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:20:56 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/16 15:21:56 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
    const char *last_occurrence = NULL;
    
    while (*str)
    {
        if (*str == (char)c)
            last_occurrence = str;
        str++;
    }
    if (c == '\0')
        return ((char *)str);

    return ((char *)last_occurrence);
}
