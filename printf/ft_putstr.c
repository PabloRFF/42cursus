#include "ft_printf.h"

int ft_putstr(char *str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        ft_putchar(str[len]);
        len++;
    }

    return (len);
}
