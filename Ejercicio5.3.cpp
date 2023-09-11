/*función en C que lea 3 números y desplegar el número del medio (usar AND o OR)*/

#include<stdio.h>

int main ()
{
    float num1, num2, num3;
    printf("Ingresa el primer numero: ");
    scanf("%f",&num1);
    printf("Ingresa el segundo numero: ");
    scanf("%f",&num2);
    printf("Ingresa el tercer numero: ");
    scanf("%f",&num3);

    if (num1 > num2 & num1 < num3 || num1 > num3 & num1 < num2)
    {
        printf ("El numero %.2f es el de en medio",num1);
        
    }
    else
    {
        if ( num2 > num1 & num2 < num3 || num2 < num1 & num2 > num3)
        {
            printf("El numero %.2f es el de en medio",num2);
        }
        else 
        {
            printf("El numero %.2f es el de en medio",num3);
        }
    }

}