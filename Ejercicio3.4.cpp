/*3.- Programa en C que lea 6 números, desplegar el valor del número mayor.*/

#include <stdio.h>
 int main ()
 {
    int num1, num3, num2,num4, num5, num6, mayor;
    printf("Ingresa el primer numero: ");
    scanf("%d",&num1);
    printf("Ingresa el segundo numero: ");
    scanf("%d",&num2);
    printf("Ingresa el tercer numero: ");
    scanf("%d",&num3);
    printf("Ingresa el cuarto numero: ");
    scanf("%d",&num4);
    printf("Ingresa el quinto numero: ");
    scanf("%d",&num5);
    printf("Ingresa el sexto numero: ");
    scanf("%d",&num6);
    mayor = num1;
    if (num2 > mayor)
    {
      mayor = num2;
    }
    if ( num3 > mayor)
    {
      mayor = num3;
    }
    if ( num4 > mayor)
    {
      mayor = num4;
    }
    if (num5 > mayor)
    {
      mayor = num5;
    }
    if ( num6 > mayor)
    {
      mayor = num6;
    }
   printf("El numero mayor es: %d",mayor);
   return 0;
 }