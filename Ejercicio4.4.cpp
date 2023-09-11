/*4.- Programa en C que sirva para calcular el salario semanal de un trabajador donde se obtiene como dato de 
entrada las horas semanales trabajadas, el salario por hora.

El programa deberá calcular el salario normal, salario extra y salario total, considerando lo siguiente:
Jornada Normal de 40 horas.
El salario normal se considera las horas trabajadas menores o igual a la jornada normal
Salario extra se considera las horas trabajadas mayores a la jornada normal y se pagan dobles las primeras 9 y 
triples a partir de la décima hora extra
*/
#include<stdio.h>

int main ()
{
    int horas,salario, jornada, total,extra, normal;
    printf("Ingresa cuantas horas trabjaste en la semana: ");
    scanf("%d",&horas);
    printf("Ingresa cuanto ganas por hora: ");
    scanf("%d",&salario);
    jornada = 40;

    if (horas > 40 )
    {
        if (horas > 49)
        {
            normal = (salario * jornada );
            extra =  ((salario * 9) * 2) + (((horas - 49)* salario) *3);
        }
        else 
        {
            normal = (salario * jornada) ;
            extra = (((horas - jornada) * salario)*2);
        }
    }
    else 
    {
      normal = salario * horas;
      extra = 0;
    }
    total = normal + extra;
    printf("Horas trabjadas: %d \n",horas);
    printf("Salario pro hora: %d \n",salario);
    printf ("Salario Normal: %d \n" , normal);
    printf("Salario Extra:  %d \n", extra);
    printf( "Salario total:  %d \n", total);
    return 0;
}