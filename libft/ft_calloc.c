
#include "libft.h"

void    *ft_calloc(size_t nitems, size_t size)
{
    void *ptr;
    size_t total_size;

    total_size = nitems * size;
    ptr = malloc(total_size);
    if (ptr == NULL)
        return NULL;
    ft_bzero(ptr, total_size);
    return ptr;
}

// #include <stdio.h>
// int main() {
//     int *arr;
//     size_t n = 5;

//     arr = (int *)ft_calloc(n, sizeof(int));
//     if (arr == NULL) {
//         printf("Error al asignar memoria\n");
//         return 1;
//     }

//     for (size_t i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     free(arr);

//     return 0;
// }
