//
// Created by Manol on 11/2/2026.
//

#include "Planta.h"

Planta::Planta(int fila, int col) :Entidad(fila,col){
}

char Planta::obtenerSimbolo() const {
    return 'P';
}
