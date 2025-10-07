/*********************************************
* Fecha: 7/10/2025
* Autor: Santiago Jose Hernandez
* Materia: Sistemas Operativos
* Tema: Duplicidad de procesos y comunicación
*       entre procesos usando PIPE
 * crea un pipe, el hijo lee desde el pipe y el
 * padre escribe en el pipe
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void) {
    int pipefd[2];  // pipefd[0] = lectura, pipefd[1] = escritura
    pid_t pHijo_PID;

    if (pipe(pipefd) == -1) { // crea el pipe
        perror("PIPE");
        exit(EXIT_FAILURE);
  }

    /* se identifica el hijo con el PID*/
    pHijo_PID = fork();
    if (pHijo_PID == -1) {
        perror("FORK");
        exit(EXIT_FAILURE);
    }

    /* si es == a 0 cierro la salida*/
    if (pHijo_PID == 0) {
        close(pipefd[1]);  

        char mensaje[100];
        ssize_t lecturaBYTES = read(pipefd[0], mensaje, sizeof(mensaje));
        if (lecturaBYTES == -1) {
            perror("ESCRITURA");
            exit(EXIT_FAILURE);
        }

        mensaje[lecturaBYTES] = '\0';
printf("Proceso HIJO (%d): Recibe mensaje del PADRE: \"%s\"\n",
               getpid(), mensaje);

        close(pipefd[0]);  
    } else {
        close(pipefd[0]); 

        char mensajePADRE[] = "Hola, SOY TU PADRE, LUKE!!!";
        int escriturBytes;
 escriturBytes = write(pipefd[1], mensajePADRE, strlen(mensajePADRE));
        if (escriturBytes == -1) {
            perror("ESCRITURA");
            exit(EXIT_FAILURE);
        }
   close(pipefd[1]);  
    }

    printf("fin.....\n");
    return 0;
}
