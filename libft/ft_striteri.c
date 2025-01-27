#include "libft.h"

void to_uppercase(char *c)
{
    *c = (char)ft_toupper((unsigned char)*c);
}

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int i;
    i = 0;

    while (s[i] != '\0')
    {
        f(i, &s[i]);
        i++;
    }
}
/*
int main(void)
{
    char str[] = "hello, world!";
    printf("Original string: %s\n", str);
    ft_striteri(str, to_uppercase);
    printf("Modified string: %s\n", str);
    return 0;
}
*/
