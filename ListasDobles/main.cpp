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
    Nodo *ant;
}*lista,*primos;

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

//

 void iniciar()
 {

     Nodo * p= new Nodo;
     printf("Ingrese un primer elemento en la lista vacia\n");
     scanf("%d",&p->datoEntero);
     lista = p;
    lista->ant=NULL;
    lista->sig=NULL;

    Nodo *aux=new Nodo;
    aux->datoEntero=1;
    primos=aux;
    primos->ant=NULL;
    primos->sig=NULL;

 }
void insertarInicio( )
{
    Nodo *p = new Nodo;
    printf("Ingrese un elemento al inicio de la lista\n");
    scanf("%d",&p->datoEntero);
    p->sig=lista;
    p->ant=lista->ant;
    lista->ant=p;
    lista=p;

};
void insertarFin( )
{
    Nodo *p = new Nodo;
    printf("Ingrese un elemento al final de la lista\n");
    scanf("%d",&p->datoEntero);
    p->sig=lista->sig;
    lista->sig=p;
    p->ant=lista;
    //lista=p;

};
void insertarEntre( )
{
    Nodo *p = new Nodo;
    printf("Ingrese un elemento entre la lista\n");
    scanf("%d",&p->datoEntero);
    p->sig=lista->sig;
    lista->sig=p;
    p->ant=lista;
    p->sig->ant=p;
    //lista=p;

};

void imprimir(Nodo *c)
{
    Nodo *k;
    k=c;
    do{
        printf("-> %d",k->datoEntero);
        k=k->sig;
    }while(k!=NULL);
}

void buscar(Nodo *c)
{
    Nodo *k;
    k=c;
    int num,i=1;
    printf("\nIngrese el numero que quiere buscar\n");
    scanf("%d",&num);
    do{
            if(k->datoEntero==num)
                printf("Numero %d encontrado en la posicion %d\n",num,i);

                k=k->sig;
                i++;

    }while(k!=NULL);
}

void eliminarPrimero()
{
    Nodo *p ;
    printf("\nELIMINAR INICIO\n");
    p=lista;
    lista=lista->sig;
    lista->ant=NULL;

    delete p;

}

void nprimos(Nodo *c, Nodo *d)
{
    Nodo *k,*aux;
    int op,cont,num;
    k=c;

    do{

    printf("\t\tMENU DE NUMEROS PRIMOS\n");
    printf("1. Obtener numeros primos\n");
    printf("2. Imprimir numeros primos\n");
    printf("0. Salir\n");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        aux=d;
        do{
        num=k->datoEntero;
        cont =0;

        for(int i=1;i<(num+1);i++)
        {
         if((num%i)==0)
         {

             cont++;

         }

        }

            if(cont<=2){

            Nodo *p = new Nodo;
            p->datoEntero = num;
            p->sig=aux;
            p->ant=aux->ant;
            aux->ant=p;
            aux=p;
            }


            k=k->sig;
        }while(k!=NULL);
        printf("SE HAN OBTENIDO EXITOSAMENTE LOS NUMEROS PRIMOS\n");
        break;

    case 2:
        imprimir(lista);
        printf("\nNumeros primos de la lista\n");
        do{
            printf("-> %d",aux->datoEntero);
            aux=aux->sig;
        }while(aux!=NULL);
        printf("\n");
        break;

    case 0:
        printf("Salir\n");
        break;

    default:
        printf("Opcion Incorrecta\n");
    }
    system("pause");
    system("cls");
    }while(op!=0);

}

/*void eliminarFin()
{
    Nodo *p ;
    printf("\nELIMINAR FIN\n");

    do{
        lista=lista->sig;
    }while(lista!=NULL);
     p=lista;
    lista=lista->ant;
    lista->ant->sig=lista;
    lista->sig=NULL;

    delete p;

}*/

void menu()
{
    iniciar();
    int tecla, op=1;

    do{
    gotoxy(25,0);printf("MENU PRINCIPAL - Seleccione una opcion ");


     do{
  gotoxy(0,5);printf("In. Inicio");
  gotoxy(20,5);printf("In. Fin");
 gotoxy(35,5);printf("In. Entre");
  gotoxy(50,5);printf("Eliminar ");
  gotoxy(60,5);printf("Imprimir");
  gotoxy(70,5);printf("N. Primos");
  gotoxy(80,5);printf("Salir");
  switch(op)
  {


        case 1:
      t(10);gotoxy(0,5);printf("In. Inicio");break;
     case 2:
      t(10);gotoxy(20,5);printf("In. Fin");break;
     case 3:
      t(10);gotoxy(35,5);printf("In. Entre");break;
      case 4:
      t(10);gotoxy(50,5);printf("Eliminar");break;
      case 5:
      t(10);gotoxy(60,5);printf("Imprimir");break;
      case 6:
      t(10);gotoxy(70,5);printf("N. Primos");break;
      case 7:
      t(10);gotoxy(80,5);printf("Salir");break;
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

       if(op<7)
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

      printf("\t\t\tInsertar Datos Al Inicio\n");

       insertarInicio();


        getch();
        break;
  case 2:

          printf("\t\t\tInsertar Datos Al Final\n");

       insertarFin();

            getch();
            break;
  case 3:



             printf("\t\t\tInsertar Datos Entre\n");

       insertarEntre();




      getch();break;

  case 4:

            printf("\t\t\tEliminar\n");
            eliminarPrimero();


       getch();break;


  case 5:

            printf("\t\t\LISTA\n");
            imprimir(lista);
        getch();
            break;


    case 6:

      printf("\t\t\BUSCAR NUMEROS PRIMOS\n");
            nprimos(lista,primos);

            getch();
            break;

  case 7:gotoxy(25,8);

      fflush(stdin);
      system("pause");

  break;
  }
  system("cls");
 }while(op!=7);
}
int main()
{
    menu();

    return 0;
}
