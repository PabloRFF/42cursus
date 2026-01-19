#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char buffer[4096];  // buffer grande
    ssize_t bytesLeidos;
    char *pattern = argv[1];
    size_t p_len = strlen(pattern);

    // Leer stdin completo
    bytesLeidos = read(0, buffer, sizeof(buffer) - 1);
    if (bytesLeidos < 0) return 1;

    buffer[bytesLeidos] = '\0'; // asegurar terminación

    // Reemplazar todas las ocurrencias
    char *pos = buffer;
    while ((pos = memmem(pos, buffer + bytesLeidos - pos, pattern, p_len)))
    {
        memset(pos, '*', p_len);
        pos += p_len; // avanzar para seguir buscando
    }

    write(1, buffer, bytesLeidos);

    return 0;
}
