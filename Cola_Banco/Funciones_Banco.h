#ifndef FUNCIONES_BANCO_H_INCLUDED
#define FUNCIONES_BANCO_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>
#include <time.h>




int tiempodellegada()
{



    return (rand()%30);
}

int tiempodesservicio()
{
    int t;

    t = (rand()%16)+1;
    return t;
}


int tiempodeespera(int salida,int llegada)
{
   int mayor;

   if(salida>llegada)
        mayor=salida;

   else
    mayor= llegada;

   return (mayor-llegada);

}

int tiempodedescanso(int salida,int llegada)
{
   int mayor;

   if(salida>llegada)
        mayor=salida;

   else
    mayor= llegada;

   return (mayor-salida);

}

int tiempodesalida(int llegada, int espera,int servicio)
{
    return(llegada+espera+servicio);
}

int tiempoentrellegadas(int llegada1, int llegada2)
{

    return(llegada2-llegada1);
}

#endif // FUNCIONES_BANCO_H_INCLUDED
