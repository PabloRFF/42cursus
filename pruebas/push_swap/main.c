#include "push_swap.h"

int main(int argc, char **argv) {
    t_stack a = {0};
    t_stack b = {0};
    int i;

    if (argc < 2) return (0);
    i = 1;
    while (i < argc)
    {
        if (!add_number(&a, argv[i])) {
            write(2, "Error\n", 6);
            return (1);
        }
        i++;
    }
    assign_indices(&a);
    if (a.size == 2) sort_two(&a);
    else if (a.size == 3) sort_three(&a);
    else if (a.size <= 5) sort_five(&a, &b);
    else radix_sort(&a, &b);
    return (0);
}