#include "push_swap.h"

void pa(t_stack *a, t_stack *b) {
    int i;
    if (b->size == 0) return;
    i = a->size;
    while (i > 0) {
        a->data[i] = a->data[i - 1];
        i--;
    }
    a->data[0] = b->data[0];
    a->size++;
    i = 0;
    while (i < b->size - 1) {
        b->data[i] = b->data[i + 1];
        i++;
    }
    b->size--;
    write(1, "pa\n", 3);
}

void rra(t_stack *a) {
    t_elem tmp;
    int i;
    if (a->size < 2) return;
    tmp = a->data[a->size - 1];
    i = a->size - 1;
    while (i > 0) {
        a->data[i] = a->data[i - 1];
        i--;
    }
    a->data[0] = tmp;
    write(1, "rra\n", 4);
}