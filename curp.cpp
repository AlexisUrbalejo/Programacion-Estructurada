
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "alexis.h"
bool band=true;
void menu();
void datos();
void gencurp(char appat[], char apmat[],char nombre[],char gen,char msge[],int dia,int mes,int anio, int estado);
void excepciones(char curp[],char appat[], char apmat[],char nombre[],char gen);
void malpal (char curp[]);

int main()
{   
    menu();

return 0;
}

void menu()
{
  int op;
  do{
        system("CLS");
        printf("- SISTEMA PARA OBTENER TU CURP - \n");
        printf("1.- Generar CURP \n");
        printf("2.- Salir \n");
        op=valinum(1,2,"Que deseas hacer? "); 
        if (op==1)
        {
            system("CLS");
            datos();
        }      
        system ("PAUSE");
      
    }while (op != 2);
}

void datos()
{   int dia,mes,anio,estado;
    char appat[20],apmat[20],nombre[20],gen,msge[30];
    system ("CLS");
    while(1)
    { 
        printf("INGRESA TU GENERO (H PARA HOMBRE ---- M PARA MUJER) \n");
        scanf(" %c",&gen);
        if((gen=='H'||gen=='h' || gen=='M'||gen=='m'))
        {
            break;
        }
        printf("ERROR: Caracter no valido, intente de nuevo \n");
    }
    do{
        printf("INGRESA TU APELLIDO PATERNO (PONER X SI NO TIENES APELLIDO PATERNO): \n");
        fflush(stdin);
	    gets(appat);

        if(Valicad(appat)==1)
        {
            printf("ERROR: caracter invalido \n");
            system("PAUSE");
        }
    }while(Valicad(appat)==1);

    do{
        printf("INGREA TU APELLIDO MATERNO (PONER X SI NO TIENES APELLIDO MATERNO\n");
        fflush(stdin);
	    gets(apmat);

        if(Valicad(apmat)==1)
        {
            printf("ERROR: Caracter invalido \n");
            system("PAUSE");
        }
    }while(Valicad(apmat)==1);

    do{
        printf("INGRESA TU NOMBRE(S)  \n");
        fflush(stdin);
	    gets(nombre);

        if(Valicad(nombre)==1)
        {
            printf("ERROR: Caracter invalido \n");
            system("PAUSE");
        }
    }while(Valicad(nombre)==1);


    anio=valinum(1923,2023,"INGRESA EL ANIO EN QUE NACISTE \n");
    mes=valinum(1,12,"Ingresa tu mes de nacimiento (M): ");
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12 )
    {
        dia=valinum(1,31,"INGREAS TU DIA DE NACIMIENTO(D): \n");
    }
    else if(mes==2)
    {
        if((anio%4 == 0 && anio%100 != 0) || anio%400 == 0)
        {
            dia=valinum(1,29,"INGRESA TU DIA DE NACIMIENTO (D): \n");
        }
        else
        {
            dia=valinum(1,28,"INGRESA TU DIA DE NACIMIENTO(D): \n");
        }
    }
    else
    {
        dia=valinum(1,30,"INGRESA TU DIA DE NACIMIENTO(D): \n");
    }

    Estados();
    estado=valinum(1,33,"INGRESA EL NUMERO CORRESPONDIENTE A TU ESTADO: \n");

    gencurp(appat,apmat,nombre,gen,msge,dia,mes,anio,estado);
}


void gencurp(char appat[], char apmat[],char nombre[],char gen,char msge[],int dia,int mes,int anio,int estado)
{   
    char curp[19]; 
    srand(time(NULL));
    curp[0]=appat[0];

    curp[1]=Vocales(appat,1);
    curp[2]=apmat[0];
    curp[3]=nombre[0];
    curp[4]=((anio/10)%10)+48;
    curp[5]=(anio%10)+48;

    if(appat=="X" || appat=="x")
    {
        curp[0]='X';
        curp[13]='X';
    }
    if(apmat=="X" || apmat=="x")
    {
        curp[2]='X';
        curp[14]='X';
    }

    if(mes<10)
    {
        curp[6]=48;
        curp[7]=mes+48;
    }
    else
    {
        curp[6]=49;
        curp[7]=(mes%10)+48;
    }

    if(dia<10)
    {
        curp[8]=48;
        curp[9]=dia+48;
    }
    else
    {
        if(dia>=30)
        {
            curp[8]=51;
            curp[9]=(dia%10)+48;
        }
        else
        {
            if(dia>=20)
            {
                curp[8]=50;
                curp[9]=(dia%10)+48;
            }
            else
            {
                if(dia>=10)
                {
                    curp[8]=49;
                    curp[9]=(dia%10)+48;
                }
            }
        }
    }
    curp[10]=gen;
    
    switch (estado)
      {
        case 1:
            //Aguascalientes AS
            curp[11]=65;
            curp[12]=83;
              break;
        case 2:
            //Baja California BC
            curp[11]=66;
            curp[12]=67;
              break;
        case 3:
            //Baja California Sur BS
            curp[11]=66;
            curp[12]=83;
              break;
        case 4:
            //Campeche CC
            curp[11]=67;
            curp[12]=67;
              break;
        case 5: 
            //Coahuila CL
            curp[11]=67;
            curp[12]=76;
              break;
        case 6: 
            //Colima CM
            curp[11]=67;
            curp[12]=77;
             break;
        case 7:
            //Chiapas CS
            curp[11]=67;
            curp[12]=83;
              break;
        case 8:
            //Chihuahua CH
            curp[11]=67;
            curp[12]=72;
              break;
        case 9:
            //Distrito Federal DF
            curp[11]=68;
            curp[12]=70;
              break;
        case 10:
            //Durango DG
            curp[11]=68;
            curp[12]=71;
              break;
        case 11: 
            //Guanajuato GT
            curp[11]=71;
            curp[12]=84;
              break;
        case 12:
            //Guerrero GR
            curp[11]=71;
            curp[12]=82;
             break;
        case 13:
            //Hidalgo HG
            curp[11]=72;
            curp[12]=71;
              break;
        case 14:
            //Jalisco JC
            curp[11]=74;
            curp[12]=67;
              break;
        case 15:
            //Mexico MC
            curp[11]=77;
            curp[12]=67;
              break;
        case 16:
            //Michoacan MN
            curp[11]=77;
            curp[12]=78;
              break;
        case 17: 
            //Morelos MS
            curp[11]=77;
            curp[12]=83;
              break;
        case 18:
            //Nayarit NT
            curp[11]=78;
            curp[12]=84;
             break;
        case 19:
            //Nuevo Leon NL
            curp[11]=78;
            curp[12]=76;
              break;
        case 20:
            //Oaxaca OC
            curp[11]=79;
            curp[12]=67;
              break;
        case 21:
            //Puebla PL
            curp[11]=80;
            curp[12]=76;
              break;
        case 22:
            //Queretaro QT
            curp[11]=81;
            curp[12]=84;
              break;
        case 23: 
            //Quintana Roo QR
            curp[11]=81;
            curp[12]=82;
              break;
        case 24:
            //San Luis Potosi SP
            curp[11]=83;
            curp[12]=80;
             break;
        case 25:
            //Sinaloa SL
            curp[11]=83;
            curp[12]=76;
              break;
        case 26:
            //Sonora SR
            curp[11]=83;
            curp[12]=82;
              break;
        case 27:
            //Tabasco TC
            curp[11]=84;
            curp[12]=67;
              break;
        case 28:
            //Tamaulipas TS
            curp[11]=84;
            curp[12]=83;
              break;
        case 29: 
            //Tlaxcala TL
            curp[11]=84;
            curp[12]=76;
              break;
        case 30:
            //Veracruz VZ
            curp[11]=86;
            curp[12]=90;
             break;
        case 31:
            //Yucatan YN
            curp[11]=89;
            curp[12]=78;
              break;
        case 32: 
            //Zacatecas ZS
            curp[11]=90;
            curp[12]=83;
              break;
        case 33:
            //Extranjero NE
            curp[11]=78;
            curp[12]=69;
             break;
      }

    curp[13]=Consonantes(appat,1);
    curp[14]=Consonantes(apmat,1);
    curp[15]=Consonantes(nombre,1);

    if (anio<=1999)
    {
        curp[16]='0';
    }
    
    if (anio>=2000)
    {
        curp[16]='A';
    }

    curp[17]=rand()%10 + '0';

    excepciones(curp,appat,apmat,nombre,gen);
    malpal(curp);
    Mayus(curp);

    printf("SU CURP ES: %s \n",curp);
}

void excepciones(char curp[],char appat[], char apmat[],char nombre[],char gen)
{
    //Ñ

    int i;
        for(i=0;i<strlen(curp);i++)
        {
            if(curp[i] == -91 || curp[i] == -92)
            {
                curp[i] = 'X';
            }
        }
  
    //MARIA || JOSE
    if(strlen(nombre)>6) //maria
    {
        char temp[7];
        memset(temp,'\0',7);
        strncpy(temp,nombre,6);
        if(strcmpi(temp,"maria ")==0)
        {
            curp[3]=nombre[6];
            curp[15]=Consonantes(nombre,6);
        }

    }

    if(strlen(nombre)>4) //ma.
    {
        char temp[5];
        memset(temp,'\0',5);
        strncpy(temp,nombre,4);
        if(strcmpi(temp,"ma. ")==0)
        {
            curp[3]=nombre[4];
            curp[15]=Consonantes(nombre,4);
        }

    }

    if(strlen(nombre)>3) //ma
    {
        char temp[4];
        memset(temp,'\0',4);
        strncpy(temp,nombre,3);
        if(strcmpi(temp,"ma ")==0)
        {
            curp[3]=nombre[3];
            curp[15]=Consonantes(nombre,3);
        }

    }

    if(strlen(nombre)>5) //Jose
    {
        char temp[6];
        memset(temp,'\0',6);
        strncpy(temp,nombre,5);
        if(strcmpi(temp,"jose ")==0)
        {
            curp[3]=nombre[5];
            curp[15]=Consonantes(nombre,5);
        }

    }

    if(strlen(nombre)>3) //J.
    {
        char temp[4];
        memset(temp,'\0',4);
        strncpy(temp,nombre,3);
        if(strcmpi(temp,"j. ")==0)
        {
            curp[3]=nombre[3];
            curp[15]=Consonantes(nombre,3);
        }

    }

    if(strlen(nombre)>2) //J
    {
        char temp[3];
        memset(temp,'\0',3);
        strncpy(temp,nombre,2);
        if(strcmpi(temp,"j ")==0)
        {
            curp[3]=nombre[2];
            curp[15]=Consonantes(nombre,2);
        }

        //caracteres especiales

        if(nombre[0]=='/' || nombre[0]=='-' || nombre[0]=='.')
        {
            curp[3]='X';
        }

        if(appat[0]=='/' || appat[0]=='-' || appat[0]=='.')
        {
            curp[0]='X';
        }

        if(apmat[0]=='/' || apmat[0]=='-' || apmat[0]=='.')
        {
            curp[2]='X';
        }

        //dieresis
        if(nombre[0]==142 || nombre[0]==132)
        {
            curp[3]='A';
        }

        if(nombre[0]==69 || nombre[0]==137)
        {
            curp[3]='E';
        }

        if(nombre[0]==73 || nombre[0]==139)
        {
            curp[3]='I';
        }

        if(nombre[0]==153 || nombre[0]==148)
        {
            curp[3]='O';
        }

        if(nombre[0]==154 || nombre[0]==129)
        {
            curp[3]='U';
        }

        if(appat[0]==142 || appat[0]==132)
        {
            curp[0]='A';
        }

        if(appat[0]==69 || appat[0]==137)
        {
            curp[0]='E';
        }

        if(appat[0]==73 || appat[0]==139)
        {
            curp[0]='I';
        }

        if(appat[0]==153 || appat[0]==148)
        {
            curp[0]='O';
        }

        if(appat[0]==154 || appat[0]==129)
        {
            curp[0]='U';
        }

        if(apmat[0]==142 || apmat[0]==132)
        {
            curp[2]='A';
        }

        if(apmat[0]==69 || apmat[0]==137)
        {
            curp[2]='E';
        }

        if(apmat[0]==73 || apmat[0]==139)
        {
            curp[2]='I';
        }

        if(apmat[0]==153 || apmat[0]==148)
        {
            curp[2]='O';
        }

        if(apmat[0]==154 || apmat[0]==129)
        {
            curp[2]='U';
        }

        if(curp[1]==142 || curp[1]==132)
        {
            curp[1]='A';
        }

        if(curp[1]==69 || curp[1]==137)
        {
            curp[1]='E';
        }

        if(curp[1]==73 || curp[1]==139)
        {
            curp[1]='I';
        }

        if(curp[1]==153 || curp[1]==148)
        {
            curp[1]='O';
        }

        if(curp[1]==154 || curp[1]==129)
        {
            curp[1]='U';
        }
    }

    //apellidos||nombres compuestos
    if(strlen(nombre)>4) 
    {
        char temp[5];
        memset(temp,'\0',5);
        strncpy(temp,nombre,4);

        if(strcmpi(temp,"das ")==0 || strcmpi(temp,"del ")==0 || strcmpi(temp,"der ")==0 || strcmpi(temp,"die ")==0 || strcmpi(temp,"los ")==0 || strcmpi(temp,"las ")==0 || strcmpi(temp,"les ")==0 || strcmpi(temp,"mac")==0 || strcmpi(temp,"van ")==0 || strcmpi(temp,"von ")==0)
        {
            curp[3]=nombre[4];
            curp[15]=Consonantes(nombre,5);
        }
    }
    if(strlen(nombre)>3) 
    {
        char temp[4];
        memset(temp,'\0',4);
        strncpy(temp,nombre,3);

        if(strcmpi(temp,"da ")==0 || strcmpi(temp,"de ")==0 || strcmpi(temp,"di ")==0 || strcmpi(temp,"dd ")==0 || strcmpi(temp,"el ")==0 || strcmpi(temp,"la ")==0 || strcmpi(temp,"le ")==0 || strcmpi(temp,"mc ")==0)
        {
            curp[3]=nombre[3];
            curp[15]=Consonantes(nombre,4);
        }
    }
    if(strlen(nombre)>2) 
    {
        char temp[3];
        memset(temp,'\0',3);
        strncpy(temp,nombre,2);

        if(strcmpi(temp,"y ")==0)
        {
            curp[3]=nombre[2];
            curp[15]=Consonantes(nombre,3);
        }
    }
     if(strlen(appat)>4) 
    {
        char temp[5];
        memset(temp,'\0',5);
        strncpy(temp,appat,4);

        if(strcmpi(temp,"das ")==0 || strcmpi(temp,"del ")==0 || strcmpi(temp,"der ")==0 || strcmpi(temp,"die ")==0 || strcmpi(temp,"los ")==0 || strcmpi(temp,"las ")==0 || strcmpi(temp,"les ") == 0 || strcmpi(temp,"mac ")==0 || strcmpi(temp,"van ")==0 || strcmpi(temp,"von ")==0)
        {
            curp[0]=appat[4];
            curp[1]=Vocales(appat,5);
            curp[13]=Consonantes(appat,5);
        }
    }
    if(strlen(appat)>3) 
    {
        char temp[4];
        memset(temp,'\0',4);
        strncpy(temp,appat,3);

        if(strcmpi(temp,"da ")==0 || strcmpi(temp,"de ")==0 || strcmpi(temp,"di ")==0 || strcmpi(temp,"dd ")==0 || strcmpi(temp,"el ")==0 || strcmpi(temp,"la ")==0 || strcmpi(temp,"le ")==0 || strcmpi(temp,"mc ")==0)
        {
            curp[0]=appat[3];
            curp[1]=Vocales(appat,4);
            curp[13]=Consonantes(appat,4);
        }
    }
    if(strlen(appat)>2) 
    {
        char temp[3];
        memset(temp,'\0',3);
        strncpy(temp,appat,2);

        if(strcmpi(temp,"y ")==0)
        {
            curp[0]=appat[2];
            curp[1]=Vocales(appat,3);
            curp[13]=Consonantes(appat,3);
        }
    }
     if(strlen(apmat)>4) 
    {
        char temp[5];
        memset(temp,'\0',5);
        strncpy(temp,apmat,4);

        if(strcmpi(temp,"das ")==0 || strcmpi(temp,"del ")==0 || strcmpi(temp,"der ")==0 || strcmpi(temp,"die ")==0 || strcmpi(temp,"los ")==0 || strcmpi(temp,"las ")==0 || strcmpi(temp,"les ")==0 || strcmpi(temp,"mac ")==0 || strcmpi(temp,"van ")==0 || strcmpi(temp,"von ")==0)
        {
            curp[2]=apmat[4];
            curp[14]=Consonantes(apmat,5);
        }
    }
    if(strlen(apmat)>3) 
    {
        char temp[4];
        memset(temp,'\0',4);
        strncpy(temp,apmat,3);

        if(strcmpi(temp,"da ")==0 || strcmpi(temp,"de ")==0 || strcmpi(temp,"di ")==0 || strcmpi(temp,"dd ")==0 || strcmpi(temp,"el ")==0 || strcmpi(temp,"la ")==0 || strcmpi(temp,"le ")==0 || strcmpi(temp,"mc ")==0)
        {
            curp[2]=apmat[3];
            curp[14]=Consonantes(apmat,4);
        }
    }
    if(strlen(apmat)>2) 
    {
        char temp[3];
        memset(temp,'\0',3);
        strncpy(temp,apmat,2);

        if(strcmpi(temp,"y ")==0)
        {
            curp[2]=apmat[2];
            curp[14]=Consonantes(apmat,3);
        }
    }
}



void malpal (char curp[])
{
    int i,x;
    char temp[5];
    memset(temp,'\0',5); 
    strncpy(temp,curp,4);

    char palinc[81][5]={"BACA","BAKA","BUEI","BUEY","CACA","CACO","CAGA","CAGO",
    "CAKA","CAKO","COGE","COGI","COJA","COJE","COJI","COJO","COLA","CULO","FALO",
    "FETO","GETA","GUEI","GUEY","JETA","JOTO","KACA","KACO","KAGA","KAGO","KAKA","KAKO",
     "KOGE","KOGI","KOJA","KOJE","KOJI","KOJO","KOLA","KULO","LILO","LOCA","LOCO","LOKA",
      "LOKO","MAME","MAMO","MEAR","MEAS","MEON","MIAR","MION","MOCO","MOKO","MULA","MULO",
      "NACA","NACO","PEDA","PEDO","PENE","PIPI","PITO","POPO","PUTA","PUTO","QULO","RATA",
      "ROBA","ROBE","ROBO","RUIN","SENO","TETA","VACA","VAGA","VAGO","VAKA","VUEI","VUEY",
      "WUEI","WUEY"};

    i=0;
    while(i<81)
    {
        x=stricmp(temp,palinc[i]);
        if(x==0)
        {
            curp[1]='X';
        }
        i++;
    }
}