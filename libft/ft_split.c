/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:30:14 by pablrome          #+#    #+#             */
/*   Updated: 2025/01/23 19:48:59 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *str, char c)
{
	int i;
	int count_words;
	
	if (!str)
		return 0;
	i = 0;
	count_words = 0;
	while (str[i] != '\0')
	{
		// Si encontramos un carácter diferente de 'c' y es el primer carácter o después de un espacio
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count_words++;
		i++;
	}
	return (count_words);
}

char **ft_split(char const *s, char c)
{
	char	**result;
	int		n_words;
	int		i;

	i = 0;
	n_words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (n_words + 1) );
	result[n_words + 1] = '\0';
	while (result[i] != '\0')
	{
		result[i] = GET_WORD(str, &j)
	}
	
	
}

int main(int argc, char const *argv[])
{
	char *str = "   Hola q u e tal como  estas  d  ";
	printf("%d\n", count_words(str, ' '));
	return 0;
}


// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		c;
// 	char	**result;

// 	i = 0;
// 	while (!s)
// 	{
// 		/* code */
// 	}
	
// }