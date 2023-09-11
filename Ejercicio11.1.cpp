//11.-

#include<stdio.h>

int main()
{
    int minutos,tipo_llam,sub;
    float iva,total;
    printf("TIPOS DE LLAMADA: \n 1.Llamada Local \n 2.Llamada Nacional \n 3.Llamada Internacional");
    printf("\n Selecciona el tipo de llamada: ");
    scanf("%d",&tipo_llam);
    printf("Ingresa los minutos de duracion de la llamada: ");
    scanf("%d",&minutos);
    if(tipo_llam == 1)
    {
        sub = minutos * 3;
    }
    else
    {
        if(tipo_llam == 2)
        {
            if (minutos > 3)
            {
                sub= (3 * 7)+((minutos-3)*2);
            }
            else
            {
                sub = (minutos * 7);
            }
            
        }
        else
        {
            if(tipo_llam == 3)
            {
                if(minutos > 2)
                {
                    sub = (2 * 9)+((minutos-2)*4);
                }
                else
                {
                    sub = (minutos * 9);
                }
            }
            else
            {
                printf("Tipo de llamada no valida");
            }
        }
    }
    iva = sub * 0.16;
    total = sub + iva;
    printf("Subtotal: %d $ \n",sub);
    printf("Iva(16%): %.1f $ \n",iva);
    printf("Total: %.1f $ \n",total);
    return 0;
}