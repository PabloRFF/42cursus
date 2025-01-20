#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *sub;

    if (!s)
        return (NULL);
    i = ft_strlen(s);
    if (i < start)
        return (ft_strdup(""));
    if (i - start < len)
        len = i - start;
    sub = (char *)malloc(sizeof(char) * (len + 1)); // +1 para el nulo
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}
