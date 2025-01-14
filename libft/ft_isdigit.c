/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:35:27 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/14 16:49:12 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int str)
{
	return (str > 47 && str < 58);
}
// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
//     int str1 = '4';

//     printf("Resultado para \"%c\": %d\n", str1, ft_isdigit(str1));
//     printf("Resultado para \"%c\": %d\n", str1, isdigit(str1));

//     return 0;
// }
