/*6.- Función en C que lea 3 números y despegarlos en forma ascendente (usar AND o OR)*/

#include<stdio.h>

int main()
{
    float num1, num2, num3;
    printf("Ingresa el primer numero: ");
    scanf("%f",&num1);
    printf("Ingresa el segundo numero: ");
    scanf("%f",&num2);
    printf("Ingresa el tercer numero: ");
    scanf("%f",&num3);
     if(num1 > num2 & num1 > num3)
    {
        if(num2>num3)
        {
            printf("El ordende los numeros es: %.2f, %.2f, %.2f",num3,num2,num1);
        }
        else
        {
            printf("El orden de los numeros es: %.2f, %.2f, %.2f",num2,num3,num1);
        }
    }

    if(num2 > num1 & num2 > num3)
    {
        if(num1>num3)
        {
            printf("El orden de los numeros es: %.2f, %.2f, %.2f",num3,num1,num2);
        }
        else
        {
            printf("El orden de los numeros es: %.2f, %.2f, %.2f",num1,num3,num2);
        }
    }
    if(num3 > num1 & num3 > num2)
    {
        if(num1>num2)
        {
            printf("El orden de los numeros es: %.2f, %.2f, %.2f",num2,num1,num3);
        }
        else
        {
            printf("El orden de los numeros es: %.2f, %.2f, %.2f",num1,num2,num3);
        }
    }
    return 0;

}
