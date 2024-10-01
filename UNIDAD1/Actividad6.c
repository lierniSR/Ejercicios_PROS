#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include  <sys/wait.h>

void main(){
    pid_t hijo1, hijo2, hijo3;
    hijo1 = fork(); //Creamos hijo 1
    if(hijo1 == -1){
        printf("No se ha podido crear ningun proceso hijo...");
    }
    if(hijo1 == 0){
        printf("Yo soy el hijo 1, mi padre es PID = %d,yo soy PID = %d\n", getppid(), getpid());
    } else {
        hijo2 = fork(); //Creamos hijo2
        if(hijo2 == 0){
            //Estamos en el hijo 2
            printf("Soy el hijo2, mi padre es PID = %d, y mi PID = %d\n", getppid(), getpid());
            hijo3 = fork(); //Creamo proceso hijo 2, con padre hijo2
            if(hijo3 == 0){
                printf("Soy el hijo 3, mi padre es PID = %d, y mi PID = %d\n", getppid(), getpid());
                exit(0);
            }
            wait(NULL);
        }
        wait(NULL);
    }
}