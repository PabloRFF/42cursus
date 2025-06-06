#include <stdio.h>
#include <stdlib.h>

int n_len(int n)
{
	int i = 1;
	while (n /= 10)
		i++;
	return i;
	
}

char    *ft_itoa(int n)
{
	char *result;
	int is_negative = n < 0 ? 1 : 0;
	int len = n_len(n) - 1 + is_negative;
	result = (char *) malloc(sizeof(char) * (len + 2));
	if (!result)
		return NULL;
	if (is_negative)
	{
		n = -n;
		result[0] = '-';
	}
	result[len + 1] = '\0';

	while (len >= (0 + is_negative))
	{
		result[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return result;
}
