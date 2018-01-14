#include <iostream>

using namespace std;

struct Nodo{
    int entero;
    Nodo *sig;

} *cabeza;

int main()
{
    Nodo *uno = new Nodo;
    Nodo *dos = new Nodo;
    Nodo *tres = new Nodo;

    cabeza=uno;

    uno->sig = dos;
    dos->sig = tres;
    tres->sig = NULL;

    uno->entero = 1;
    dos->entero = 2;
    tres->entero = 3;

    cout<<cabeza->entero<<cabeza->sig->entero<<cabeza->sig->sig->entero<<endl;

    return 0;
}
