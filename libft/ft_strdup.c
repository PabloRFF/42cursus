#include "libft.h"

char    *ft_strdup(const char *s)
{
    size_t len;
    char *dup;

    len = ft_strlen(s) + 1;

    dup = (char *)malloc(len * sizeof(char));
    if (dup == NULL)
        return (NULL);
    ft_memcpy(dup, s, len);
    return (dup);
}