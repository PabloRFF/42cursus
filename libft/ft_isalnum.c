/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:34:35 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/14 16:49:55 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c > 64 && c < 91 || c > 96 && c < 123 || c > 47 && c < 58)
		return 1;
	else
		return 0;
}
// #include <stdio.h>
// int main()
// {
//     char str1 = 'C';
//     char str2 = '^';

//     printf("Resultado para \"%c\": %d\n", str1, ft_isalnum(str1));
//     printf("Resultado para \"%c\": %d\n", str2, ft_isalnum(str2));

//     return 0;
// }
