/*2.- Programa en C que use un menú para realizar conversiones de unidades de medida, 
donde el usuario selecciona una opción y realizará la opción según sea su selección del menú.
MENÚ
1.- cm a pulgadas
2.- cm a pies
3.- Km a millas
4.- Pulgadas a cm
5.- pies a cm
6.- millas a Km*/

#include<stdio.h>
int main ()
{
    float cm, pulg,mill, ft, km, opc, cantidad;
    printf("MENU: \n 1 cm a pulgadas \n 2 cm a pies \n 3 Km a millas \n 4 Pulgadas a cm \n 5 Pies a cm \n 6 Millas a Km \n");
    printf("Ingresa la conversion que desea realizar: ");
    scanf("%f",&opc);
    printf("Ingresa la cantidad que desea convertir: ");
    scanf("%f",&cantidad);
    if (opc == 1)
    {
        pulg = cantidad / 2.54;
        printf("La conversion de %f cm a pulgadas es de : %.2f", cantidad, pulg);
    }
    else 
    {
        if( opc == 2)
        {
            ft = cantidad / 30.48;
            printf(" La conversion de  %f cm a pies es de : %.2f", cantidad, ft);
        }
        else 
        {
            if ( opc == 3)
            {
                mill = cantidad / 1.6093;
                printf(" La conversion de  %f Km a millas es de : %.2f", cantidad, mill);

            }
            else 
            {
                if ( opc == 4)
                {
                    pulg = cantidad * 2.54;
                    printf(" La conversion de  %f pulgadas a cm es de : %.2f", cantidad, pulg);

                }
                else
                {
                    if ( opc == 5)
                    {
                        cm = cantidad * 30.48;
                        printf(" La conversion de  %f pies a cm es de : %.2f", cantidad, cm);

                    }
                    else 
                    {
                        km = cantidad * 1.6093;
                        printf(" La conversion de  %f millas a Km es de : %.2f", cantidad, km);

                    }
                }
            
                
            }
        
            
        }
        

    }

return 0;

}