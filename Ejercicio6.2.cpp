#include<stdio.h>
#include<stdlib.h>

int msges();
void menu();
void calif(void);
void multi(void);
void rango(void);
void peso(void);
void reprobado(void);

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
    printf("1.- CALIFICACIONES \n");
    printf("2.- MULTIPLICACIONES \n");
    printf("3.- RANGO \n");
    printf("4.- PESO \n");
    printf("5.- REPROBADOS \n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf ("%d",&op);
    return op;
}

int validnum()
{
    int num;
    char xnum[30];
    fflush(stdin);
    gets(xnum);
    num = atoi(xnum);
    return num;
}
void menu()
{
    int op;
    do{
      op=msges();
      switch (op)
      {
        case 1:
            calif();
            break;
        case 2:
            multi();
            break;
        case 3:
            rango();
            break;
        case 4:
            peso();
            break;
        case 5:
            reprobado();
            break;
      }

    }while(op != 0);
}

void calif()
{
    int calf,suma,prom,i,j,reprobados;
    reprobados = 0;
    system("CLS");
    printf("CALIFICACIONES: \n");
    for(i=0;i<40;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("Escribe la calificacion %d del alumno %d: \n",j+1,i+1);
            scanf("%d",&calf);
            suma = suma + calf;
        }
        prom = suma / j;
        printf("El promedio del alumno %d es: %d \n",i+1,prom);
        if (prom < 50)
        {
            printf("El alumno %d no tiene derecho a examen de nivelacion \n",i+1);
            reprobados++;
        }
        else
        {
            printf("El alumno  %d esta aprobado \n",i+1);
        }
        suma = 0;
        prom = 0;
    }
    printf("La cantidad de alumnos que no tienen derecho a examen de nivelacion es: %d \n",reprobados);
    system("PAUSE");
}

void multi()
{
    int mult,op,i,n;
    n = 1;
    system("CLS");
    printf("MULTIPLICACIONES: \n");
    
    do{
        printf("Tabla del %d: \n",n);
        for(i=0;i<10;i++)
        {
            mult = n*(i+1);
            printf("%d x %d = %d \n",n,i+1,mult);
        }
        n++;
        printf("CONTINUAR: \n 1.-Si \n 2.-No \n");
        scanf("%d",&op);
        if(n == 11)
        {
            op=2;
            system("PAUSE");
        }
        system("CLS");
    }while(op != 2);
    system("PAUSE");
}

void rango()
{
    int ri,rf,num,rango,media,suma,i,n;
    i = 0;
    suma = 0;
    system("CLS");
    printf("RANGO: \n");
    printf("Ingresa el rango inicial: ");
    scanf("%d",&ri);
    printf("Ingresa el rango final: ");
    scanf("%d",&rf);
    printf("Cantidad de numeros a leer: ");
    scanf("%d",&n);
    while(i<n)
    {
        printf("Ingresa el numero %d: ",i+1);
        scanf("%d",&num);
        if(num >= ri & num <= rf)
        {
            suma = suma + num;
            i++;
        }
        num = 0;
    }
    printf("La suma de los numeros es: %d \n",suma);
    printf("La media de los numeros es: %d \n",suma/i);
    system("PAUSE");
}

void peso()
{
    int pesototal,pesopasaj,i;
    system("CLS");
    printf("PESO DE PASAJEROS: \n");
    pesototal = 0;
    bool band=true;
    i=1;
    while(band==true)
    {
        printf("Pasajero %d, ingrese su peso(en kg): ",i);
        scanf("%d",&pesopasaj);
        pesototal = pesototal + pesopasaj;
        if(pesototal >= 700)
        {
            band = false;
            printf("SE ALCANZO EL PESO MAXIMO (700 kg) \n");
        }
        if(i == 10)
        {
            band = false;
            printf("NUMERO DE PASAJEROS MAXIMO ALCANZADO (10 pasajeros) \n");
        }
        i++;
    }
    printf("El peso total de los pasajeros fue: %d kg \n",pesototal);
    printf("El promedio del peso de los turistas es: %d kg \n",pesototal/(i-1));
    system("PAUSE");
}

void reprobado()
{
    int calf,prom,sumacal,i,j;
    i = 1;
    sumacal = 0;
    system("CLS");
    printf("REPROBADOS: \n");
    bool band=true;
    while(band == true)
    {
        for(j=0;j<3;j++)
        {
            printf("INTENTO %d  \n",i);
            printf("Ingresa la calificacion del parcial %d: ",j+1);
            scanf("%d",&calf);
            sumacal= sumacal + calf;
        }
        prom = sumacal / j;
        printf("El promedio es: %d \n",prom);
        if(prom >= 60)
        {
            i++;
            printf("APROBADO, FELICIDADES \n");
            band = false;
        }
        else
        {
            sumacal = 0;
            printf("REPROBADO, REPITE LA MATERIA \n");
            system("PAUSE");
            system("CLS");
            i++;
        }
        if(i > 3)
        {
            band = false;
            printf("BAJA ACADEMICA \n");
        }
    }
    system("PAUSE");
}