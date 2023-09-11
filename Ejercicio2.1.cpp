/*2.- Algoritmo que lea un número entero, y desplegar si el número es “PAR” o “IMPAR”*/
#include<stdio.h>
#include<math.h>

int main()
{
    int num;
    printf("Ingresa un numero entero: ");
    scanf("%d",&num);
    if ((num % 2) == 0)
    {
        printf("El numero es PAR\n");
    }
    if ((num % 2) == 1)
    {
        printf("El numero es IMPAR\n");
    }
    return 0;
}