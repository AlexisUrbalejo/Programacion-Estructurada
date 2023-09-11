/*1.- Programa en C que lea 3 calificaciones calcule el promedio del alumno y desplegar: 
Si prom < 30 Repetir 
Si prom >=30 y prom <60 extraordinario 
Si prom >=60 y prom <70 suficiente 
Si prom >=70 y prom <80 Regular 
Si prom >=80 y prom <90 bien 
Si prom >=90 y prom <98 muy bien 
Si prom >=98 y prom <=100 excelente 
Si prom >100 Error en promedio */

#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int i;
    float cal,suma,prom;

   for(i=0;i<3;i++) 
   {
     printf(" Ingresa la calificacion %d:  ",i+1);
     scanf("%f",&cal);
     suma = suma + cal;
   }
   prom = suma / i;
   printf("El promedio es: %.1f \n",prom);
   if(prom >= 80)
    {
        if(prom >= 98)
        {
            if(prom >= 100)
            {
                printf("Error en el promedio");
            }
            else
            {
                printf("Excelente");
            }
        }
        else
        {
            if(prom >= 90)
            {
                printf("Muy bien");
            }
            else
            {
                printf("Bien");
            }
        }
    }
    else
    {
        if(prom >= 60)
        {
            if(prom >= 70)
            {
                printf("Regular");
            }
            else
            {
                printf("Suficiente");
            }
        }
        else
        {
            if(prom >= 30)
            {
                printf("Extraordinario");
            }
            else
            {
                printf("Repetir");
            }
        }
    }
    return 0;
}

    

