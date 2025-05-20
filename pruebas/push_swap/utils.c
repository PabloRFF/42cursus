#include "push_swap.h"

void assign_indices(t_stack *a) {
    t_elem sorted[MAX];
    int i, j;

    for (i = 0; i < a->size; i++) sorted[i] = a->data[i];
    sort_array(sorted, a->size);
    for (i = 0; i < a->size; i++) {
        j = 0;
        while (j < a->size) {
            if (a->data[i].value == sorted[j].value) {
                a->data[i].index = j;
                break;
            }
            j++;
        }
    }
}

void sort_array(t_elem *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                t_elem tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}