#include <iostream>
#include "Equipamiento.h"
#include "Personaje.h"
#include "Jugador.h"
#include "Botas.h"
#include "Armadura.h"
#include "Carnivoro.h"
#include "Casco.h"
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    Personaje* jugador = new Jugador(5,5);

    jugador = new Casco(jugador);
    jugador = new Botas(jugador);

    auto enemigo1 = new Carnivoro(1,1,1);

    Entidad*** matriz;
    matriz = new Entidad**[15];
    for (int i=0;i<15;i++) {
        matriz[i] = new Entidad*[15];
        for (int j=0;j<15;j++) {
            matriz[i][j] = nullptr;
        }
    }

    matriz[enemigo1->obtenerFila()][enemigo1->obtenerColumna()] = enemigo1;
    matriz[jugador->obtenerFila()][jugador->obtenerColumna()] = jugador;
    cout << "      ";
    for (int j = 0; j < 15; j++) {
        cout << setw(2) << setfill('0') << j << "   ";
    }

    cout << endl << setfill(' ');

    // Borde superior
    cout << "    +";
    for (int j = 0; j < 15; j++) {
        cout << "----+";
    }
    cout << endl;

    // Contenido de la matriz
    for (int i = 0; i < 15; i++) {

        cout << setw(2) << setfill('0') << i << "  ";
        cout << setfill(' ');

        for (int j = 0; j < 15; j++) {

            if (matriz[i][j] == nullptr) {
                cout << "|    ";
            }
            else {
                cout << "| " << matriz[i][j]->obtenerSimbolo() << "  ";
            }
        }

        cout << "|" << endl;

        // Separación entre filas
        cout << "    +";
        for (int j = 0; j < 15; j++) {
            cout << "----+";
        }
        cout << endl;
    }

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


    delete jugador;
    return 0;
}