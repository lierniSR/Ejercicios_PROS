#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include  <sys/wait.h>

void main(){
    pid_t hijo;
    if(hijo == -1){
        printf("No se ha encontrado ningun proceso hijo...");
    }
    if(hijo == 0){
        for(int i = 1; i < 4; i++){
            //Creamos 3 hijo en un bucle
            hijo = fork();
            printf("Soy el hijo %d, Mi padre es %d, y mi PID es %d\n", i, getppid(), getpid());
            exit(0);
        }
        wait(NULL);
    }
    printf("Proceso padre %d", getppid());
}