#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
    int fp, bytesleidos;
    char buffer[30];

    // Abrimos el FIFO en modo lectura no bloqueante
    fp = open("FIFO2", O_RDONLY | O_NONBLOCK);
    if(fp == -1){
        printf("Error al abrir el FIFO...\n");
        exit(0);
    }

    printf("Obteniendo información...\n");

    while(1){
        bytesleidos = read(fp, buffer, 1);
        if(bytesleidos > 0){
            printf("%c", buffer[0]);
        }
        
        if(bytesleidos >= sizeof(buffer)){
            break;
        }
    }

    close(fp);
    return 0;
}