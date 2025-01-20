#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t  i;
    size_t  j;
    char    *join;

    if (!s1 || !s2)
        return (NULL);
    join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!join)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        join[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        join[i + j] = s2[j];
        j++;
    }
    join[i + j] = '\0';
    return (join);
}