#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define N 10


void msges();
void menu();
int vali_num(int ri,int rf,char msge[]);
void llenavectmanual(int vector1[],int ri,int rf);
void llenavectrandom(int vector2[],int ri,int rf);
void imprimirvect(int vector1[],int vector2[]);
void llenamatriz(int matriz[][4],int m,int vector1[],int vector2[]);
void imprimirmatriz(int matriz[][4],int m);

main()
{
    menu();
    return 0;
}

void msges()
{
	system("CLS");
	printf ("   M  E   N   U \n");
	printf("1.-Llenar vector 1(Manualmente) \n");
	printf("2.-Llenar vector 2(Aleatoriamente) \n");
	printf("3.-Imprimir vectores \n");
	printf("4.-Llenar Matriz 4 X 4 \n");
    printf("5.-Imprimir Matriz \n");
	printf("0.-Salir \n");

}
void menu()
{
	int op,i;
    int vector1[N],vector2[N];
    int m=4,matriz[4][4];
    char msge[30]={"escoge una opcion"};

	do{
		msges();
        op = vali_num(0,5,msge);
		switch(op)
		{
			case 1:
				llenavectmanual(vector1,10,70);
				break;
			case 2:
				llenavectrandom(vector2,1,20);
				break;
			case 3:
				imprimirvect(vector1,vector2);
				break;
            case 4:
                llenamatriz(matriz,m,vector1,vector2);
                break;
            case 5:
                imprimirmatriz(matriz,m);
                break;
		}
	}while(op != 0);
}

int vali_num(int ri,int rf,char msge[])
{
    char xnum[30];
    int num;
    do{
        printf("%s:",msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if (num < ri || num > rf)
        {
            printf("QUE ESTE DENTRO DEL RANGO(%d a %d) \n",ri,rf);
            system("PAUSE");
        }
    }while(num < ri || num > rf);
    return num;
}

void llenavectmanual(int vector1[],int ri,int rf)
{
    system("CLS");
    char msge[50]={"Ingresa un numero(entre 10 y 70)"};
    int i,num;
    i = 0;
    printf("VECTOR 1: \n");
    while(i<N)
    {
        printf("Valor %d: ",i);
        num = vali_num(ri,rf,msge);
        vector1[i]=num;
        i++;
    }
    system("PAUSE");
}

void llenavectrandom(int vector2[],int ri,int rf)
{
    int i,j,num,rango;
    bool band;
    rango = (rf-ri)+1;
    if(rango>=N)
    {
        for(i=0;i<N;i++)
        {
            do{
                num = (rand()%rango)+ri;
                j = 0;
                band = false;
                while(j<i && band == false)
                {
                    if(num == vector2[j])
                    {
                        band = true;
                    }
                    j++;
                }
            }while(band==true);
            vector2[i] = num;
        }
    }

}

void imprimirvect(int vector1[], int vector2[])
{
    int i;
    system("CLS");
    printf("VECTOR 1: \n");
    for(i=0;i<N;i++)
    {
        printf("Vector 1[%d]:%d \n",i,vector1[i]);
    }
    printf("VECTOR 2: \n");
    for(i=0;i<N;i++)
    {
        printf("Vector 2[%d]:%d \n",i,vector2[i]);
    }
    system("PAUSE");
}

void llenamatriz(int matriz[][4],int m,int vector1[],int vector2[])
{
    int i,j;
    int k=0,l=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(k<10)
            {
                matriz[i][j]=vector1[k];
                k++;
            }
            else
            {
                matriz[i][j]=vector2[l];
                l++;
            }
        }
    }
}

void imprimirmatriz(int matriz[][4],int m)
{
    int i,j;
    system("CLS");
    printf("MATRIZ: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("[%3d]",matriz[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}