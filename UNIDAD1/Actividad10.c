#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

//gestion de señales
void gestion_padre(int signal){
    printf("Padre recibe señal...%d\n", signal);
}
void gestion_kill_padre(){
    printf("Terminado (killed)");
}
void main(){
    int pid_hijo, pid_padre;
    pid_padre = getpid();
    pid_hijo = fork();//Creamos hijo
    if(pid_hijo == -1){
        printf("No se ha podido crear el proceso hijo...\n");
        exit(-1);
    }
    //Entramos en el hijo
    if(pid_hijo == 0){
        //Enviamos tres señales SIGUSR1 AL PADRE
        sleep(1);
        kill(pid_padre, SIGUSR1);
        sleep(1);
        kill(pid_padre, SIGUSR1);
        sleep(1);
        kill(pid_padre, SIGUSR1);
        sleep(1);
        kill(pid_padre, SIGKILL);
        sleep(1);
        exit(0);
    } else {
        signal(SIGUSR1, gestion_padre);//Manejador de señal del padre
        signal(SIGKILL, gestion_kill_padre);
        while(1){};//Bucle infinito
        exit(0);
    }
}