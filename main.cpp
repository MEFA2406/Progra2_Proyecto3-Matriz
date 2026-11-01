#include <iostream>
#include "Equipamiento.h"
#include "Personaje.h"
#include "Jugador.h"
#include "Botas.h"
#include "Armadura.h"
#include "Carnivoro.h"
#include "Casco.h"
#include "Matriz.h"
#include <sstream>
#include <iomanip>

#include "Matriz.h"

using namespace std;

int main() {
    Personaje* jugador = new Jugador(5,5);

    jugador = new Casco(jugador);
    jugador = new Botas(jugador);

    auto enemigo1 = new Carnivoro(1,1,1);





    cout<<"Vida: "<< jugador->getVida()<<endl;
    cout<<"Proteccion: "<<jugador->getProteccion()<<endl;

    cout<<"Primer ataque 5"<<endl;
    enemigo1->atacar(jugador);

    cout<<"Vida: "<< jugador->getVida()<<endl;
    cout<<"Proteccion: "<<jugador->getProteccion()<<endl;

    cout<<"Segundo ataque 5"<<endl;
    enemigo1->atacar(jugador);

    cout<<"Vida: "<< jugador->getVida()<<endl;
    cout<<"Proteccion: "<<jugador->getProteccion()<<endl;

    enemigo1->setNivel(2);
    enemigo1->atacar(jugador);

    cout<<"Vida: "<< jugador->getVida()<<endl;
    cout<<"Proteccion: "<<jugador->getProteccion()<<endl;

    Matriz* matriz2 = new Matriz();
    cout<<matriz2->mostrar();

    matriz2->setPosicion(1,1,enemigo1);
    matriz2->setPosicion(5,5,jugador);

    cout<<matriz2->mostrar();

    delete enemigo1;
    delete jugador;
    delete matriz2;
    return 0;
}