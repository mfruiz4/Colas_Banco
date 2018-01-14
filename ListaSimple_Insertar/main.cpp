/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
ESTRUCTURAS DE DATOS
NRC: 2479
MAURICIO RUIZ
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct Nodo{
    int datoEntero;
    Nodo *sig;

} *lista;


void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
  void t(int n){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}
char insertar( )
{
    Nodo *p = new Nodo;
    char x;
    do{
    printf("Ingrese un numero\n");
    scanf("%d",&p->datoEntero);
    }while(p->datoEntero<0);
    p->sig=lista;
    lista=p;

    printf("Desea ingresar otro dato?S/N\n");
    do
    {
        fflush(stdin);
        x=getchar();
    }while((x!='S' && x!='s')&&(x!='n'&&x!='N'));
    system("cls");

    return x;
};

void imprimir(Nodo *c)
{
    Nodo *k;
    k=c;

    do{
        printf("-> %d ",k->datoEntero);
        k=k->sig;
    }while(k!=NULL);
}

void buscarPos(int c, Nodo *s)
{
    Nodo *k;
    int pos;
    int aux=1;
    k=s;
    printf("\nIngrese la posicion que desea buscar: ");
    scanf("%d",&pos);

    if(pos>c)
    {
        printf("La posicion buscada no existe, use otra\n");
        printf("Ingrese la posicion que desea buscar: ");
        scanf("%d",&pos);
    }



    else
    {
    do{
        if(aux==pos)

        {printf("Dato encontrado: %d \n",k->datoEntero);
        k=k->sig;
        aux++;
        }
        else
        {
            k=k->sig;
            aux++;
        }


        }while(k!=NULL);

    }

};

void modificarNum(Nodo *s)
{
    Nodo *k;
    int n,aux,cont=0;
    k=s;


    printf("Ingrese el numero que desea modificar\n");
    scanf("%d",&n);

    do{
        if(n!=k->datoEntero)

        {
        k=k->sig;
        }
        else
        {
            printf("Numero encontrado:%d\n",n);
            printf("Ingrese el numero por el cual se va a modificar: ");
            scanf("%d",&aux);
            k->datoEntero=aux;
            k=k->sig;
            cont++;
        }

        }while(k!=NULL);
        if(cont==0)
        printf("Numero no encontrado en la lista\n");

    };

    void eliminar(int c,Nodo *&lista)
    {

     Nodo *k;
     Nodo *anterior=NULL;
    k=lista;
    printf("eliminando...\n");
    do{
            anterior=k;
            k=k->sig;
    }while(k!=NULL);

       delete anterior;
    };

void guardarFile(Nodo *s)
{
    FILE *fichero;
    Nodo *k;
    k=s;
    fichero=fopen("Registro.txt","a");
    if(fichero!=NULL)
    {
        fputs("\t\tGuardado Exitoso\n",fichero);
        fputs("Lista Actual\n",fichero);
         do{
                fputs("->",fichero);
            fprintf(fichero,"%d ",k->datoEntero);
                k=k->sig;
        }while(k!=NULL);

    fputs("\n------------------------------------------\n",fichero);

    }
    else
        printf("Existe un problema con el archivo, no pudo ser creado\n");

    fclose(fichero);
};

void menu()
{

    char y;
    int cont=0,c=0;
    int tecla, op=1;
    lista = NULL;

do{
    gotoxy(25,0);printf("MENU PRINCIPAL - Seleccione una opcion ");


     do{
  gotoxy(0,5);printf("Insertar Datos");
  gotoxy(20,5);printf("Buscar");
 gotoxy(35,5);printf("Modificar");
  gotoxy(50,5);printf("Eliminar");
  gotoxy(60,5);printf("Imprimir");
  gotoxy(70,5);printf("Salir");
  switch(op)
  {


        case 1:
      t(10);gotoxy(0,5);printf("Insertar Datos");break;
     case 2:
      t(10);gotoxy(20,5);printf("Buscar");break;
     case 3:
      t(10);gotoxy(35,5);printf("Modificar");break;
      case 4:
      t(10);gotoxy(50,5);printf("Eliminar");break;
      case 5:
      t(10);gotoxy(60,5);printf("Imprimir");break;
      case 6:
      t(10);gotoxy(70,5);printf("Salir");break;
  }


   do{
      tecla=getch();
      }while(tecla!=77 && tecla!=75 && tecla!=80 && tecla!=13 );
//tecla 13 enter

      if(tecla==75)
      {

       if(op>1)
       {
       op--;
       }
       }
       if(tecla==77)
      {

       if(op<6)
       {
       op++;
       }
       }

       }while(tecla!=80&&tecla!=13);
    //do{
            system("cls");
           switch(op)
  {

  case 1:
      c+=1;
      printf("\t\t\tInsertar Datos\n");
        do
        {
        y=insertar( );
        cont++;
        }while(y!='N' && y!='n');

        guardarFile(lista);
        getch();
        break;
  case 2:

      if(c!=0)
        {
            printf("\t\t\tBuscar\n");
            buscarPos(cont,lista);
            guardarFile(lista);
        }

        else
        {
            printf("La lista esta vacia no se encontraron datos\n");
        }
            getch();
            break;
  case 3:

      if(c!=0)
        {
            printf("\t\t\tModificar\n");
            modificarNum(lista);
            guardarFile(lista);
        }

        else
        {
            printf("La lista esta vacia no se encontraron datos\n");
        }


      getch();break;

  case 4:
      if(c!=0)
        {
            printf("\t\t\tEliminar\n");
            eliminar(cont,lista);
            guardarFile(lista);
        }

        else
        {
            printf("La lista esta vacia no se encontraron datos\n");
        }
       getch();break;


  case 5:
    if(c!=0)
        {
            printf("\t\t\tLISTA\n");
            imprimir(lista);
            guardarFile(lista);
        }

        else
        {
            printf("La lista esta vacia no se encontraron datos\n");
        }
        getch();
            break;

  case 6:gotoxy(25,8);

      fflush(stdin);
      system("pause");

  break;
  }
  system("cls");
 }while(op!=6);
    /*do{
    printf("\t\t\tMENU PRINCIPAL - LISTA SIMPLE\n");
    printf("1. Insertar Datos\n");
    printf("2. Buscar\n");
    printf("3. Modificar\n");
    printf("4. Eliminar\n");
    printf("5. Mostrar\n");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        printf("\t\t\tInsertar Datos\n");
        do
        {
        y=insertar( );
        cont++;
        }while(y!='N' && y!='n');
        c++;
        guardarFile(lista);
        break;

    case 2:
        if(c=0)
        {
            printf("\t\t\tBuscar\n");
            buscarPos(cont,lista);
            guardarFile(lista);
        }

        else
        {
            printf("La lista esta vacia no se encontraron datos\n");
        }
            break;

    case 3:
        if(c=0)
        {
            printf("\t\t\tModificar\n");
            modificarNum(lista);
            guardarFile(lista);
        }

        else
        {
            printf("La lista esta vacia no se encontraron datos\n");
        }
            break;

    case 4:
        if(c=0)
        {
            printf("\t\t\tEliminar\n");
            eliminar(cont,lista);
            guardarFile(lista);
        }

        else
        {
            printf("La lista esta vacia no se encontraron datos\n");
        }
            break;

    case 5:
        if(c=0)
        {
            printf("\t\t\tLISTA\n");
            imprimir(lista);
            guardarFile(lista);
        }

        else
        {
            printf("La lista esta vacia no se encontraron datos\n");
        }
            break;

    case 0:
        printf("Salir\n");

    default:
        printf("Opcion incorrecta\n");

    }
    system("pause");
    system("cls");
    }while(op!=0);
*/

}
int main()
{
    menu();


    return 0;
}
