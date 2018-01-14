/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
ESTRUCTURAS DE DATOS
NRC: 2479
MAURICIO RUIZ
*/

#include <iostream>
#include <stdio.h>

struct Nodo{
    int entero;
    Nodo *sig;

} *ptr;

void insertar(Nodo *p)
{
    do{
    printf("Ingrese un numero\n");
    scanf("%d",&p->entero);
    }while(p->entero<0);
    p->sig=ptr;
    ptr=p;

};

void recorrer(Nodo *c)
{
    Nodo *k;
    k=c;

    do{
        printf("%d\n",k->entero);
        k=k->sig;
    }while(k!=NULL);
}

int main()
{
    Nodo *p = new Nodo;
    Nodo *l = new Nodo;
    Nodo *m = new Nodo;


    insertar(p);
    insertar(l);
    insertar(m);
    printf("Numeros en lista\n");
    recorrer(ptr);
    return 0;
}
