#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1000  // Puedes aumentar este valor si es necesario

// Estructura que almacena el valor y su índice (según el orden ascendente)
typedef struct {
    int value;
    int index;
} t_elem;

typedef struct {
    t_elem data[MAX];
    int size;
} Stack;

// Variable global para contar movimientos
int move_count = 0;

/* ********************* FUNCIONES DE IMPRESIÓN ********************* */

void print_stacks(Stack *a, Stack *b) {
    printf("\nPila A: ");
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->data[i].value);
    }
    printf("\nPila B: ");
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->data[i].value);
    }
    printf("\n------------------\n");
}

/* ********************* FUNCIONES BÁSICAS DE LAS OPERACIONES ********************* */

void sa(Stack *a) {
    if (a->size >= 2) {
        t_elem tmp = a->data[0];
        a->data[0] = a->data[1];
        a->data[1] = tmp;
        printf("sa\n");
        move_count++;
    }
}

void sb(Stack *b) {
    if (b->size >= 2) {
        t_elem tmp = b->data[0];
        b->data[0] = b->data[1];
        b->data[1] = tmp;
        printf("sb\n");
        move_count++;
    }
}

void ss(Stack *a, Stack *b) {
    sa(a);
    sb(b);
    printf("ss\n");
    move_count++;
}

void pa(Stack *a, Stack *b) {
    if (b->size == 0) return;
    // Desplazar los elementos de A para dejar espacio en la cima
    for (int i = a->size; i > 0; i--)
        a->data[i] = a->data[i - 1];
    a->data[0] = b->data[0];
    a->size++;
    // Desplazar hacia arriba en B
    for (int i = 0; i < b->size - 1; i++)
        b->data[i] = b->data[i + 1];
    b->size--;
    printf("pa\n");
    move_count++;
}

void pb(Stack *a, Stack *b) {
    if (a->size == 0) return;
    // Desplazar los elementos de B para dejar espacio en la cima
    for (int i = b->size; i > 0; i--)
        b->data[i] = b->data[i - 1];
    b->data[0] = a->data[0];
    b->size++;
    // Desplazar hacia arriba en A
    for (int i = 0; i < a->size - 1; i++)
        a->data[i] = a->data[i + 1];
    a->size--;
    printf("pb\n");
    move_count++;
}

void ra(Stack *a) {
    if (a->size < 2) return;
    t_elem tmp = a->data[0];
    for (int i = 0; i < a->size - 1; i++)
        a->data[i] = a->data[i + 1];
    a->data[a->size - 1] = tmp;
    printf("ra\n");
    move_count++;
}

void rb(Stack *b) {
    if (b->size < 2) return;
    t_elem tmp = b->data[0];
    for (int i = 0; i < b->size - 1; i++)
        b->data[i] = b->data[i + 1];
    b->data[b->size - 1] = tmp;
    printf("rb\n");
    move_count++;
}

void rr(Stack *a, Stack *b) {
    ra(a);
    rb(b);
    printf("rr\n");
    move_count++;
}

void rra(Stack *a) {
    if (a->size < 2) return;
    t_elem tmp = a->data[a->size - 1];
    for (int i = a->size - 1; i > 0; i--)
        a->data[i] = a->data[i - 1];
    a->data[0] = tmp;
    printf("rra\n");
    move_count++;
}

void rrb(Stack *b) {
    if (b->size < 2) return;
    t_elem tmp = b->data[b->size - 1];
    for (int i = b->size - 1; i > 0; i--)
        b->data[i] = b->data[i - 1];
    b->data[0] = tmp;
    printf("rrb\n");
    move_count++;
}

void rrr(Stack *a, Stack *b) {
    rra(a);
    rrb(b);
    printf("rrr\n");
    move_count++;
}

/* ********************* VALIDACIÓN Y LECTURA DE ARGUMENTOS ********************* */

bool is_number(const char *str) {
    if (*str == '-' || *str == '+') str++;
    if (!*str) return false;
    while (*str) {
        if (*str < '0' || *str > '9') return false;
        str++;
    }
    return true;
}

bool has_duplicate(Stack *a, int num) {
    for (int i = 0; i < a->size; i++) {
        if (a->data[i].value == num)
            return true;
    }
    return false;
}

bool add_number(Stack *a, const char *arg) {
    if (!is_number(arg))
        return false;
    long n = strtol(arg, NULL, 10);
    if (n < INT_MIN || n > INT_MAX)
        return false;
    if (has_duplicate(a, (int)n))
        return false;
    a->data[a->size].value = (int)n;
    a->data[a->size].index = -1; // Inicialmente sin asignar
    a->size++;
    return true;
}

/* ********************* ASIGNAR ÍNDICES ********************* */

// Función auxiliar para intercambiar dos elementos (usada en el sort)
void swap_elem(t_elem *a, t_elem *b) {
    t_elem tmp = *a;
    *a = *b;
    *b = tmp;
}

// Ordenamiento simple (bubble sort) de un array auxiliar
void sort_array(t_elem arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                swap_elem(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Asigna a cada elemento un índice según su orden (el menor tendrá índice 0)
void assign_indices(Stack *a) {
    int n = a->size;
    t_elem *aux = malloc(sizeof(t_elem) * n);
    if (!aux) {
        fprintf(stderr, "Error de memoria.\n");
        exit(1);
    }
    // Copiar elementos
    for (int i = 0; i < n; i++) {
        aux[i] = a->data[i];
    }
    // Ordenar el array auxiliar
    sort_array(aux, n);
    // Asignar índices: el menor obtendrá índice 0, el siguiente 1, etc.
    for (int i = 0; i < n; i++) {
        int val = a->data[i].value;
        for (int j = 0; j < n; j++) {
            if (aux[j].value == val) {
                a->data[i].index = j;
                break;
            }
        }
    }
    free(aux);
}

/* ********************* ALGORITMO TURCO ********************* */

// Función para encontrar el índice del elemento máximo en la pila B
int find_max_index(Stack *b) {
    int max_idx = 0;
    for (int i = 1; i < b->size; i++) {
        if (b->data[i].index > b->data[max_idx].index)
            max_idx = i;
    }
    return max_idx;
}

// Rota la pila B para poner en la cima el elemento en la posición "pos"
void rotate_b_to_top(Stack *b, int pos) {
    if (pos <= b->size / 2) {
        for (int i = 0; i < pos; i++)
            rb(b);
    } else {
        for (int i = 0; i < b->size - pos; i++)
            rrb(b);
    }
}

// Implementación del algoritmo “turco”:
// Se dividen los elementos en chunks según su índice y se mueven de A a B.
void turco(Stack *a, Stack *b) {
    int chunk_size;
    int total = a->size;
    // Elegir el tamaño del chunk dependiendo del total (ajusta estos valores según necesites)
    if (total <= 100)
        chunk_size = 15;
    else
        chunk_size = 30;

    int current_max = chunk_size - 1;
    int pushed = 0;

    // Mover los elementos de A a B, según el chunk actual.
    while (a->size > 0) {
        if (a->data[0].index <= current_max) {
            pb(a, b);
            pushed++;
            // Si el elemento está en la mitad inferior del chunk, rota B para facilitar el orden
            if (b->size > 1 && b->data[0].index < current_max - (chunk_size / 2))
                rb(b);
        } else {
            ra(a);
        }
        // Cuando se han empujado todos los elementos del chunk actual, aumenta el límite
        if (pushed >= current_max + 1 && current_max < total - 1)
            current_max += chunk_size;
    }

    // Recuperar los elementos de B de vuelta a A en orden (el mayor primero)
    while (b->size > 0) {
        int pos = find_max_index(b);
        rotate_b_to_top(b, pos);
        pa(a, b);
    }
}

/* ********************* FUNCIÓN MAIN ********************* */

int main(int argc, char **argv) {
    Stack a = {.size = 0};
    Stack b = {.size = 0};

    if (argc < 2) {
        fprintf(stderr, "Uso: %s num1 num2 ...\n", argv[0]);
        return 1;
    }

    // Cargar los números en la pila A
    for (int i = 1; i < argc; i++) {
        if (!add_number(&a, argv[i])) {
            fprintf(stderr, "Error: Argumento inválido o duplicado: %s\n", argv[i]);
            return 1;
        }
    }

    // Asignar índices a cada elemento
    assign_indices(&a);

    // Ejecutar el algoritmo turco
    turco(&a, &b);

    // Mostrar el resultado final (pila A ordenada y pila B vacía)
    print_stacks(&a, &b);

    // Imprimir el total de movimientos ejecutados
    printf("Total movimientos: %d\n", move_count);

    return 0;
}
