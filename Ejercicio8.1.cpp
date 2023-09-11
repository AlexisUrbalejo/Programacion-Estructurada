//8.- Algoritmo que lea 3 numeros y desplegar cual numero es del medio y su valor


#include<stdio.h>

int main()
{
    float num1,num2,num3;
    printf("Inresa el primer numero: ");
    scanf("%f",&num1);
    printf("Inresa el segundo numero: ");
    scanf("%f",&num2);
    printf("Inresa el tercer numero: ");
    scanf("%f",&num3);
    if(num1 > num2)
    {
        if(num1>num3)
        {
            if(num2>num3)
            {
                printf("El numero del medio es: %.2f (segundo numero)",num2);
            }
            else
            {
                printf("El numero del medio es %.2f (tercer numero)",num3);
            }
        }
        else
        {
            printf("El numero del medio es %.2f (primer numero)",num1);
        }
    }
    else
    {
        if(num2>num3)
        {
            if(num1>num3)
            {
                printf("El numero de en medio es %.2f (primer numero)",num1);
            }
            else
            {
                printf("El numero de en medio es %.2f (tercer numero)",num3);
            }
        }
        else
        {
            printf("El numero de en medio es: %.2f (segundo numero)",num2);
        }
    }
    return 0;
}