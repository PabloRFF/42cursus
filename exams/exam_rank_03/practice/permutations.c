#include <unistd.h>

int str_len(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void    put_str(char *str)
{
    while(*str)
        write(1, str++, 1);
    write(1, "\n", 1);
}

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void    sort(char *str)
{
    int len = str_len(str);
    int i = 0;
    while (i < (len - 1))
    {
        int j = 0;
        while (j < (len - i - 1))
        {
            if (str[j] > str[j + 1])
                swap(&str[j], &str[j + 1]);
            j++;
        }
        i++;
    }
}

int next_permutation(char *str, int len)
{
    int i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1])
        i--;
    if (i < 0)
        return 0;
    int j = len - 1;
    while (str[j] <= str[i])
        j--;
    swap(&str[i], &str[j]);
    int start = i + 1;
    int end = len - 1;
    while (start < end)
        swap(&str[start++], &str[end--]);
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    char *str = argv[1];
    int len = str_len(str);
    sort(str);
    put_str(str);
    while (next_permutation(str, len))
        put_str(str);
    return 0;
}
