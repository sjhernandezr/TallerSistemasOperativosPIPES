/*****************
* fecha 7/10/2025
*autor Santiago Jose Hernandez
* Materia: Sistemas operativos
*Profesor: Jhon corredor
*Tema: funcion Fork, creacion de procesos
* Descripcion: Demostrar el uso de fork para la creacion de procesos hijos
* ***********************************/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*Se inicia el main/
int main (){

int procesoID = fork();
/*proceso padre*/
if (procesoID >0){
printf( "\t ##==>Proceso padre con ID %d \n", getpid());
}else {
/* Proceso hijo*/
printf("\t ##==>Proceso hijo con ID %d \n", getpid());

}
printf ("A partir de aqui es el proceso main del proceso principal");
return 0;

}