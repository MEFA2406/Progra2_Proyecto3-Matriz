//
// Created by Manol on 10/31/2026.
//

#include "Comida.h"

Comida::Comida(int valor, int fila, int columna) :valor(valor), Entidad(fila, columna){
}

int Comida::getValor() const {
    return valor;
}

char Comida::obtenerSimbolo() const {
    return 'C';
}
