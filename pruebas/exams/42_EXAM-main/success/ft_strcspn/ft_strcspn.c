#include <stdlib.h>

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

size_t  ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t len = ft_strlen(s);
    int j;
    while (*s)
    {
        j = 0;
        while (reject[j])
        {
            if (reject[j] == *s)
                return i;
            j++;
        }
        i++;
        s++;
    }
    return len;
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str1[] = "hola mundo";
//     char str2[] = "u";

//     size_t len = strcspn(str1, str2);
//     printf("Original longitud: %zu\n", len);
//     len = ft_strcspn(str1, str2);
//     printf("Usuario longitud: %zu\n", len);
//     return 0;
// }
