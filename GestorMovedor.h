//
// Created by Manol on 11/3/2026.
//

#ifndef PROYECTO3_MATRIZ_GESTORMOVEDOR_H
#define PROYECTO3_MATRIZ_GESTORMOVEDOR_H

#include "ControlHilos.h"
#include "Comida.h"
#include "Loot.h"

// Template: hilo que mueve al azar, una celda por turno, todas las entidades
// de tipo T. Sirve para la comida y para el equipamiento (Loot).
template<typename T>
class GestorMovedor : public ControlHilos {
protected:
    void actualizar() override {
        T** lista = new T*[matriz->getFilas() * matriz->getColumnas()];
        int cantidad = recolectar(lista);

        for (int i = 0; i < cantidad; i++) {
            moverAleatorio(lista[i]);
        }

        delete[] lista;
    }
public:
    GestorMovedor(Matriz* matriz, std::mutex& mutexMatriz, ControlTurnos& control)
        : ControlHilos(matriz, mutexMatriz, control) {}
};

using GestorComida = GestorMovedor<Comida>;
using GestorEquipamiento = GestorMovedor<Loot>;

#endif //PROYECTO3_MATRIZ_GESTORMOVEDOR_H