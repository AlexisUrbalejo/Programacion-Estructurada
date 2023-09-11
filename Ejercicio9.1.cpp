//9.-Algoritmo que lea 3 numeros y desplegar los 3 numeros en orden ascendente

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
    if(num1>num2)
    {
        if(num1>num3)
        {
            if(num2>num3)
            {
                printf("El orden de los numeros es: \n %.2f \n %.2f \n %.2f",num3,num2,num1);
            }
            else
            {
                printf("El orden de los numeros es: \n %.2f \n %.2f \n %.2f",num2,num3,num1);
            }
        }
        else
        {
            printf("El orden de los numeros es: \n %.2f \n %.2f \n %.2f",num2,num1,num3);
        }
    }
    else
    {
        if(num2>num3)
        {
            if(num1>num3)
            {
                printf("El orden de los numeros es: \n %.2f \n %.2f \n %.2f",num3,num1,num2);
            }
            else
            {
                printf("El orden de los numeros es: \n %.2f \n %.2f \n %.2f",num1,num3,num2);
            }
        }
        else
        {
            printf("El orden de los numeros es: \n %.2f \n %.2f \n %.2f",num1,num2,num3);
        }
    }
    return 0;
}