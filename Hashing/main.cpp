/*
*
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define LARGO 12

struct Tabla
{
    int ced;
    bool estado;
    int indice;
};

void iniciar(Tabla *&t)
{
   t = (Tabla*)malloc(LARGO*sizeof(Tabla));

   for(int i =0;i<LARGO;i++)
   {
       t[i].estado= true;
       t[i].indice=i+1;
       t[i].ced=0;
   }
}
int posicion(int c)
{
   int pos;
   do{
   pos = c%LARGO;
   c-=LARGO;
   }while(pos>LARGO);
   //printf("POSICION RETORNADA %d\n",pos);
    return pos;
}

char insertar(Tabla *t,int c)
{
    char x;
    int pos;
    bool aux;
    pos = posicion(c);
    do{
        aux = t[pos].estado;
    if(t[pos].estado==true)
    {
        t[pos].estado=false;
        t[pos].ced=c;
        printf("Elemento insertado en la posicion %d\n",pos+1);
    }
    else
    {
        printf("Colision en la posicion %d, recalculando\n",pos+1);
       pos++;

    }


        }while(aux!=true);

        printf("Desea ingresar otro elemento? S/N\n");
        x=getch();
        return x;

}

void mostrar(Tabla *t)
{
    printf("Tabla de dispersion\n");
   printf("Indice\tNumero\n");
  for(int i =0;i<LARGO;i++)
   {
       printf("%d\t%d\n",t[i].indice,t[i].ced);
   }
  ;


}
int main()
{
    char op;
    int c;
    Tabla *t = NULL;

    iniciar(t);
    do{
    printf("Ingrese un numero\n");
    scanf("%d",&c);
    op =insertar(t,c);
    }while(op!='N' && op!= 'n');
    mostrar(t);

}
