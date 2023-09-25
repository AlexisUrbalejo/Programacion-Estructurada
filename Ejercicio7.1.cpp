//ACTIVIDAD 7 PARTE 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int msges();
void menu();
void salida1(void);
void salida2(void);
void salida3(void);
void salida4(void);
void salida5(void);
void salida6(void);
void salida7(void);
void salida8(void);
void salida9(void);
void salida10(void);

int main()
{
	menu();
	return 0;
	
}


int msges()
{
	int op;
	system("CLS");
	printf ("   M  E   N   U \n");
	printf("1.-Salida 1 \n");
	printf("2.-Salida 2 \n");
	printf("3.-Salida 3 \n");
	printf("4.-Salida 4 \n");
	printf("5.-Salida 5 \n");
	printf("6.-Salida 6 \n");
	printf("7.-Salida 7 \n");
	printf("8.-Salida 8 \n");
	printf("9.-Salida 9 \n");
	printf("10.-Salida 10 \n");
	printf("0.-SALIR DEL CODIGO \n");
	printf("Escoge una opcion: ");
	scanf("%d",&op);
	return op;
}


void menu()
{
	int op;
	do{
		op =msges();
		switch(op)
		{
			case 1:
				salida1();
				break;
			case 2:
				salida2();
				break;
			case 3:
				salida3();
				break;
			case 4:
				salida4();
				break;
			case 5:
				salida5();
			case 6:
				salida6();
				break;
			case 7:
				salida7();
				break;
			case 8:
				salida8();
				break;
			case 9:
				salida9();
				break;
			case 10:
				salida10();
				break;
		}
	}while(op != 0);
}

void salida1(void)//ENSENADA
{
	int i,tam;
	char cadena[30];
	system("CLS");
	printf("Ingresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	strupr(cadena);
	printf("SALIDA 1: \n");
	printf("%s \n",cadena);
	system("PAUSE");

}
void salida2(void)//ADANESNE
{
	char cadena[30];
	system("CLS");
	printf("Ingresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	strupr(cadena);
	strrev(cadena);
	printf("SALIDA 2: \n");
	printf("%s \n",cadena);
	system("PAUSE");
}

void salida3(void)
{
	int i,tam;
	char cadena[30];
	system("CLS");
	printf("Ingresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	strupr(cadena);
	tam = strlen(cadena);
	for(i=0;i<tam;i++)
	tam = strlen(cadena);
	printf("SALIDA 3: \n");
	for(i=0;i<tam;i++)
	{
		printf("%c \n",cadena[i]);
	}
	system("PAUSE");
}

void salida4(void)
{
	int i,tam;
	char cadena[30];
	system("CLS");
	printf("Ingresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	strupr(cadena);
	tam = strlen(cadena);
	strrev(cadena);
	printf("SALIDA 4: \n");
	for(i=0;i<tam;i++)
	{
		printf("%c \n",cadena[i]);
	}
	system("PAUSE");
	
}

void salida5(void)
{
	int i,j,tam;
	char cadena[30];
	system("CLS");
	printf("Ingresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	strupr(cadena);
	tam = strlen(cadena);
	printf("SALIDA 5: \n");
	for(j=0;j<tam;j++)
	{
		for(i=0;i<tam-j;i++)
		{
			printf("%c",cadena[i]);
		}
		printf("\n");
	}
	system("PAUSE");
}

void salida6(void)
{
	int i,j,tam;
	char cadena[30];
	system("CLS");
	printf("Ingresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	strupr(cadena);
	tam = strlen(cadena);
	printf("SALIDA 6: \n");
	for(j=0;j<tam;j++)
	{
		for(i=tam-1;i-j>=0;i--)
		{
			printf("%c",cadena[i]);
		}
		printf("\n");
	}
	system("PAUSE");
}

void salida7(void)
{
	int i,j,tam;
	char cadena[30];
	system("CLS");
	printf("Ingresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	strupr(cadena);
	tam = strlen(cadena);
	printf("SALIDA 7: \n");
	for(j=0;j<tam;j++)
	{
		for(i=0;i<tam-j;i++)
		{
			printf("%c",cadena[i+j]);
		}
		printf("\n");
	}
	system("PAUSE");
}

void salida8(void)
{
	int i,j,tam;
	char cadena[30];
	system("CLS");
	printf("Ingresa una cadena: ");
	fflush(stdin);
	gets(cadena);
	strupr(cadena);
	tam = strlen(cadena);
	printf("SALIDA 8: \n");
	for(j=0;j<tam;j++)
	{
		for(i=tam-1;i-j>=0;i--)
		{
			printf("%c",cadena[i-j]);
		}
		printf("\n");
	}
	system("PAUSE");
}

void salida9(void)
{
	
    char cadena[30], nuevacadena[30];
    int i, j = 0;
	system("CLS");
    printf("Escribe una cadena: ");
    fflush(stdin);
	gets(cadena);
	printf("SALIDA 9: \n");
    for(i = 0; i < strlen(cadena); i++) 
	{
        if(cadena[i] != 'a' && cadena[i] != 'e' && cadena[i] != 'i' && cadena[i] != 'o' && cadena[i] != 'u' && cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U') 
		{
            nuevacadena[j] = cadena[i];
            j++;
        }
    }
    nuevacadena[j] = '\0';

    printf("La cadena sin vocales es: %s\n", nuevacadena);
	printf("\n");
	system("PAUSE");
}

void salida10(void)
{

   char cadena[30];
   int i, j = 0,tam;
   system("CLS");
   printf("Escribe una cadena: ");
   fflush(stdin);
   gets(cadena);
   tam = strlen(cadena);
   printf("SALIDA 10: \n");
   for (i = 0; i < tam; i++) 
   {
		if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
		{
        	printf("%c", cadena[i]);
      	}
   }
   printf("\n");
   system("PAUSE");
}






