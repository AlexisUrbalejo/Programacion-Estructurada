#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int valinum(int ri, int rf, const char msge[]);
int Valicad(char cadena[],int in);



int valinum(int ri, int rf, const char msge[])
{
    char xnum[30];
    int num,op;
    do{
        printf("%s",msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if(num<ri || num>rf)
        {
            printf("ERROR: Numero fuera de rango, intente de nuevo \n");
            system("PAUSE");
        }
    

    }while(num<ri || num>rf);
    return num;
}

int Valicad(char cadena[])
{
     int i;
    
    do
    {
        for(i = 0; i < strlen(cadena); i++) 
        {
            if(isdigit(cadena[i]) || (cadena[i]==' ' && cadena[i+1]==' ')) 
            {
                return 1;
            }
        }
    }while(isdigit(cadena[i]) != 0);
        return 0;
}