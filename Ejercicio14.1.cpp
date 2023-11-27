#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "alexis.h"
#define N 2700

bool ordenado = false;

typedef struct talum{
        int matricula;
        char nombre[20];
        char appat[20];
        char apmat[20];
        int edad;
        char sexo[20];
        int status;   
    }talum;

typedef struct tindex{
        long matricula;
        int indice;   
    }tindex;

int msges();
void menu();
talum agregar(talum vect[],int n);
void prntbin(talum vect[],int n);
void buscar(talum vect[], int n);
void cargarind(tindex vect[],int n);
void eliminar(tindex vect[], int n);
int leebinario(talum vect[],int n);
void archtext(talum vect[],tindex vect_index[],int n,char nombrearchivo[]);
void generarbin(void);
void buscar_principal(talum vect[],int n);
void imprimirtxt(char nombrearchivo[]);
int validar_matri(int matri, talum vector[], int n);
void ordenar(tindex vect[], int n);
void burbuja(tindex vect[],int n);
void buscar(tindex vect[], int n);
void quicksort(tindex vect[], int primero, int ultimo);
void imprimir_ord(tindex vect[], int n);
void empaquetar(int n);

int main()
{
    srand(time(NULL));
    menu();
	return 0;
}

int msges()
{   
    int op,menu;
    printf ("   M E N U\n");
        printf("1.- Agregar\n");
        printf("2.- Eliminar\n");
        printf("3.- Buscar\n");
        printf("4.- Ordenar\n");
        printf("5.- Imprimir registros archivo original\n");
        printf("6.- Imprimir registros archivo ordenado\n");
        printf("7.- Generar archivo de texto\n");
        printf("8.- Empaquetar \n"); 
        printf("0.- Salir  \n");
    op=valinum(0,8,"Elige una opcion:");
    return op;
}

void menu()
{
    int i,op,total,tam=0,j,k=0,l=0;
    char nom_arch[20] = "Alumnos";
    char nom_arch_bin[20] = "archi";
    char nombrearchivo[20];
    generarbin();
    bool cargado_bin = false;
    talum vect[N];
    tindex vect_index[N];
    cargarind(vect_index,0);
    k = leebinario(vect,k);
    do{
        op=msges();
        switch (op)
        {
            case 1:
                if(k < N-1)
                {
                    vect[i]=agregar(vect,k);
                    k++;
                    ordenado = false;
                    cargarind(vect_index,0);
                }
                break;
            case 2:
                eliminar(vect_index,k);
                break;
            case 3:
                buscar(vect_index,k);
                break;
            case 4:
                if(ordenado==false)
                {
                    ordenar(vect_index,k);
                    ordenado = true;
                }
                else
                {
                    printf("El vector ya esta ordenado \n");
                    system("PAUSE");
                }
                break;
            case 5:
                prntbin(vect,k);
                break;
            case 6:
                imprimir_ord(vect_index,k);
                break;
            case 7:
                printf("Ingrese el nombre para guardar su archivo de texto: ");
                fflush(stdin);
                gets(nombrearchivo);
				archtext(vect,vect_index,k,nombrearchivo);
				break;
            case 8:
                empaquetar(k);
                break;
		}
    }while (op != 0);
    system("PAUSE");
}

talum agregar(talum vect[],int n)
{
    talum reg;
	char nombres_hom[20][20]={"Raymundo", "Jacob", "Josue", "Abraham", "Daniel", "Alexis", "Marcelo", "Roberto", "Ellan", "Francisco"};
	char nombres_muj[20][20]={"Nancy", "Samantha", "Thanya", "Brianda", "Zharina", "Patricia", "Claudia", "Alexa", "Cossete", "Vanessa"};
	char appat[20][20]={"Acosta", "Callejas", "Arista", "Perez", "Guerrero", "Evans", "Loyo", "Urbalejo", "Peralta", "Garcia"};
	char apmat[20][20]={"Hernandez", "Ortiz", "Carrera", "Paniagua", "Beristain", "Marquez", "Quintero", "Cobiza", "Siqueiros", "Navarro"};
    int sexo,status=1,i;
	long ri3=300000, rf3=399999, rango3,matri;
	strcpy(reg.appat,appat[rand()%12]);
	strcpy(reg.apmat,apmat[rand()%12]);
	sexo=(rand()%2)+1;
	if (sexo==1)
	{
	   	strcpy(reg.sexo,"HOMBRE");
	   	strcpy(reg.nombre,nombres_hom[rand()%11]);
	}
	else
	{
	   	strcpy(reg.sexo,"MUJER");
		strcpy(reg.nombre,nombres_muj[rand()%11]);
	}
	reg.edad=(rand()%10)+12;
    rango3 = ( rf3 - ri3 ) + 1;
    do{
        matri = (rand()%rango3) + ri3;
    }while(validar_matri(matri,vect,n) != -1);
    reg.matricula = matri; 
    reg.status=status;
    FILE *arch;
    arch = fopen("registros.dat","a+b");
    if(arch)
    {
        fwrite(&reg,sizeof(talum),1,arch);
        fclose(arch);
    }
     printf("Agregado correctamente \n");
	return reg;
}


int validar_matri(int matri, talum vector[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        if (vector[i].matricula == matri) 
        {
            return i;
        }
    }
    return -1;
}

void prntbin(talum vect[],int n)
{
    system("CLS");
    int i;
    talum reg;
    FILE *arch;
    arch = fopen("registros.dat","r+b");
    if(arch)
    {
        i = n;
        while(fread(&reg,sizeof(talum),1,arch))
        {
            printf("    %6d    %10s    %12s    %12s     %6d    %10s  %d \n",reg.matricula,reg.nombre,reg.appat,reg.apmat,reg.edad,reg.sexo,reg.status);
        }
        fclose(arch);
    }
    system("PAUSE");
}

void cargarind(tindex vect[],int n)
{
    int i, index;
    long matricula;
    talum temp;
    tindex reg;
    FILE *arch;
    arch = fopen("registros.dat","r+b");
    if(arch)
    {
        i = n;
        while(fread(&temp,sizeof(talum),1,arch))
        {
            reg.matricula = temp.matricula;
            reg.indice = i;
            vect[i] = reg;
            i++; 
        }
        fclose(arch);
    }
}

void eliminar(tindex vect[], int n)
{
	system("CLS");
	int mati,i,j,com=0,op;
    int indicebuscado;
    long desplazamiento;
	mati=valinum(300000,399999,"Ingrese la Matricula que desea eliminar:");
	for(i=0; i<=n; i++)
	{
		
		if (vect[i].matricula==mati)
		{
			printf("Matricula %ld encontrada en el indice %d \n",vect[i].matricula,vect[i].indice);
			com=1;
            FILE *arch;
            arch = fopen("registros.dat","r+b");
            if(arch)
            {
                indicebuscado = vect[i].indice;
                desplazamiento = (long)(sizeof(talum)) * (long)(indicebuscado);
                fseek(arch, desplazamiento, SEEK_SET);
                talum reg;
                fread(&reg, sizeof(talum), 1, arch);
                printf("\n");
                printf("    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO \n");
                printf("   %6ld        %8s    %14s       %14s        %5d       %7s      \n",reg.matricula,reg.nombre,reg.appat,reg.apmat,reg.edad,reg.sexo);	
                com=1;
                printf("Seguro que desea eliminar la matricula? \n");
                op=valinum(1,2,"1.-Si \n 2.-No \n");
                if(op == 1)
                {
                    reg.status = 0;
                    fseek(arch, desplazamiento, SEEK_SET);
                    fwrite(&reg, sizeof(talum), 1, arch);
                    printf("\n Matricula eliminada correctamente \n");
                }
                fseek(arch, desplazamiento, SEEK_END);
                fclose(arch); 
            }           
        }    
    }
    if (com==0)
    {
        printf("..\n");
    }
	system("PAUSE");
}

void buscar(tindex vect[], int n)
{
	system("CLS");
	int mati,i,j,com=0;
    int indicebuscado;
    long desplazamiento;
	mati=valinum(300000,399999,"Ingrese la Matricula que desea buscar: \n");
	for(i=0; i<=n; i++)
	{
		
		if (vect[i].matricula==mati)
		{
			printf("Matricula %ld encontrada en el indice %d \n",vect[i].matricula,vect[i].indice);	
			com=1;
            FILE *arch;
            arch = fopen("registros.dat","r+b");
            if(arch)
            {
                indicebuscado = vect[i].indice;
                desplazamiento = (long)(sizeof(talum)) * (long)(indicebuscado);
                fseek(arch, desplazamiento, SEEK_SET);
                talum reg;
                fread(&reg, sizeof(talum), 1, arch);
                printf("\n");
                printf("    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO  STATUS\n");
                printf("   %6ld        %8s    %14s       %14s        %5d       %7s     [%d] \n",reg.matricula,reg.nombre,reg.appat,reg.apmat,reg.edad,reg.sexo,reg.status);	
                com=1;
                fseek(arch, desplazamiento, SEEK_END);
                fclose(arch);    
            }           
        }    
    }
    if (com==0)
    {
        printf("Matricula no encontrada \n");
    }
	system("PAUSE");
}

int leebinario(talum vect[],int n)
{
    int i;
    talum reg;
    FILE *arch;
    arch = fopen("registros.dat","r+b");
    if(arch)
    {
        i = n;
        while(fread(&reg,sizeof(talum),1,arch))
        {
            vect[i] = reg;
            i++;
            if(i == n)
            {
                return i;
            }
        }
        fclose(arch);
    }
    return i;
}

void ordenar(tindex vect[], int n) 
{
    int i, j;
    tindex burb;
    if (vect[i].matricula > vect[i+1].matricula) 
    {
        quicksort(vect,0,n);
    }
    else
    {
        burbuja(vect,n);
    }
    printf("Vector ordenado correctamente \n");
    system("PAUSE");
}

void burbuja(tindex vect[], int n) 
{
    int i, j;
    tindex burb;
    for (i = 0; i<n; i++) 
    {
        for (j = i+1; j<n; j++) 
        {
            if (vect[i].matricula > vect[j].matricula) 
            {
                burb = vect[i];
                vect[i] = vect[j];
                vect[j] = burb;
            }
        }
    }
}

void quicksort(tindex vect[], int primero, int ultimo) 
{
    int i,j, pivote_n;
    tindex pivote,temp;
    if (primero < ultimo) 
    {
        pivote = vect[ultimo];
        i = primero - 1;

        for (j = primero; j <= ultimo-1; j++) 
        {
            if (vect[j].matricula < pivote.matricula) 
            {
                i++;
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
        temp = vect[i+1];
        vect[i+1] = vect[ultimo];
        vect[ultimo] = temp;
        pivote_n = i + 1;
        quicksort(vect, primero, pivote_n - 1);
        quicksort(vect, pivote_n + 1, ultimo);
    }
}

void imprimir_ord(tindex vect[], int n)
{
	system("CLS");
	int mati,i,j;
    long desplazamiento;
    int indicebuscado;
    FILE *arch;
    arch = fopen("registros.dat","rb");
    if(arch)
    {
        printf("    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO  STATUS\n");
        printf("\n");
        for(i=0;i<n;i++)
        {
            indicebuscado = vect[i].indice;
            desplazamiento = (long)(sizeof(talum)) * (long)(indicebuscado);
            fseek(arch, desplazamiento, SEEK_SET);
            talum reg;
            fread(&reg, sizeof(talum), 1, arch);    
            printf("   %6ld        %8s    %14s       %14s        %5d       %7s     [%d] \n",reg.matricula,reg.nombre,reg.appat,reg.apmat,reg.edad,reg.sexo,reg.status);	
        }
        fseek(arch, desplazamiento, SEEK_END);
        fclose(arch);   
    }     
    system("PAUSE");      
}

void archtext(talum vect[],tindex vect_index[],int n,char nombrearchivo[])
{
    int i,op;
    long desplazamiento;
    int indicebuscado;
    char nombre_arch[24];
    strcpy(nombre_arch,nombrearchivo);
    strcat(nombre_arch,".txt");
    printf("Desea imprimir el archivo ordenado? \n");
    op=valinum(1,2,"1.-Si \n 2.- No \n");
    FILE *arch;
    arch = fopen(nombre_arch,"w");
    FILE *arch_bin;
    arch_bin = fopen("registros.dat","rb");
    if(arch)
    {
        talum reg;
        fprintf(arch,"  No.  MATRICULA   NOMBRE        APELLIDO P.      APELLIDO MAT.     EDAD    SEXO       \n");
        if(op == 1)
        {
            for(i=0;i<n;i++)
            {
                indicebuscado = vect_index[i].indice;
                desplazamiento = (long)(sizeof(talum)) * (long)(indicebuscado);
                fseek(arch_bin, desplazamiento, SEEK_SET);
                fread(&reg, sizeof(talum), 1, arch_bin);    
                fprintf(arch,"%d      %6ld     %10s    %12s      %12s      %6d   %10s \n",i,reg.matricula,reg.nombre,reg.appat,reg.apmat,reg.edad,reg.sexo);
            }    
        }
        else
        {
            i = 0;
            while(fread(&reg,sizeof(talum),1,arch_bin))
            {
                fprintf(arch,"%d      %6ld     %10s    %12s      %12s      %6d   %10s \n",i,reg.matricula,reg.nombre,reg.appat,reg.apmat,reg.edad,reg.sexo);
                i++;
            }
            fclose(arch);
        }
        fseek(arch_bin, desplazamiento, SEEK_END);
        fclose(arch);   
    }
}

void generarbin(void)
{
    int i;
    talum reg;
    FILE *arch;
    arch = fopen("registros1.dat","r+b");
    FILE *copia_arch;
    copia_arch = fopen("registros.dat","w+b");
    if(arch)
    {
        while(fread(&reg,sizeof(talum),1,arch))
        {
            fwrite(&reg,sizeof(talum),1,copia_arch);
        }
        fclose(arch);
        fclose(copia_arch);
    }
}

void empaquetar(int n)
{
    int i;
    talum reg;
    FILE *arch;
    arch = fopen("registros.dat1","wb");
    FILE *copia_arch;
    copia_arch = fopen("registros.dat","r+b");
    if(arch)
    {
        for(i=0;i<n;i++)
        {    
            fread(&reg,sizeof(talum),1,copia_arch);
            fwrite(&reg,sizeof(talum),1,arch);
        }
        fclose(arch);
        fclose(copia_arch);
    }
}

