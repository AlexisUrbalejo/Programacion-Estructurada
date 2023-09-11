/*6.- Programa en C que sirva para calcular el Total a pagar por consumo de agua, donde el dato de 
entrada son los M3 de agua consumidos, Tomar en cuenta que se cobra escalonada de la Siguiente manera:
Rango1: 0 al 4 M3 $50 x facturación sin importar cuánto consumió en este rango
Rango2: 5 a 15 M3 $8.00 x M3
Rango3: 16 a 50 M3 $10.00 x M3
Rango4: 51 M3 en adelante $11.00 x M3
Nota: Desplegar SubTotal, Iva(16%), y Total a pagar.*/

#include<stdio.h>

int main ()
{
    float m3, subtotal, total, iva, extra;

    printf ("Ingrese la cantidad de metros cubicos de agua gastada: ");
    scanf("%f",&m3);
    if (m3 > 16)
    {
        if ( m3 > 50)
        {
            extra= (m3-50);
           subtotal =(50) + (8*11) + (35*10) + (extra*11);

        }
        else
        {
            extra = m3-15;
            subtotal = (50) + (8*11) + (extra*10);
        }
    }
    else
    {
        if (m3 >= 5)
        {
            extra = m3 - 4;
            subtotal = (50) + (extra*8);
        }
      
    else
    {
        subtotal =50;
    }
        
    }
    iva = subtotal * 0.16;
    total = subtotal + iva;
    printf("El subtotal es de: %f pesos\n",subtotal);
    printf("El iva es de: %f pesos\n",iva);
    printf("El total es de: %f pesos\n",total);
     
}