#include <unistd.h>
#include <string.h>

int ft_atoi(char *s)
{
    int res = 0;

    while (*s)
    {
        if (*s >= '0' && *s <= '9')
            res = (res * 10) + (*zs - 48);
        s++;
    }
    return res;
}

void ft_puthex(int n, char *base)
{
    int len = strlen(base);
    char c;
    if(n / len != 0)
        ft_puthex(n / len);
    c = base[n % 16];
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    if(argc != 3)
        write(1, "\n", 1);
    
    int result = ft_atoi(argv[1]);
    ft_puthex(result, argv[2]);
    write(1, "\n", 1);
    return 0;
}