#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 15

char *get_next_line(int fd) {
    static char *buffer = NULL;  // Almacena el contenido entre llamadas
    char temp[BUFFER_SIZE + 1];  // Buffer temporal para leer del archivo
    char *newline;               // Puntero al salto de línea
    ssize_t bytes_read;          // Bytes leídos en cada iteración
    size_t line_len;             // Longitud de la línea a extraer

    // Validación de parámetros
    if (fd < 0 || BUFFER_SIZE <= 0) return NULL;

    // Inicializar buffer si es NULL
    if (!buffer) buffer = strdup("");

    // Buscar un salto de línea en el buffer actual
    while ((newline = strchr(buffer, '\n')) == NULL) {
        bytes_read = read(fd, temp, BUFFER_SIZE);  // Leer datos del archivo
        if (bytes_read <= 0) break;                // Fin de archivo o error

        temp[bytes_read] = '\0';                   // Terminar el buffer temporal
        char *new_buffer = realloc(buffer, strlen(buffer) + bytes_read + 1);
        if (!new_buffer) {                         // Manejar fallo de memoria
            free(buffer);
            buffer = NULL;
            return NULL;
        }
        buffer = new_buffer;
        strcat(buffer, temp);                      // Concatenar al buffer estático
    }

    // Manejar errores de lectura
    if (bytes_read == -1) {
        free(buffer);
        buffer = NULL;
        return NULL;
    }

    // Caso 1: Se encontró un salto de línea
    if (newline) {
        line_len = newline - buffer + 1;           // Incluir el '\n'
        char *line = malloc(line_len + 1);         // Asignar memoria para la línea
        strncpy(line, buffer, line_len);           // Copiar hasta el '\n'
        line[line_len] = '\0';

        char *remaining = strdup(newline + 1);     // Guardar el resto del buffer
        free(buffer);
        buffer = remaining;                        // Actualizar buffer estático

        return line;
    } 
    // Caso 2: Fin del archivo sin salto de línea
    else {
        if (buffer[0] == '\0') {                  // Si el buffer está vacío
            free(buffer);
            buffer = NULL;
            return NULL;
        }

        char *line = strdup(buffer);               // Devolver el resto como última línea
        free(buffer);
        buffer = NULL;

        return line;
    }
}


#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error abriendo el archivo");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Linea:%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
