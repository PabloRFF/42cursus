#include "push_swap.h"

void sort_two(t_stack *a) {
    if (a->data[0].value > a->data[1].value)
        sa(a);
}

void sort_three(t_stack *a) {
    int top = a->data[0].value;
    int mid = a->data[1].value;
    int bot = a->data[2].value;

    if (top > mid && mid < bot && top > bot) ra(a);
    else if (top > mid) sa(a);
    if (a->data[1].value > a->data[2].value) {
        rra(a);
        sa(a);
    }
}

void sort_five(t_stack *a, t_stack *b) {
    pb(a, b);
    pb(a, b);
    sort_three(a);
    pa(a, b);
    pa(a, b);
    if (a->data[0].value > a->data[1].value) sa(a);
}

void radix_sort(t_stack *a, t_stack *b) {
    int max_bits = 0;
    int max_num = a->size - 1;

    while ((max_num >> max_bits) != 0) max_bits++;
    for (int bit = 0; bit < max_bits; bit++) {
        for (int i = 0; i < a->size; i++) {
            if (((a->data[0].index >> bit) & 1) == 0) pb(a, b);
            else ra(a);
        }
        while (b->size > 0) pa(a, b);
    }
}