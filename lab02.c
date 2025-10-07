/*********************************************
* Fecha: 7/10/2025
* Autor:Santiago Jose hernandez
* Materia: Sistemas Operativos
* Tema: Duplicidad de procesos y caos en creacion de procesos padre e hijo
*Este programa cuenta con una gran cantidad de caos, da numeros diferentes
* a pesar de contar con la misma ejecucion
**********************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    /* Se inicia el proceso */
    printf("#=> Inicio del proceso main o proceso principal <=#\n\n\n");

    int procesoID = fork();

    /* Proceso HIJO */
    if(procesoID == 0){
  printf("\t #==> Proceso Hijo recién Creado \n");
    } 
    /* Proceso PADRE */
    else {
        printf("\t #==> Proceso Padre \n");
    }

    printf("Imprimiendo .... \n");
    for(int i = 0; i < 5; i++){
        printf("\t\t == %d == \n", i);
  }
    /* Se marca el fin del proceso */
    printf("FIN .... \n");

    return 0;
}
