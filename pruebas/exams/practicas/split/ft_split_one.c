#include <stdio.h>
#include <stdlib.h>

int delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
	int words = 0;
	int in_word = 0;
	while (*str)
	{
		if(*str == ' ' || *str == '\t' || *str == '\n')
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			words++;
		}
		str++;
	}
	return words;
}

char	**ft_split(char *s)
{
	int words = count_words(s);
	int i = 0;
	char **matrix;

	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if(!matrix)
		return NULL;
	while (*s)
	{
		while(delimiter(*s))
			s++;
		if(*s == '\0')
			break;
		char *start = s;
		while(!delimiter(*s) && *s)
			s++;
		int len = s - start;
		matrix[i] = (char *)malloc(sizeof(char) * (len + 1));
		int j = 0;
		while(j < len)
		{
			matrix[i][j] = start[j];
			j++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	matrix[i] = NULL;
	return matrix;
}

int	main(void)
{
	char *s = "There     should be an array of 8         words! ";
	char **array = ft_split(s);
	int i = 0;
	int count = count_words(s);

	printf("wordcount: %d\n", count);
	while (i < count)
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}
