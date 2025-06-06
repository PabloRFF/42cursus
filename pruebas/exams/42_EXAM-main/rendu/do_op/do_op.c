#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int result = 0;
    if( argc != 4 || !atoi(argv[1]) || !atoi(argv[3]))
    {
        printf("\n");
        return (1);
    }

    if(argv[2][0] == '+')
        printf("%d\n", atoi(argv[1]) + atoi(argv[3]));
    else if(argv[2][0] == '-')
        printf("%d\n", atoi(argv[1]) - atoi(argv[3]));
    else if(argv[2][0] == '*')
        printf("%d\n", atoi(argv[1]) * atoi(argv[3]));
    else if(argv[2][0] == '/')
        printf("%d\n", atoi(argv[1]) / atoi(argv[3]));
    else
        printf("%d\n", atoi(argv[1]) % atoi(argv[3]));
    return 0;   
}