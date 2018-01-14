#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;
    Nodo *sig;
};


void insertar(Nodo *&pila)
{
    int n;
    Nodo *aux = new Nodo();
    printf("Ingrese el elemento deseado\n");
    scanf("%d",&n);
    aux->dato=n;
    aux->sig=pila;
    pila=aux;

}
void eliminar(Nodo *&pila)
{
    int n;
    Nodo *aux = pila;
    n=aux->dato;
    pila=aux->sig;
    delete aux;

    printf("Elemento %d eliminado correctamente\n",n);

}
void mostrar(Nodo *pila)
{
    printf("Elementos en la pila\n");
    do{
        printf("|%d",pila->dato);
        pila=pila->sig;
    }while(pila!=NULL);
}
int main()
{
    Nodo *pila = NULL;
    insertar(pila);
    insertar(pila);
    insertar(pila);
    eliminar(pila);
    mostrar(pila);
    return 0;
}
