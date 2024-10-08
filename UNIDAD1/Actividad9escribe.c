#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(void){
    int fp, p;
    p = mknod("FIFO2", S_IFIFO|0666, 0);
    char saludo[] = "Un saludo !!!!!\n";
    if(p == 1){
        printf("Ha ocurrido un error...\n");
        exit(0);
    }
    fp = open("FIFO2", 1); //Abrimos fifo en forma de escritura
    if(fp == -1){
        printf("Error al abrir el fichero...\n");
        exit(1);
    }
    printf("Mandando informacion al FIFO...\n");
    write(fp, saludo, sizeof(saludo));
    close(fp);
}