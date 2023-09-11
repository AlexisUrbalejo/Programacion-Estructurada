/*7- En la materia programación estructurada se aplican 5 exámenes, calcular el promedio final de 
la materia donde la calificación menor de los exámenes se anula y el promedio se calcula en base a 4 exámenes.
Desplegar el promedio final.
*/
#include<stdio.h>

int main()
{
    int exa1, exa2, exa3, exa4,exa5, menor, prom;
    printf("Ingresa la calificiacion del primer examen: ");
    scanf("%d",&exa1);
    printf("Ingresa la calificiacion del segundo examen: ");
    scanf("%d",&exa2);
    printf("Ingresa la calificiacion del tercer examen: ");
    scanf("%d",&exa3);
    printf("Ingresa la calificiacion del cuarto examen: ");
    scanf("%d",&exa4);
    printf("Ingresa la calificiacion del quinto examen: ");
    scanf("%d",&exa5);

    menor = exa1;
    if ( exa2 < menor)
    {
        menor = exa2;
    }
    if( exa3 < menor)
    {
        menor = exa3;
    }
    if ( exa4 < menor)
    {
        menor = exa4;
    }
    if (exa5 < menor)
    {
        exa5 = menor;
    }
    prom = (exa1 + exa2 + exa3 + exa4 + exa5 - menor)/4;
    printf("El promedio es de: %d", prom);

   

}