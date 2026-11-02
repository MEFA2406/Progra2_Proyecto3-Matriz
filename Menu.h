//
// Created by Manol on 11/2/2026.
//

#ifndef PROYECTO3_MATRIZ_MENU_H
#define PROYECTO3_MATRIZ_MENU_H

#include "Matriz.h"
#include "Armadura.h"
#include "Botas.h"
#include "Casco.h"
#include "Jugador.h"
#include "Carnivoro.h"
#include "Comida.h"

class Menu {
private:
    //Sistema
    Matriz* matriz;
    Jugador* jugador;
    Carnivoro* carnivoro;

    void menuPrincipal();
    void menuAccion();

public:
    Menu();
    ~Menu();
    void initMenu();
};


#endif //PROYECTO3_MATRIZ_MENU_H