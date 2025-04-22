#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void shuffle(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int numbers[SIZE];
    
    // Inicializar lista con números únicos
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i + 1;
    }

    // Mezclar la lista aleatoriamente
    srand(time(NULL));
    shuffle(numbers, SIZE);

    // Imprimir la lista
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
