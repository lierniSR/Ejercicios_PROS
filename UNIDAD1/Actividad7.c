#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include  <sys/wait.h>

void main(){
    //Declaras variables PID
    pid_t hijo;
    int contador = 6;
    printf("Valor inicial de la variable: %d\n", contador);
    hijo = fork();

    if(hijo == -1){
        printf("No se ha podido crear ningun proceso hijo...");
    }
    if(hijo == 0){
        //Estamos en el hijo
        printf("Variable en Proceso hijo : %d\n", contador - 5);
        exit(0);
    }
    wait(NULL);
    printf("Variable en Proceso padre: %d\n", contador + 5);
}