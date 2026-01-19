#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Funciones de utilidad estándar (equivalentes a tu Libft) ---

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	actual_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		actual_len = 0;
	else if (ft_strlen(s) - start < len)
		actual_len = ft_strlen(s) - start;
	else
		actual_len = len;
	sub = (char *)malloc(actual_len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < actual_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// Implementación simplificada de ft_calloc (para este test)
static void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, count * size);
	return (ptr);
}

// Reemplazo simple para ft_memfree/free
#define ft_memfree free

// --- Funciones de manejo de Token y Comillas (Core del Fix) ---

static int count_words(char *str, char delim)
{
    int count = 0;
    int in_quote = 0;
    int i = 0;

    if (!str)
        return (0);
    while (str[i])
    {
        while (str[i] == delim)
            i++;
        if (!str[i])
            break ;
        count++;
        in_quote = 0;
        while (str[i] && (in_quote || str[i] != delim))
        {
            if (str[i] == '\'' || str[i] == '\"')
            {
                if (!in_quote)
                    in_quote = str[i];
                else if (in_quote == str[i])
                    in_quote = 0;
            }
            i++;
        }
    }
    return (count);
}

/*
** clean_quotes: Limpia las comillas sintácticas.
** Recibe un token con malloc, libera el token y devuelve el nuevo token limpio.
*/
static char *clean_quotes(char *str)
{
    char    *new_str;
    int     i;
    int     j;
    char    quote;

    if (!str)
        return (NULL);
    new_str = (char *)malloc(ft_strlen(str) + 1);
    if (!new_str)
        return (NULL);
    i = 0;
    j = 0;
    quote = 0;
    while (str[i])
    {
        if ((str[i] == '\'' || str[i] == '\"') && (quote == 0 || quote == str[i]))
        {
            if (quote == 0)
                quote = str[i];
            else
                quote = 0;
        }
        else
        {
            new_str[j++] = str[i];
        }
        i++;
    }
    new_str[j] = '\0';
    ft_memfree(str); // Liberamos la string original (lo que hacía tu ft_memfree(word) )
    return (new_str);
}

/*
** process_token: Simulación de ft_strtrim si delim != ' '.
** He quitado la dependencia de ft_strtrim para simplificar el test.
*/
static char *process_token(char *token, char delim)
{
    // Si delim != ' ', deberías usar ft_strtrim. 
    // Para simplificar la prueba y centrarla en las comillas, omito esa lógica compleja.
    
    // Lo esencial: Limpiamos las comillas
    return (clean_quotes(token));
}

static char *extract_word(char *str, int *index, char delim)
{
    int     start;
    int     in_quote;
    char    *word;

    start = *index;
    in_quote = 0;
    while (str[*index] && (in_quote || str[*index] != delim))
    {
        if (str[*index] == '\'' || str[*index] == '\"')
        {
            if (!in_quote)
                in_quote = str[*index];
            else if (in_quote == str[*index])
                in_quote = 0;
        }
        (*index)++;
    }
    word = ft_substr(str, start, *index - start);
    return (process_token(word, delim));
}

// --- Función Principal ---

/*
** El t_shell *msh y msh->cmd_argc han sido simplificados en el main para el test.
** Solo devolvemos el char **.
*/
char    **split_comands(char *str, char delim)
{
    char    **result;
    int     word_count;
    int     i;
    int     j;

    if (!str)
        return (NULL);
    word_count = count_words(str, delim);
    result = (char **)ft_calloc(word_count + 1, sizeof(char *));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i] && j < word_count)
    {
        while (str[i] == delim)
            i++;
        if (!str[i])
            break ;
        result[j] = extract_word(str, &i, delim);
        j++;
    }
    return (result);
}

// --- Main de Prueba Autocontenido ---

void    print_result(char **result, int count)
{
    int i;
    
    printf("Resultado (%d palabras): ", count);
    if (!result)
    {
        printf("[NULL]\n");
        return;
    }
    for (i = 0; result[i]; i++)
    {
        printf("[%s] ", result[i]);
    }
    printf("\n");
    
    // Liberar memoria
    for (i = 0; result[i]; i++)
        ft_memfree(result[i]);
    ft_memfree(result);
}

void    test_case(char *str, char delim, char *desc)
{
    char    **result;
    
    printf("\n--- %s ---\n", desc);
    printf("Input: \"%s\" (delimitador: '%c')\n", str, delim);
    result = split_comands(str, delim);
    
    int count = 0;
    if (result)
    {
        while (result[count])
            count++;
    }
    print_result(result, count);
}

int main(void)
{
    printf("=== PRUEBAS FT_SPLIT_SHELL STANDALONE ===\n");
    
    // El caso que causa el error:
    test_case("export v=\"ls -la\"", ' ', "✅ Exportación de comando (DEBE LIMPIAR COMILLAS)");
    
    // Otros casos de comillas
    test_case("comando \"argumento con espacios\" 'otro argumento'", ' ', "Comillas al inicio/final del arg");
    test_case("echo \"texto 'entre comillas'\" 'y \"mas\" texto'", ' ', "Comillas anidadas y juntas (debe quedar texto 'entre comillas'y \"mas\" texto)");
    test_case("a=\"b c\"d='e'", ' ', "Comillas en medio de arg");
    test_case("\"word\" | \"word\"", '|', "Separador Pipe con comillas");
    test_case("  espacios  al  inicio  y  final  ", ' ', "Solo espacios (debe funcionar)");

    printf("\n=== PRUEBAS COMPLETADAS ===\n");
    return (0);
}