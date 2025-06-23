#include <stdlib.h>

int delimiter(char c)
{
	return(c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *s)
{
	int in_word = 0;
	int words = 0;

	while (*s)
	{
		if(*s != ' ' && *s != '\t' && in_word == 0)
		{
			in_word = 1;
			words++;
		} else if (*s == ' ' || *s == '\t')
			in_word = 0;
		s++;
	}
	return words;
}

char    **ft_split(char *str)
{
	int words = count_words(str);
	int i = 0;
	char **tab = (char **)malloc(sizeof(char *) * words + 1);

	if (!tab)
		return NULL;

	while (*str)
	{
		while (delimiter(*str))
			str++;

		if(*str == '\0')
			break;	
		
		char *start = str;
		while (!delimiter(*str) && *str)
			str++;
		int len = str - start;
		tab[i] = (char *)malloc(sizeof(char) * len + 1);
		int j = 0;
		while (j < len)
		{
			tab[i][j] = start[j];
			j++;
		}
		tab[i][j] = '\0';
		i++;		
	}
	tab[i] = NULL;
	return tab;
}