/* 9.- Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera) para 1 jugador y 
la computadora, (usar selección múltiple)*/
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
    switch(compu)
    {
        case 1:
        printf("La computadora eligio piedra \n");
        break;
        case 2:
        printf("La computadora eligio papel \n");
        break;
        case 3:
        printf("La computadora elgio tijeras \n");
        break;
    }
    switch(compu)
    {
        case 1:
        switch(jugador)
        {
            case 1:
            printf("Empate");
            break;
            case 2:
            printf("Ganaste!");
            break;
            case 3:
            printf("Gana la computadora");
            break;
        }
        break;
        case 2:
        switch(jugador)
        {
            case 1:
            printf("Gana la computadora");
            break;
            case 2:
            printf("Empate");
            break;
            case 3:
            printf("Ganaste!");
            break;
        }
        break;
        case 3:
        switch(jugador)
        {
            case 1:
            printf("Ganaste!");
            break;
            case 2:
            printf("Gana la computadora");
            break;
            case 3:
            printf("Empate");
            break;
        }
        break;
    }
    return 0;
}