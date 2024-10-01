#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include  <sys/wait.h>

void main(){
    pid_t hijo, nieto;
    if(hijo == -1){
        printf("No se ha podido crear el hijo...");
    }
    if(hijo == 0){
        nieto = fork();
        if(nieto == 0){
            printf("Soy el nieto mi PID es %d, y el de mi padre es %d\n", getpid(), getppid());
            exit(0);
        }
        //PAdre espera a nieto
        wait(NULL);
        printf("Soy el hijo mi PID es %d, y el de mi padre es %d\n", getpid(), getppid());
    }
    printf("Soy el padre y mi PID es %d", getppid());
}