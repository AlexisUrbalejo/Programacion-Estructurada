/*5.- Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar: 
Si prom < 30 Repetir 
Si prom >=30 y prom <60 extraordinario 
Si prom >=60 y prom <70 suficiente 
Si prom >=70 y prom <80 Regular 
Si prom >=80 y prom <90 bien 
Si prom >=90 y prom <98 muy bien 
Si prom >=98 y prom <=100 excelente 
Si prom >100 Error en promedio */
#include<stdio.h>
#include<math.h>

int main()
{
    float cal1,cal2,cal3,prom;
    printf("Ingresa la primer calificacion: ");
    scanf("%f",&cal1);
    printf("Ingresa la segunda calificacion: ");
    scanf("%f",&cal2);
    printf("Ingresa la tercera calificacion: ");
    scanf("%f",&cal3);
    prom=(cal1+cal2+cal3)/3;
    if(prom>=30)
    {
      if(prom>=60)
      {
        if(prom>=70)
        {
            if(prom>=80)
            {
                if (prom>=90)
                {
                    if(prom>=98)
                    {
                        if (prom>100)
                        {
                        printf("Error en promedio");
                        }
                        else
                        {
                         printf("Excelente"); 
                        }
                      
                    }
                    else
                    {
                        printf("Muy bien");
                    }
                    
                }
                else
                {
                   printf("Bien"); 
                }
                
            }
            else
            {
             printf("Regular");   
            }
            
        }
        else
        {
            printf("Suficiente");
        }
      }
      else
      {
       printf("Extraordinario");
      }
    }
    else 
    {
     printf ("Repetir");
    }

return 0;
}