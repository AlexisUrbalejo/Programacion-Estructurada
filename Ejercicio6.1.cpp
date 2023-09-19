#include<stdio.h>
#include<stdlib.h>

int msges();
void menu();
//Prototipos funciones para Fibonacci
void menufibo(void);
void fibofor(void);
void fibowhile(void);
void fibodowhile(void);
//Prototipos funciones para factorial
void menufact(void);
void factfor(void);
void factwhile(void);
void factdowhile(void);
//Prototipos funciones para digitos
void menudigitos(void);
void digitosfor(void);
void digitoswhile(void);
void digitosdowhile(void);
//****  main principal  *********
int main()
{
    menu();
    return 0;
}

int msges()
{
    int op,menu;
    system("CLS");
    printf ("   M  E   N   U \n");
    printf("1.- FIBONACCI \n");
    printf("2.- FACTORIAL \n");
    printf("3.- CANTIDAD DE DIGITOS \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf ("%d",&op);
    return op;
}

void menu()
{
    int op;
    do{
      op=msges();
      switch (op)
      {
        case 1:
            menufibo();
            break;
        case 2:
            menufact();
            break;
        case 3:
            menudigitos();
            break;
    
      }

    }while (op != 0);
}
void menufibo()
{
    int op;
    system("CLS");
    printf("FIBONACCI \nCON QUE CICLO DESEAS QUE SE REALICE: \n");
    printf("1.-For \n2.-While \n3.-Do While \n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            fibofor();
            break;
        case 2:
            fibowhile();
            break;
        case 3:
            fibodowhile();
            break;
    }
    return;
}

void menufact()
{
    int op;
    system("CLS");
    printf("FACTORIAL \nCON QUE CICLO DESEAS QUE SE REALICE: \n");
    printf("1.-For \n2.-While \n3.-Do While \n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            factfor();
            break;
        case 2:
            factwhile();
            break;
        case 3:
            factdowhile();
            break;
    }
    return;
}

void menudigitos()
{
    int op;
    system("CLS");
    printf("DIGITOS \nCON QUE CICLO DESEAS QUE SE REALICE: \n");
    printf("1.-For \n2.-While \n3.-Do While \n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            digitosfor();
            break;
        case 2:
            digitoswhile();
            break;
        case 3:
            digitosdowhile();
            break;
    }
    return;
}

void fibofor(void)
{
    int ant,sig,res,i,n;
    ant = -1;
    sig = 1;
    res = 0;
    system("CLS");
    printf("Ingresa cuantas veces deseas que se realice el programa de fibonacci: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        res=ant+sig;
        printf("%d, ",res);
        ant = sig;
        sig = res;
    }
    printf("\n");
    system("PAUSE");
}

void fibowhile(void)
{
    int ant,sig,res,i,n;
    ant = -1;
    sig = 1;
    res = 0;
    i = 0;
    system("CLS");
    printf("Ingresa cuantas veces deseas que se realice el programa de fibonacci: ");
    scanf("%d",&n);
    while(i<n)
    {
        res=ant+sig;
        printf("%d, ",res);
        ant = sig;
        sig = res;
        i++;
    }
    printf("\n");
    system("PAUSE");
}

void fibodowhile(void)
{
    int ant,sig,res,i,n;
    ant = -1;
    sig = 1;
    res = 0;
    i = 0;
    system("CLS");
    printf("Ingresa cuantas veces deseas que se realice el programa de fibonacci: ");
    scanf("%d",&n);
    do{
        res=ant+sig;
        printf("%d, ",res);
        ant = sig;
        sig = res;
        i++;
    }while(i<n);
    printf("\n");
    system("PAUSE");
}

void factfor(void)
{
    int i,num,ant,sig,result;
    system ("CLS");
    printf("FACTORIAL\n"); 
    printf("Ingresa un numero: ");
    scanf("%d",&num);
    ant = num;
    for(i=0;i<num-2;i++)
    {
    	sig = num-(i+1);
		result = ant * sig;
		printf("%d x %d = %d \n",ant,sig,result);
		ant = result;
	}
    system("PAUSE");
}

void factwhile(void)
{
    int i,num,ant,sig,result;
    i=0;
    system ("CLS");
    printf("FACTORIAL\n"); 
    printf("Ingresa un numero: ");
    scanf("%d",&num);
    ant = num;
    while(i<num-2)
    {
        sig = num-(i+1);
		result = ant * sig;
		printf("%d x %d = %d \n",ant,sig,result);
		ant = result;
        i++;
    }
    system("PAUSE");
}

void factdowhile(void)
{
    int i,num,ant,sig,result;
    i=0;
    system ("CLS");
    printf("FACTORIAL\n"); 
    printf("Ingresa un numero: ");
    scanf("%d",&num);
    ant = num;
    do{
        sig = num-(i+1);
		result = ant * sig;
		printf("%d x %d = %d \n",ant,sig,result);
		ant = result;
        i++;
    }while(i<num-2);
    system("PAUSE");
}

void digitosfor(void)
{
    int num,op,i;
    for(i=0;op != 2;i++)
    {
        system("CLS");
        printf("Escribe el numero para saber su cantidad de digitos: ");
        scanf("%d",&num);
        if(num <= 9)
        {
            printf("El numero %d tiene 1 digito \n",num);
        }
        else
        {
            if(num <= 99)
            {
                printf("El numero %d tiene 2 digitos \n",num);
            }
            else
            {
                if(num <= 999)
                {
                    printf("El numero %d tiene 3 digitos \n",num);
                }
                else
                {
                    if(num <= 9999)
                    {
                        printf("El numero %d tiene 4 digitos \n",num);
                    }
                }
            }
        }
        num = 0;
        printf("Quieres continuar con otro numero: \n1.-Si \n2.-No \n: ");
        scanf("%d",&op);
    }
    printf("\n");
    system("PAUSE");
}

void digitoswhile(void)
{
    int num,op;
    while(op != 2)
    {
        system("CLS");
        printf("Escribe el numero para saber su cantidad de digitos: ");
        scanf("%d",&num);
        if(num <= 9)
        {
            printf("El numero %d tiene 1 digito \n",num);
        }
        else
        {
            if(num <= 99)
            {
                printf("El numero %d tiene 2 digitos \n",num);
            }
            else
            {
                if(num <= 999)
                {
                    printf("El numero %d tiene 3 digitos \n",num);
                }
                else
                {
                    if(num <= 9999)
                    {
                        printf("El numero %d tiene 4 digitos \n",num);
                    }
                }
            }
        }
        num = 0;
        printf("Quieres continuar con otro numero: \n1.-Si \n2.-No \n: ");
        scanf("%d",&op);
    }
    printf("\n");
    system("PAUSE");
}

void digitosdowhile(void)
{
    int num,op;
    do{
        system("CLS");
        printf("Escribe el numero para saber su cantidad de digitos: ");
        scanf("%d",&num);
        if(num <= 9)
        {
            printf("El numero %d tiene 1 digito \n",num);
        }
        else
        {
            if(num <= 99)
            {
                printf("El numero %d tiene 2 digitos \n",num);
            }
            else
            {
                if(num <= 999)
                {
                    printf("El numero %d tiene 3 digitos \n",num);
                }
                else
                {
                    if(num <= 9999)
                    {
                        printf("El numero %d tiene 4 digitos \n",num);
                    }
                }
            }
        }
        num = 0;
        printf("Quieres continuar con otro numero: \n1.-Si \n2.-No \n: ");
        scanf("%d",&op);
    }while(op != 2);
    printf("\n");
    system("PAUSE");
}

