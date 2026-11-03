//
// Created by Manol on 11/2/2026.
//

#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::menuPrincipal() {
}

void Menu::menuAccion() {
    do {
        int x,y;
        cout<<matriz->mostrar();
        cout<<"x:";
        cin >> x;
        cout<<"y:";
        cin >> y;
        matriz->mover(jugador->obtenerFila(),
            jugador->obtenerColumna(),x,y);
    }while (jugador->getVida()>0);
}

Menu::Menu() {
    jugador = new Jugador(7,7);
    carnivoro = new Carnivoro(1,5,5);
    matriz = new Matriz();
    matriz->setPosicion(7,7,jugador);
    matriz->setPosicion(5,5,carnivoro);
}

Menu::~Menu() {
    delete matriz;
}

void Menu::initMenu() {
    menuAccion();
}
