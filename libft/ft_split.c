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

char	*get_next_word(char const *s, int *index, char c)
{
	int start = *index;
	while (s[start] == c && s[start] != '\0')
		start++;
	int end = start;
	while (s[end] != c && s[end] != '\0')
		end++;
	*index = end;
	return ft_substr(s, start, end - start);
}

char **ft_split(char const *s, char c)
{
	char	**result;
	int		n_words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	n_words = count_words(s, c);
	if (!s || !(result = (char **)malloc(sizeof(char *) * (n_words + 1))))
		return NULL;
	while (j < n_words)
	{
		result[j] = get_next_word(s, &i, c);
		if (!result[j])
		{
			while (j > 0)
				free(result[--j]);
			free(result);
			return NULL;
		}
		j++;
	}
	result[j] = NULL;
	return result;
}

/* int main(void)
{
    char *str = "Hello, this is a test string.";
    char delimiter = ' ';
    char **result;
    int i;

    result = ft_split(str, delimiter);
    if (!result)
    {
        printf("Memory fail.\n");
        return 1;
    }
	printf("COMPLETE WORD: \n");
	printf("%s\n", str);
	printf("-----------------------------\n");
    printf("Split words:\n");
    for (i = 0; result[i] != NULL; i++)
    {
        printf("Word %d: %s\n", i + 1, result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
} */
