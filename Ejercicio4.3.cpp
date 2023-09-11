/*4.- Función en C que lea 3 números y desplegar cuál número es el mayor (usar AND o OR)*/

#include<stdio.h>

int main()
{
    int num1,num2,num3;
    printf("Ingresa el primer numero: ");
    scanf("%d",&num1);
    printf("Ingresa elsegundo numero: ");
    scanf("%d",&num2);
    printf("Ingresa el tercer numero: ");
    scanf("%d",&num3);

    if ( num1 > num2 & num1 > num3)
    {
        printf("El numero %d es el mayor",num1);
    }
    else 
    {
        if (num2 > num1 & num2 > num3)
        {
            printf("El numero %d es el mayor",num2);

        }
        else
        {

            printf("El numero %d es el mayor",num3);
          
        }
    
    }
    return 0;
}