//
// Created by Manol on 11/3/2026.
//

#include "GestorPlantas.h"

void GestorPlantas::actualizar() {
    Planta** lista = new Planta*[matriz->getFilas() * matriz->getColumnas()];
    int cantidad = recolectar(lista);

    for (int i = 0; i < cantidad; i++) {
        if (((rand() % PROBABILIDAD) + 1) != 1) {
            continue;
        }

        int fila, columna;
        if (posicionVaciaAleatoria(fila, columna)) {
            matriz->mover(lista[i]->obtenerFila(), lista[i]->obtenerColumna(), fila, columna);
        }
    }

    delete[] lista;
}