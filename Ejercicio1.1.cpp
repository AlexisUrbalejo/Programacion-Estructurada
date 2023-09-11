/*1.- Algoritmo que lea 4 calificaciones de un alumno, calcular y desplegar el promedio acompañado de la leyenda 
APROBADO o REPROBADO*/
#include<stdio.h>
#include<math.h>

int main()
{
    float cal1,cal2,cal3,cal4,prom;
    printf("Ingresa la primer calificacion: ");
    scanf("%f",&cal1);
    printf("Ingresa la segunda calificacion: ");
    scanf("%f",&cal2);
    printf("Ingresa la tercer calificacion: ");
    scanf("%f",&cal3);
    printf("Ingresa la cuarta calificacion: ");
    scanf("%f",&cal4);
    prom=(cal1+cal2+cal3+cal4)/4;
    if (prom>=60)
    {    
        printf("Tu promedio es de: %.2f\n",prom);
        printf("Has APROBADO");
    }
    if (prom<60)
    {    
        printf("Tu promedio es de: %.2f\n",prom);
        printf("Has REPROBADO");
    }
    return 0;
    


}