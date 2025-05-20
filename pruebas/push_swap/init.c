#include "push_swap.h"

int is_number(const char *str) {
    if (*str == '-' || *str == '+') str++;
    if (!*str) return (0);
    while (*str) {
        if (*str < '0' || *str > '9') return (0);
        str++;
    }
    return (1);
}

int has_duplicate(t_stack *a, int num) {
    int i = 0;
    while (i < a->size) {
        if (a->data[i].value == num) return (1);
        i++;
    }
    return (0);
}

int add_number(t_stack *a, const char *arg) {
    long n;
    if (!is_number(arg)) return (0);
    n = strtol(arg, NULL, 10);
    if (n < INT_MIN || n > INT_MAX) return (0);
    if (has_duplicate(a, (int)n)) return (0);
    a->data[a->size].value = (int)n;
    a->size++;
    return (1);
}