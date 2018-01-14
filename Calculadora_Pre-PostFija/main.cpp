/*
Universidad de las Fuerzas Armadas
Estructuras de Datos
PROYECTO PARCIAL 2
Nombre: Mauricio Ruiz, Andres Sanaguano, Carlos Yupa
NRC: 2479
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Numeros{
    int dato;
    Numeros *sig;
};

struct Operaciones{
    char signo;
    Operaciones *sig;
};

struct Infijo{
    char c;
    Infijo *sig;
};

void mostrarInfijo(Infijo *inicio, Infijo *fin)
{
    Infijo *aux = inicio;
    if(inicio!=NULL)
    {
    //printf("Ingrese la operacion. (Enter para terminar)\n");
    do{
            printf("%c ",aux->c);
        aux=aux->sig;
    }while(aux!=NULL);
    }


}
char ingresoDatos(Infijo *&inicio,Infijo *&fin)
{

    Infijo *aux = new Infijo();
    char x;
    x = getch();
    aux->c=x;

    if(inicio == NULL){
    aux->sig=NULL;
    inicio=aux;
    }
    else{
        fin->sig=aux;
    }
        fin=aux;

    return x;
}
int main()
{
    char x;
   /* Numeros *pilaN = NULL;
    Operaciones *pilaO = NULL;*/
    Infijo *Inicio = NULL;
    Infijo *Fin = NULL;


    do{
    system("cls");
    printf("Ingrese la operacion. (Enter para terminar)\n");
    mostrarInfijo(Inicio,Fin);
    x=ingresoDatos(Inicio, Fin);
    }while(x!=13);
    printf("\nOperacion ingresada correctamente - Notacion Infija\n");

    return 0;
}
