/*6.- Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar: 
Si prom < 30 Repetir 
Si prom >=30 y prom <60 extraordinario 
Si prom >=60 y prom <70 suficiente 
Si prom >=70 y prom <80 Regular 
Si prom >=80 y prom <90 bien 
Si prom >=90 y prom <98 muy bien 
Si prom >=98 y prom <=100 excelente 
Si prom >100 Error en promedio */

#include<stdio.h>

int main()
{
    float cal1,cal2,cal3,prom;
    printf("Ingresa la primer calificacion: ");
    scanf("%f",&cal1);
    printf("Ingresa la segunda calificacion: ");
    scanf("%f",&cal2);
    printf("Ingresa la tercer calificacion: ");
    scanf("%f",&cal3);
    prom = (cal1+cal2+cal3) / 3;
    printf("El promedio es: %.1f \n",prom);
    if(prom<30)
    {
        printf("Repetir");
    }
    else
    {
        if (prom<60)
        {
            printf("Extraordinario");
        }
        else
        {
            if(prom<70)
            {
                printf("Suficiente");
            }
            else
            {
                if(prom<80)
                {
                    printf("Regular");
                }
                else
                {
                    if(prom<90)
                    {
                        printf("Bien");
                    }
                    else
                    {
                        if(prom<98)
                        {
                            printf("Muy bien");
                        }
                        else
                        {
                            if(prom<=100)
                            {
                                printf("Excelente");
                            }
                            else
                            {
                                printf("Error en promedio");
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}