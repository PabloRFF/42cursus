#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 15

int main(void)
{
    static char *buffer;
    char *newline;
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    char temp_buffer[BUFFER_SIZE + 1];
    int bytes_leidos;

    while ((bytes_leidos = read(fd, temp_buffer, BUFFER_SIZE)) > 0)
    {
        newline = strchr(temp_buffer, '\n');
        if(!newline)
        {
            printf("%s", temp_buffer);
        }
        else
        {
            *newline = '\0';
            printf("Buffer: %s", temp_buffer);
            //Lo que queda del buffer despues del salto de linea se guarda en la static
            buffer = strdup(newline + 1);
            break;
        }
    }

    if (bytes_leidos == -1)
        printf("Error al leer el archivo");
    close(fd);
    return (0);
}
