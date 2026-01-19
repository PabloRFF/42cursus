#include <unistd.h> // Necesaria para read()
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char *buffer;
    ssize_t bytesLeidos;
    char *pattern = argv[1];
    size_t p_len = strlen(pattern);


    // read(descriptor, puntero_al_buffer, tamaño_maximo)
    // Usamos 0 o STDIN_FILENO para la entrada estándar
    while ((bytesLeidos = read(0, buffer, 234)) > 0) {
        // Escribimos lo leído directamente a la salida estándar (descriptor 1)
        write(1, buffer, bytesLeidos);
    }

    char *concurrence = memmem(buffer, strlen(buffer), pattern, p_len);

    if (!concurrence)
        printf("%s\n", buffer);
    else
    {
        while (*buffer != *concurrence)
            buffer++;
        memset(buffer, '*', p_len);
        printf("%s\n", buffer);
    }
        
    return 0;
}
