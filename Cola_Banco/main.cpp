/*
Universidad de las Fuerzas Armadas
Estructuras de Datos
Tema: COLAS
Nombre: Mauricio Ruiz, Andres Sanaguano, Carlos Yupa
NRC: 2479
*/
#include<iostream>
#include <Funciones_Banco.h>

struct Cliente{
    int t_llegada;
    int t_espera;
    int t_descanso;
    int t_servicio;
    int t_salida;
    int t_e_llegadas;
    Cliente *sig;

};


class Banco{

public:


    Cliente *Insertar(Cliente *&inicio, Cliente *&fin, Cliente *anterior )
    {
        Cliente *nuevo = new Cliente();

        if(inicio==NULL)
        {
            nuevo->t_llegada=tiempodellegada();
            nuevo->t_espera=0;
            nuevo->t_descanso=0;
            nuevo->t_e_llegadas=nuevo->t_llegada;
            nuevo->t_servicio=tiempodesservicio();
            nuevo->t_salida=tiempodesalida(nuevo->t_llegada,nuevo->t_espera,nuevo->t_servicio);
            nuevo->sig=NULL;
            inicio=nuevo;

        }

        else
        {

            nuevo->t_llegada=tiempodellegada();
            nuevo->t_llegada+=anterior->t_llegada;
            nuevo->t_espera=tiempodeespera(anterior->t_salida,nuevo->t_llegada);
            nuevo->t_descanso=tiempodedescanso(anterior->t_salida,nuevo->t_llegada);
            nuevo->t_e_llegadas=tiempoentrellegadas(anterior->t_llegada,nuevo->t_llegada);
            nuevo->t_servicio=tiempodesservicio();
            nuevo->t_salida=tiempodesalida(nuevo->t_llegada,nuevo->t_espera,nuevo->t_servicio);
            fin->sig=nuevo;
        }
        fin=nuevo;


        return nuevo;
    }

    void Mostrar(Cliente *inicio, Cliente *fin,int cont)
    {
        Cliente *aux = inicio;

         printf("Cliente\tLlegada\tEspera\tDescanso\tServicio\tSalida\tEntre Llegadas\n");
        do{
           printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n",cont,aux->t_llegada,aux->t_espera,aux->t_descanso,aux->t_servicio,aux->t_salida,aux->t_e_llegadas);
            aux=aux->sig;
            cont++;
        }while(aux!=NULL);
    }
    void Eliminar(Cliente *&inicio, Cliente *&fin)
    {
        Cliente *aux = inicio;

        if(inicio == fin)
        {
            inicio = NULL;
            fin = NULL;
        }

        else
            inicio = inicio->sig;

        delete aux;
    }
};




int main()
{
    int n,n1,cont=0;
    Cliente *inicio = NULL;
    Cliente *fin = NULL;
    Cliente *aux = new Cliente();
    Banco *iniciar = new Banco();
    Banco *imprimir = new Banco();
    Banco *quitar = new Banco();
    srand(time(NULL));
    printf("CUANTOS CLIENTES DESEA INGRESAR?\n");
    scanf("%d",&n);

    do{
        aux=iniciar->Insertar(inicio,fin,aux);
        cont++;
    }while(cont<n);
    cont=1;
    imprimir->Mostrar(inicio,fin,cont);
    do{
    printf("Cuantos clientes desea eliminar ?\n");
    scanf("%d",&n1);
    }while(n1>=n);
    cont=0;
    do{
        quitar->Eliminar(inicio,fin);
        cont++;
    }while(cont<n1);
    cont=1;
    printf("--------------------------------------------------------------------------------\n");
    imprimir->Mostrar(inicio,fin,cont);


    delete(aux);
    delete(iniciar);
    delete(imprimir);
    return 0;
}
