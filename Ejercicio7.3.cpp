/*7.- Función en C que pida el mes y día de nacimiento de una persona y el programa le despliega el signo del 
zodiaco que le corresponde y su correspondiente horoscopo del Dia.*/

#include <stdio.h>


int main()
{
    int dia,mes;
    printf("Ingresa tu dia de nacimiento: ");
    scanf("%d",&dia);
    printf("Ingresa el numero de mes en que naciste: ");
    scanf("%d",&mes);
    switch(mes)
    {
        case 1:
        if(dia < 20)
        {
            printf("Eres Capricornio \n");
            printf("Cuidadito porque te van a poner el cuerno");
        }
        else
        {
            printf("Eres Acuario \n");
            printf("O te pones las pilas o te carga la que te trajo");
        }
        break;
        case 2:
        if(dia < 19)
        {
            printf("Eres Acuario \n");
            printf("O te pones las pilas o te carga la que te trajo");
        }
        else
        {
            printf("Eres Piscis \n");
            printf("Portate bien con quienes te quieren malagradecido");
        }
        break;
        case 3:
        if(dia < 21)
        {
            printf("Eres Piscis \n");
            printf("Portate bien con quienes te quieren malagradecido");
        }
        else
        {
            printf("Eres Aries \n");
            printf("Mantente ocupado y deja de pensar tontadas");
        }
        break;
        case 4:
        if(dia < 20)
        {
            printf("Eres Aries \n");
            printf("Mantente ocupado y deja de pensar tontadas");
        }
        else
        {
            printf("Eres Tauro \n");
            printf("Bajate de esa nube ");
        }
        break;
        case 5:
        if(dia < 21)
        {
            printf("Eres Tauro \n");
            printf("Bajate de esa nube");
        }
        else
        {
            printf("Eres Geminis \n");
            printf("Eres buena onda pero a vaces caes mal");
        }
        break;
        case 6:
        if(dia < 21)
        {
            printf("Eres Geminis \n");
            printf("Eres buena onda pero a vaces caes mal");
        }
        else
        {
            printf("Eres Cancer \n");
            printf("Consigue trabajo porque no vas a vivir de bonito");
        }
        break;
        case 7:
        if(dia < 23)
        {
            printf("Eres Cancer \n");
            printf("TConsigue trabajo porque no vas a vivir de bonito");
        }
        else
        {
            printf("Eres Leo \n");
            printf("Bajale tres rayitas a tu vanidad");
        }
        break;
        case 8:
        if(dia < 23)
        {
            printf("Eres Leo \n");
            printf("Bajale tres rayitas a tu vanidad");
        }
        else
        {
            printf("Eres Virgo \n");
            printf("Meh, te ira como siempre");
        }
        break;
        case 9:
        if(dia < 23)
        {
            printf("Eres Virgo \n");
            printf("Meh, te ira como siempre");
        }
        else
        {
            printf("Eres Libra \n");
            printf("No andes de quita novios/novias");
        }
        break;
        case 10:
        if(dia < 23)
        {
            printf("Eres Libra \n");
            printf("No andes de quita novios/novias");
        }
        else
        {
            printf("Eres Escorpio \n");
            printf("El mejor signo, todo te sale bien:)");
        }
        break;
        case 11:
        if(dia < 22)
        {
            printf("Eres Escorpio \n");
            printf("El mejor signo, todo te sale bien:)");
        }
        else
        {
            printf("Eres Sagitario \n");
            printf("Ponte a estudiar porque tienes examen sorpresa");
        }
        break;
        case 12:
        if(dia < 22)
        {
            printf("Eres Sagitario \n");
            printf("Ponte a estudiar porque tienes examen sorpresa");
        }
        else
        {
            printf("Eres Capricornio \n");
            printf("Cuidadito que te van a poner el cuerno");
        }
        break;
    }
    return 0;
}

