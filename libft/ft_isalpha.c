/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:31:29 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/14 16:48:59 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
    return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     int str1 = 'A';

//     printf("Resultado para \"%c\": %d\n", str1, ft_isalpha(str1));
//     printf("Resultado para \"%c\": %d\n", str1, isalpha(str1));

//     return 0;
// }
