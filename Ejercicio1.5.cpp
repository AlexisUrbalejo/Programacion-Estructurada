#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define N 10
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Aleatorios (void);
void MenorYMayor (void);
void Tabla (void);
//****  main principal  *********
int main()
{
   menu();

	return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- aeatorios \n");
  printf("2.- Menor Y mayor\n");
  printf("3.- Tabla \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}
//****************
void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
              Aleatorios();
              break;
        case 2:
              MenorYMayor();
              break;
        case 3:
              Tabla();
              break;

      }

    }while (op != 0);


}

//*********************
void Aleatorios (void)
{
    //  VARIALES LOCALES 
     int num, i,par=0,impar=0,sumpar=0,sumimpar=0;
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    srand(time(NULL));
    for(i=0;i<40;i++)
    {
        num=(rand()%201);
        
        printf("%d ",num);
        if ((num%2)==0 )
        {
            printf("PAR \n");
            par++;
            sumpar = sumpar + num;
        }
        else
        {
            printf("IMPAR \n");
            impar++;
            sumimpar = sumimpar + num;
        }
    }
    printf("El numero de pares es de: %d \n",par);
    printf("El numero de impares es de: %d \n",impar);
    printf("La suma des los pares es de: %d \n",sumpar);
    printf("La suma de los impares es de: %d \n",sumimpar);
    
    system ("PAUSE");
}

//*************************
void MenorYMayor (void)
{

    //  VARIALES LOCALES 
    int num,i,mayor,menor;
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    srand(time(NULL));
    for(i=0;i<35;i++)
    {
      num=(rand()%101)+100;
      printf("%d \n",num);
      if(num > mayor)
      {
        mayor = num;
      }
      if (num < menor)
      {
        menor = num;
      }


    }
    printf("El mayor es el numero: %d \n",mayor);
    printf("El mayor es el numero: %d \n",menor);
    system ("PAUSE");
}
//****************************
void Tabla (void)
{
    //  VARIALES LOCALES 
    int i,tabla, num;
    system ("CLS");

    //  AQUI DESARROLLO PROGRAMA
    printf("Ingresa el numero de la tabla que deseas realizar: ");
    scanf("%d",&num);
    for(i=0;i<=10;i++)
    {
      tabla = i*num;
       printf("%d x %d = %d\n",i,num,tabla);

    }
    system ("PAUSE");

}