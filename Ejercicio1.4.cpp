/*1.- Programa en C que use un menú para realizar las 4 operaciones básicas, donde el usuario introduce 2 
números enteros y realizará la operación según sea su selección del menú.
MENÚ
1.- Suma
2.- Resta
3.- Multiplicación
4.-División*/
#include <stdio.h>
int main()
{
    float num1,num2, opcion, sum, resta, multi, divi;
    printf("TIPOS DE OPERACIONES: \n 1 Suma \n 2 Resta \n 3 Multiplicacion \n 4 Division \n  ");
    printf("Ingresa una opcion: ");
    scanf("%f",&opcion);
    printf("Ingresa el primer numero: ");
    scanf("%f",&num1);
    printf("Ingresa el segundo numero: ");
    scanf("%f",&num2);
    
    if (opcion == 1)
    {
       
        sum = num1 + num2;
        printf("La suma de %.2f + %.2f da como resultado: %.2f", num1, num2, sum);
    }
    else
    {
        if (opcion == 2)
        {
            resta = num1 - num2;
            printf("La resta de %.2f - %.2f da como resultado: %.2f", num1, num2, resta);
        }
        else 
        {
            if ( opcion == 3)
            {
                multi = num1 * num2;
                printf("La multiplicacion de %.2f * %.2f da como resultado : %.2f", num1, num2, multi);
            }
            else 
            {
                if ( opcion == 4)
                {
                    divi = num1 / num2;
                    printf("La division de %.2f / %.2f da como resultado : %.2f", num1, num2, divi);                
                    }
            }
        }
    }



return 0;

}