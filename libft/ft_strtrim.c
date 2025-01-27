#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	while ( s1[start] && ft_strchr(set, s1[start]) ) //Compruebo el principio con strchr. Con el strchr busco si caracter actual de s1 es igual a algun caracter set
		start++;
	while ( end > start && ft_strchr(set, s1[end - 1])) //Compruebo el final con strchr
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1)); //Asigno la memoria necesaria para el str
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1); //Está copiando en STR (que por ahora estará vacia), los valores desde s1 + start hasta end - start + 1(Para el nulo)
	str[end - start] = '\0';
	return (str);
}

/* int main(void)
{
    char *s1 = "   xxffxHellxo Worldfxxx   ";
    char *set = " xf";
    char *result;

    result = ft_strtrim(s1, set);
    if (result)
    {
        printf("Original string: '%s'\n", s1);
        printf("Characters to trim: '%s'\n", set);
        printf("Trimmed string: '%s'\n", result);
        free(result);
    }
    else
    {
        printf("MALLOC failed\n");
    }
    return 0;
} */