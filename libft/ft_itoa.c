#include "libft.h"

static int get_len(int n)
{
    int len;

    len = 0;
    if(n <= 0)
        len++; //En el caso de que sea negativo es necesario un carcater extra para el signo
    while(n != 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    int     len;
    char    *str;
    long    num; //Para manejar los casos de MIN_INT y que no de fallo

    len = get_len(n);
    num = n;
    str = (char *)malloc(len + 1); //1 + para el nulo
    if(!str)
        return NULL;
    str[len] = '\0';
    if(num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    while (--len >= 0 && str[len] != '-')
    {
        str[len] = num % 10 + '0';
        num /= 10;
    }
    return (str);
}