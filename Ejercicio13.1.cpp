#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include<windows.h>
#include "alexis.h"
#define N 2500
typedef struct talum{
        long matricula;
        char nombre[20];
        char ApPat[20];
        char ApMat[20];
        int edad;
        char sexo[20];
        int status;   
    }talum;

int msges();
void menu();
talum agregar(talum vect[],int n);
int validar_matri(int matri, talum vector[], int n);
void imprimir(talum vect[], int n);
void generartxt(talum vect[],int n,char nombrearchivo[]);
int main()
{
    srand(time(NULL));
    menu();
	return 0;
}

int msges()
{   
    int op,menu;
    system ("CLS");
    printf ("---------------------------\n");
    printf ("   M  E   N   U \n");
    printf("1.- AGREGAR AUTOMATICO \n");
    printf("2.- EDITAR REGISTRO \n");
    printf("3.- ELIMINAR REGISTRO \n");
    printf("4.- BUSCAR \n");
    printf("5.- ORDENAR \n");
    printf("6.- IMPRIMIR \n");
    printf("7.- GENERAR ARCHIVO TEXTO \n");
    printf("8.- VER ARCHIVO TEXTO \n");
    printf("9.- CREAR ARCH BINARIO \n");
    printf("10.- CARGAR ARCH BINARIO \n");
    printf("0.- SALIR  \n");
    printf ("---------------------------\n");
    op=validanum_int(0,10,"ELIGE UNA OPCION:","ERROR");
    return op;
}

void menu()
{
    int i,op,total,tam=0,j,k=0,l=0;
    char nom_arch[20] = "Alumnos";
    char nom_arch_bin[20] = "archi";
    char nombrearchivo[20];
    bool cargado_bin = false;
    talum vect[N];
    talum reg;
    do{
        l = k+100;
        op=msges();
        switch (op)
        {
            case 1:
                if(k < N-100)
                {
                    for(i=k; i<l; i++)
                    {
                        vect[i]=agregar(vect,k);
                        k++;
                    }
                }
                break;
            case 2:
                imprimir(vect,k);
                break;
            
		}
    }while (op != 0);
    generartxt(vect,k,nom_arch);
    system("PAUSE");
}
 int cargar_archivo(talum vect[],int n)
{
    int i;
    i = n;
    talum reg;
    char basura[5];
    FILE *arch;
    arch = fopen("datos.txt","r");
    if(arch)
    {
        while(!feof(arch))
        {
            fscanf(arch,"%s%ld%s%s%s%d%s",&basura,&reg.matricula,&reg.nombre,&reg.ApPat,&reg.ApMat,&reg.edad,&reg.sexo);

            vect[i++] = reg;
            if(i == N)
            {
                return i;
            }
        }
        fclose(arch);
    }
    return i;
}

talum agregar(talum vect[],int n)
{
    talum reg;
	char nombres[20][20]={"MARCELO","ALEXIS","JULIO","EMILIANO","SERGIO","ABRAHAM","ROBERTO","JACOB","JOSUE","PABLO","ALDAHIR"};
	char mujeres[20][20]={"ANA","SAMANTHA","KARLA","NANCY","ALEXA","DENISSE","DANIELA","VIVIANA","HANNA","LENY","JULISA"};
	char ApPat[20][20]={"MARQUEZ","RUIZ","PEREZ","ARREDONDO","ZAVALA","ANDRADE","ROJAS","LUNA","HERNANDEZ","GARCIA","SHADE","SIQUEIROS"};
	char ApMat[20][20]={"ONTIVEROS","AVILA","URBALEJO","LOPEZ","HERNANDEZ","CHAVEZ","MORA","CARRILLO","GARCIA","GUZMAN","DIAZ","SANCHEZ"};
    int sexo,status=1;
	long ri3=300000, rf3=399999, rango3,matri;
	strcpy(reg.ApPat,ApPat[rand()%12]);
	strcpy(reg.ApMat,ApMat[rand()%12]);
	sexo=(rand()%2)+1;
	if (sexo==1)
	{
	   	strcpy(reg.sexo,"HOMBRE");
	   	strcpy(reg.nombre,nombres[rand()%11]);
	}
	else
	{
	   	strcpy(reg.sexo,"MUJER");
		strcpy(reg.nombre,mujeres[rand()%11]);
	}
	reg.edad=(rand()%10)+12;
    rango3 = ( rf3 - ri3 ) + 1;
    do{
        matri = (rand()%rango3) + ri3;
    }while(validar_matri(matri,vect,n) != -1);
    reg.matricula = matri; 
    reg.status=status;
	return reg;
    
}

void imprimir(talum vect[], int n)
{
	system("CLS");

	int i;
	printf("   MATRICULA      NOMBRE       APELLIDO PAT    APELLIDO MAT     EDAD        SEXO   \n");
	for(i=0; i<n; i++)
	{
		if (vect[i].status==1)
		{
	     printf("    %6d    %10s    %12s    %12s     %6d    %10s   \n",vect[i].matricula,vect[i].nombre,vect[i].ApPat,vect[i].ApMat,vect[i].edad,vect[i].sexo);
	    }
    }	
	system("PAUSE");	

}
void generartxt(talum vect[],int n,char nombrearchivo[])
{
    int i;
    char nombre_arch[24];
    strcpy(nombre_arch,nombrearchivo);
    strcat(nombre_arch,".txt");
    FILE *arch;
    arch = fopen(nombre_arch,"w");
    fprintf(arch,"----------------------------------------------------------------------------------------- \n");
    fprintf(arch,"  No | MATRICULA | NOMBRE        | APELLIDO P.    |  APELLIDO MAT.   | EDAD  | SEXO       \n");
    fprintf(arch,"----------------------------------------------------------------------------------------- \n");
    if(arch)
    {
        for(i=0; i<n; i++)
        {
            if (vect[i].status==1)
            {
                fprintf(arch,"%d      %6ld     %10s    %12s      %12s      %6d   %10s \n",i,vect[i].matricula,vect[i].nombre,vect[i].ApPat,vect[i].ApMat,vect[i].edad,vect[i].sexo);
            }
        }
        fclose(arch);
    }
}