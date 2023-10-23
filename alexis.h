#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int valinum(int ri, int rf, const char msge[]);
int Valicad(char cadena[],int in);

char Consonantes (char cadena[30],int in);
void Mayus (char cadena[]);
char Vocales (char cadena[30]);

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


char Consonantes (char cadena[30],int in)
{
    int i,tam;
    tam=strlen(cadena);
    for(i=in;i<tam-1;i++)
    {
        char car=cadena[i];
        if(car!='A' && car!='a' && car!='E' && car!='e' && car!='I' && car!='i' && car!='O' && car!='o' && car!='U' && car!='u')
        {
            return car;   
        }
    }
    return 'X';
}

void Mayus (char cadena[20])
{
    int i,tam;
    tam=strlen(cadena);
    for(i=0;i<tam;i++)
    {
        if(cadena[i]>= 'a' && cadena[i]<= 'z')
        {
            cadena[i]=cadena[i]-32;
        }
    }
}

char Vocales(char cadena[30],int in)
{
    int i,tam;
    tam=strlen(cadena);
    for(i=in;i<tam-1;i++)
    {
        char car=cadena[i];
        if(car=='A' || car=='a' || car=='E' || car=='e' || car=='I' || car=='i' || car=='O' || car=='o' || car=='U' || car=='u')
        {
            return car;   
        }
    }
    return 'X';

}


int Estados()
{
    printf("1-Aguascalientes        2-Baja California \n" );
    printf("3-Baja California Sur   4-Campeche \n"        );
    printf("5- Coahuila             6-Colima \n"          );         
    printf("7-Chiapas               8-Chihuahua \n"       );
    printf("9-Distrito Federal      10-Durango \n"        );
    printf("11-Guanajuato           12-Guerrero \n"       ); 
    printf("13-Hidalgo              14-Jalisco \n"        );
    printf("15-Mexico               16-Michoacan \n"      );
    printf("17-Morelos              18-Nayarit \n"        );
    printf("19-Nuevo Leon           20-Oaxaca \n"         );
    printf("21-Puebla               22-Queretaro \n"      );
    printf("23-Quintana Roo         24-San Luis Potosi \n");
    printf("25-Sinaloa              26-Sonora \n"         );
    printf("27-Tabasco              28-Tamaulipas \n"     );
    printf("29-Tlaxcala             30-Veracruz \n"       );
    printf("31-Yucatan              32-Zacatecas \n"      );
    printf("         33-Extranjero \n               "     );
}