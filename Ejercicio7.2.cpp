#include <stdio.h>
#include <string.h>

//Declaracion de mis funciones
void con_may(char cadena[]);
void con_min(char cadena[]); 
void con_cap(char cadena[]);
void carateres(char cadena[]);
void invertirCadena(char cadena[]);
void eliminarEspacios(char cadena[]);
void combo(char cadena[]);

int main() 
{
    int opcion;
    char cadena[100];

    printf("Ingrese una cadena: ");
    fgets(cadena, 100, stdin);
    do 
    {
        printf("\nElija una opcion:\n");
        printf("1. Mayusculas\n");
        printf("2. Minusculas\n");
        printf("3. CAPITAL\n");
        printf("4. Cantidad de caracteres\n");
        printf("5. Invertir cadena\n");
        printf("6. Eliminar espacios\n");
        printf("7. Todas las anteriores\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        

        switch (opcion) 
        {
            case 1:
                con_may(cadena);
                
                break;
            case 2:
                con_min(cadena);
                
                break;
            case 3:
                con_cap(cadena);
                
                break;
            case 4:
                carateres(cadena);
                
                break;
            case 5:
                invertirCadena(cadena);
                
                break;
            case 6:
                eliminarEspacios(cadena);
                
                break;
            case 7:
                combo(cadena);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } 
    while (opcion != 0);
    
    return 0;
    
}
void con_may(char cadena[]) 
{
    int i;
    int largo = strlen(cadena);
    char copia[strlen(cadena) + 1];
    strcpy(copia, cadena);
    
    for(i = 0; i < largo; i++) 
    {
        if(cadena[i] >= 'a' && cadena[i] <= 'z') 
        {
            cadena[i] = cadena[i] - 32;
        }
    }
    printf("Cadena en mayusculas: %s\n",cadena);
    strcpy(cadena, copia);
}
void con_min(char cadena[]) 
{
    int i = 0;
    char copia[strlen(cadena) + 1];
    strcpy(copia, cadena);
    while (cadena[i] != '\0') 
    {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') 
        {
            cadena[i] = cadena[i] + 32;
        }
        i++;
    }
    printf("Cadena en minusculas: %s\n",cadena);
    strcpy(cadena, copia);
}
void con_cap(char cadena[]) 
{
    int i;
    int largo = strlen(cadena);
    int anteriorEraEspacio = 1;
    char copia[strlen(cadena) + 1];
    strcpy(copia, cadena);
    
    for(i = 0; i < largo; i++) 
    {
        if(anteriorEraEspacio && cadena[i] >= 'a' && cadena[i] <= 'z') 
        {
            cadena[i] = cadena[i] - 32;
        }
        anteriorEraEspacio = (cadena[i] == ' '); 
    }
    printf("Cadena en capitales: %s\n",cadena);
    strcpy(cadena, copia);
}
void carateres(char cadena[]) 
{
    int i = 0;
    char copia[strlen(cadena) + 1];
    strcpy(copia, cadena);

    while (cadena[i] != '\0') 
    {
        i++;
    }
    printf("Cantidad de caracteres: %d\n",i);
    strcpy(cadena, copia);
    
}
void invertirCadena(char cadena[]) 
{
    int longitud = strlen(cadena);
    char aux;
    char copia[strlen(cadena) + 1];
    strcpy(copia, cadena);

    for (int i = 0; i < longitud/2; i++) 
    {
        aux = cadena[i];
        cadena[i] = cadena[longitud-1-i];
        cadena[longitud-1-i] = aux;
    }
    printf("Cadena invertida: %s\n",cadena);
    strcpy(cadena, copia);
}
void eliminarEspacios(char cadena[]) 
{
    int i, j = 0;
    char copia[strlen(cadena) + 1];
    strcpy(copia, cadena);

    for (i = 0; cadena[i]; i++) 
    {
        if (cadena[i] != ' ') 
        {
            cadena[j++] = cadena[i];
        }
    }
    cadena[j] = '\0';
    printf("Cadena sin espacios: %s\n",cadena);
    strcpy(cadena, copia);
}
void combo(char cadena[])
{
    con_may(cadena);
    con_min(cadena);
    con_cap(cadena);
    carateres(cadena);
    invertirCadena(cadena);
    eliminarEspacios(cadena);

}