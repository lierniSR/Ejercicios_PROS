#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include  <sys/wait.h>
#include <string.h>

void main(){
    pid_t hijo, nieto;
    //Crear descriptores de archivo para leer y escribir
    int fd[2];
    //Creamos una tuberia sin nombre en el Abuelo
    pipe(fd);
    //Escribimos en la tubería
    char* mensaje = "Saludo del abuelo...";
    write(fd[1], mensaje, strlen(mensaje));
    printf("El ABUELO envia un mensaje al HIJO...\n");
    hijo = fork();
    wait(NULL);
    if(hijo == -1){
        printf("No se ha podido crear al hijo...");
    }
    if(hijo == 0){
        //Todo esto en es el HIJO hasta entrar en el fork() del nieto
        //Lee de la tubería del ABUELO
        //Lo del caracter nulo es para que no añade contenido al mensaje del buffer
        char bufferLectura[strlen(mensaje) + 1]; // + 1 para el caracter nulo
        read(fd[0], bufferLectura,  strlen(mensaje));
        bufferLectura[strlen(mensaje)] = '\0'; //Agregar caracter nulo al final
        printf("\tEl HIJO recibe mensaje de abuelo: %s\n", bufferLectura);
        printf("\tEl HIJO envia un mensaje al NIETO...\n");
        mensaje = "Saludo del Padre...";
        write(fd[1], mensaje, strlen(mensaje));
        //Crear nieto
        nieto = fork();
        if(nieto == -1){
            printf("No se ha podido crear al nieto.");
        }
        if(nieto == 0){
            //Lee mensaje de tubería del HIJO
            bufferLectura[strlen(mensaje) + 1];
            read(fd[0], bufferLectura,  strlen(mensaje));
            bufferLectura[strlen(mensaje)] = '\0';
            bufferLectura[strlen(mensaje)] = '\0'; //Agregar caracter nulo al final
            printf("\t\tEl NIETO recibe el mensaje del padre: %s\n", bufferLectura);
            //El NIETO escribe mensaje
            printf("\t\tEl NIETO envia un mensaje al HIJO...\n");
            mensaje = "Saludo del Nieto...";
            write(fd[1], mensaje, strlen(mensaje));
            exit(0);
        }
        wait(NULL);
        //El hijo recibe mensaje del NIETO
        //Lee mensaje de tubería del HIJO
        bufferLectura[strlen(mensaje) + 1];
        read(fd[0], bufferLectura,  strlen(mensaje));
        bufferLectura[strlen(mensaje)] = '\0';
        printf("\tEl HIJO recibe el mensaje de su hijo: %s\n", bufferLectura);
        //El HIJO envia un mensaje al ABUELO
        printf("\tEl HIJO envia un mensaje al ABUELO...\n");
        mensaje = "Saludo del Hijo...";
        write(fd[1], mensaje, strlen(mensaje));
        exit(0);
    }
    wait(NULL);
    //El ABUELO recibe mensaje del HIJO
    char bufferLecturaPadre[strlen(mensaje) + 1];
    read(fd[0], bufferLecturaPadre,  strlen(mensaje));
    bufferLecturaPadre[strlen(mensaje)] = '\0'; // Agregar carácter nulo al final
    printf("El ABUELO recibe el mensaje del HIJO: %s", bufferLecturaPadre);
    close(fd[0]);
    close(fd[1]);
}