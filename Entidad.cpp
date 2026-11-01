//
// Created by Manol on 10/31/2026.
//

#include "Entidad.h"

Entidad::Entidad(int fila, int columna) : fila(fila), columna(columna) {
}

int Entidad::obtenerFila() const {
    return fila;
}

int Entidad::obtenerColumna() const {
    return columna;
}

void Entidad::cambiarPosicion(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
}

