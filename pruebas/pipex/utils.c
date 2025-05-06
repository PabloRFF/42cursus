#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd, pipe_fd[2];
    pid_t pid;

    // Verificar que el usuario haya proporcionado un comando
    if (argc < 2) {
        fprintf(stderr, "Uso: %s \"comando\"\n", argv[0]);
        return 1;
    }

    // Crear un pipe para capturar la salida del comando
    if (pipe(pipe_fd) == -1) {
        perror("Error al crear el pipe");
        return 1;
    }
    
    // Crear un proceso hijo para ejecutar el comando
    pid = fork();
    if (pid == -1) {
        perror("Error al hacer fork");
        return 1;
    }

    if (pid == 0) {  // Proceso hijo
        close(pipe_fd[0]); // Cerramos el extremo de lectura del pipe

        // Redirigir stdout al pipe
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]); // Cerramos el extremo de escritura

        // Ejecutar el comando usando execvp
        execvp(argv[1], &argv[1]);
        perror("Error al ejecutar el comando");
        exit(1);
    } else {  // Proceso padre
        close(pipe_fd[1]); // Cerramos el extremo de escritura del pipe

        // Abrir el archivo de salida
        fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("Error al abrir el archivo");
            return 1;
        }

        // Leer desde el pipe y escribir en el archivo
        char buffer[1024];
        ssize_t bytes_leidos;
        while ((bytes_leidos = read(pipe_fd[0], buffer, sizeof(buffer))) > 0) {
            write(fd, buffer, bytes_leidos);
        }

        // Cerrar el pipe y el archivo
        close(pipe_fd[0]);
        close(fd);

        printf("La salida del comando se ha guardado en 'salida.txt'.\n");
    }

    return 0;
}
