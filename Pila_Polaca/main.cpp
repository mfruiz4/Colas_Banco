/*
Universidad de las Fuerzas Armadas
Estructuras de Datos
Tema: PILAS
Nombre: Mauricio Ruiz
NRC: 2479
*/


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct nodo{
	int valor;
	struct nodo *sgte;
};
class Pil
{
	public:
		int pasaCadenaAEntero( char []);
		void insertaDatoEnLaPila(struct nodo **pila, int num);
		int extraeDatoDeLaPila(struct nodo **pila);
		void listaLiberaRam(struct nodo **lista);
};

int Pil::pasaCadenaAEntero(char cadena[20])
{
	int longCadena=strlen(cadena), numero=0, i;

	for( i=0; i<longCadena; i++ )
	{
		numero *= 10;
		numero += cadena[i]-48;
	};

	return numero;
}
void Pil::insertaDatoEnLaPila( struct nodo **pila, int num )
{
	struct nodo *temp = (struct nodo *) malloc(sizeof(struct nodo));
	temp->valor		= num;
	temp->sgte	= *pila;
	*pila			= temp;

};
// FUNCIÓN QUE EXTRAE EL PRIMER ELEMENTO DE LA PILA Y BORRA EL NODO VACIO:
int Pil::extraeDatoDeLaPila( struct nodo **pila )
{
	struct nodo *siguiente;
	int resp;
	// Se copia el valor a la variable que va a ser retornada por la función:
	resp = (*pila)->valor;
	// Se elimina el primer Nodo (el vaciado):
	siguiente = (*pila)->sgte;
	free(*pila);
	*pila = siguiente;
	return resp;
};
// FUNCIÓN QUE LIBERA LA MEMORIA USADA POR UNA LISTA:
void Pil::listaLiberaRam( struct nodo **lista )
{
	struct nodo *actual, *siguiente;
	actual = *lista;
	while(actual != NULL)
	{
		siguiente = actual->sgte;
		free(actual);
		actual = siguiente;
	};
	*lista = NULL;
};

int main()
{
	char cad[20];
	Pil pil;
	struct nodo *pila;
	int val1, val2;
     printf("\t\t\tPOLACA\n");
    printf("Instrucciones de Uso:\n");
	printf( "-Introduzca un valor u operador.\n-Pulse intro para introducir el siguiente.\n-Escriba = para calcular el resultado.\n" );
	printf( "Ejemplo:\n\n   2\n   2\n   +\n   3\n   *\n   5\n   *\n \n" );
	printf( "Ingrese los valores:\n\n" );
	do{

		// Se lee un valor o operador:
		scanf( "%s", cad );


		// Dependiendo de lo leido se hace una operacion u otra:
		switch( cad[0] )
		{
			case '+':
				// En el caso de la: '+', '-', '*' y '/', se sacan dos valores de la pila, se opera con ellos según el operador elegido y se guarda el resultado en la pila.

				val1 = pil.extraeDatoDeLaPila( &pila );
				val2 = pil.extraeDatoDeLaPila( &pila );
				pil.insertaDatoEnLaPila( &pila, val1 + val2 );
			break;


			case '-':
				val1 = pil.extraeDatoDeLaPila( &pila );
				val2 = pil.extraeDatoDeLaPila( &pila );
				pil.insertaDatoEnLaPila( &pila, val1 - val2 );
			break;


			case '*':
				val1 = pil.extraeDatoDeLaPila( &pila );
				val2 = pil.extraeDatoDeLaPila( &pila );
				pil.insertaDatoEnLaPila( &pila, val1 * val2 );
			break;


			case '/':
				val1 = pil.extraeDatoDeLaPila( &pila );
				val2 = pil.extraeDatoDeLaPila( &pila );
				pil.insertaDatoEnLaPila( &pila, val1 / val2 );
			break;


			case '=':
				// Se imprime por pantalla el ultimo y único elemento de la pila.
				printf( "\nEl resultado es: %i\n\n", pil.extraeDatoDeLaPila( &pila ) /*pila->valor*/ );
			break;


			default:
				// Se introduce un nuevo dato en la pila:
				pil.insertaDatoEnLaPila( &pila, pil.pasaCadenaAEntero(cad));
			break;
		};

	} while( cad[0] != '=' );
}

