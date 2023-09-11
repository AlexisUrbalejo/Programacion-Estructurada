/*8.- Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera) para 1 jugador y 
la computadora, (usar condición anidada)*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
    int jugador,compu;
    printf("JUEGO DEL CHINCHAMPU \n");
    printf(" 1.-Piedra \n 2.-Papel \n 3.-Tijeras \n");
    printf("Ingresa que opcion quieres: ");
    scanf("%d",&jugador);
    srand(time(NULL));
    compu = (rand()%3)+1;
    printf("---------------------------------- \n");
    if(compu == 1)
    {
        printf("La computadora eligio piedra \n");
    }
    else
    {
        if(compu == 2)
        {
            printf("La computadora eligio papel \n");
        }
        else
        {
            printf("La computadora eligio tijeras \n");
        }
    }
    if(jugador == 1)
    {
        if(compu == 3)
        {
            printf("Ganaste!");
        }
        else
        {
            if(compu == 2)
            {
                printf("Gana la computadora");
            }
            else
            {
                printf("Empate");
            }
        }
    }
    else
    {
        if(jugador == 2)
        {
            if(compu == 1)
            {
                printf("Ganaste!");
            }
            else
            {
                if(compu == 3)
                {
                    printf("Gana la computadora");
                }
                else
                {
                    printf("Empate");
                }
            }
        }
        else
        {
            if(jugador == 3)
            {
                if(compu == 2)
                {
                    printf("Ganaste!");
                }
                else
                {
                    if(compu == 1)
                    {
                        printf("Gana la computadora");
                    }
                    else
                    {
                        printf("Empate");
                    }
                }
            }
            else
            {
                printf("Jugada no valida");
            }
        }
    }
    return 0;
}
 