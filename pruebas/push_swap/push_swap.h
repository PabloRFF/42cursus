#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# define MAX 1000

typedef struct s_elem {
    int value;
    int index;
} t_elem;

typedef struct s_stack {
    t_elem data[MAX];
    int size;
} t_stack;

/* main.c */
int     main(int argc, char **argv);

/* init.c */
int     is_number(const char *str);
int     has_duplicate(t_stack *a, int num);
int     add_number(t_stack *a, const char *arg);

/* operations.c */
void    sa(t_stack *a);
void    sb(t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);

/* sort_algorithms.c */
void    sort_two(t_stack *a);
void    sort_three(t_stack *a);
void    sort_five(t_stack *a, t_stack *b);
void    radix_sort(t_stack *a, t_stack *b);

/* utils.c */
void    assign_indices(t_stack *a);
void    sort_array(t_elem *arr, int n);

#endif