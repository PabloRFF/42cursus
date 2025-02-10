#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 15

int main(void) {
    static char *buffer = NULL;  // Almacena el resto entre lecturas
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char temp[BUFFER_SIZE + 1];
    ssize_t bytes;

    while ((bytes = read(fd, temp, BUFFER_SIZE)) > 0) {
        temp[bytes] = '\0';  // Asegura terminación en NULL

        // Combina el buffer estático con el nuevo contenido
        char *combined = buffer ? malloc(strlen(buffer) + bytes + 1) : NULL;
        if (buffer) {
            strcpy(combined, buffer);
            strcat(combined, temp);
            free(buffer);
            buffer = NULL;
        } else {
            combined = strdup(temp);
        }

        // Busca el salto de línea
        char *newline = strchr(combined, '\n');
        if (newline) {
            *newline = '\0';  // Termina la línea aquí
            printf("%s\n", combined);  // Imprime la línea completa

            // Guarda el resto después del salto de línea
            char *resto = newline + 1;
            if (*resto) buffer = strdup(resto);
            free(combined);
        } else {
            buffer = combined;  // No hay salto, guarda todo
        }
    }

    // Imprime el resto final si no hay salto de línea
    if (buffer) {
        printf("%s\n", buffer);
        free(buffer);
        buffer = NULL;
    }

    close(fd);
    return 0;
}