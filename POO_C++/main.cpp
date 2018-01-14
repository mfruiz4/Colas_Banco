#include <iostream>
#include <stdio.h>

using namespace std;

class Persona{

private :float peso, estatura;

public :
void pedirP()
{
    printf("Ingrese el peso de la persona\n");
    scanf("%f",&peso);
    //Scanner s = new Scanner(System.in);

};

void pedirE()
{
    printf("Ingrese LA ESTATURA de la persona\n");
    scanf("%f",&estatura);
}

void mostrarP()
{
    printf("El peso de la persona es: %.2f\n",peso);
}

void mostrarE()
{
    printf("La estatura de la persona es: %.2f\n",estatura);
}
};

int main()
{
    Persona *p = new Persona();
    p->pedirE();
    p->pedirP();
    p->mostrarP();
    p->mostrarE();

    return 0;
}
