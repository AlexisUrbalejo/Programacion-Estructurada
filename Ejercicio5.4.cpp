/* 5.- Programa en C que sirva para desplegar el Total de una llamada telefónica donde se pide como datos de 
entrada los minutos y el tipo de llamada, se cobra de la siguiente manera:
MENÚ
1.- Llamada Local $3.00 sin límite de tiempo
2.- Llamada Nacional $7.00 por los 3 primeros minutos y $2.00 minuto adicional
3.- Llamada Internacional $9.00 por los 2 primeros minutos y $4.00 minuto adicional
Desplegar, Subtotal,Iva (16%) y Total.
*/

#include<stdio.h>

int main()
{
    float minutos, tipo, subtotal, total, iva;
    printf("1 Llamada local \n2 LLmada Nacional \n3 Llamada Internacional \n");
    printf("Ingresa el tipo de llamda que desea realizar: ");
    scanf("%f", &tipo);
    printf("Ingrese el tiempo en minutos de la llamada: ");
    scanf("%f",&minutos);

    if(tipo == 1)
    {
        subtotal = minutos * 3;
    }
    else
    {
        if ( tipo == 2)
        {
            if ( minutos > 3 )
            {
              subtotal = (7 * 3) + ((minutos - 3)*2);  
            }
            else
            {
                subtotal = minutos * 7;
            }
        }
        else
        {
          if ( tipo == 3)
          {
            if (minutos > 2)
            {
                subtotal = ( 9 * 2) + ((minutos - 2)*4);
            }
            else 
            {
                subtotal = minutos * 9;
            }
          }
        }
    
    }
    iva = subtotal * 0.16;
    total = subtotal + iva;
    printf("Subtotal: %f\n",subtotal);
    printf("Iva: %f\n",iva);
    printf("Total:%f\n ", total);

    
}