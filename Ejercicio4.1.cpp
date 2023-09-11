/*4.- Algoritmo que a través de opciones (1.- HOMBRE 2.- MUJER ) preguntar al usuario cual es su SEXO y 
desplegar la leyenda “HOLA, ERES HOMBRE ”, “ HOLA, ERES MUJER”*/
#include<stdio.h>
#include<math.h>
 int main()
 {
    int sexo;
    printf("1 HOMBRE\n");
    printf("2 MUJER\n");
    printf("Ingresa el sexo con el que te identificas (1 o 2): ");
    scanf("%d",&sexo);
    if (sexo == 1)
    {
        printf("HOLA, ERES HOMBRE");
    }
    else
    {
        printf("HOLA, ERES MUJER");
    }
     return 0;

 }