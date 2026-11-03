//
// Created by Manol on 11/3/2026.
//

#ifndef PROYECTO3_MATRIZ_GESTORPLANTAS_H
#define PROYECTO3_MATRIZ_GESTORPLANTAS_H

#include "ControlHilos.h"
#include "Planta.h"

// Hilo de plantas: redistribuye los obstaculos. En cada turno, cada planta
// tiene 1 probabilidad entre PROBABILIDAD de saltar a una celda vacia al azar

class GestorPlantas : public ControlHilos {
private:
    static const int PROBABILIDAD = 3;
protected:
    void actualizar() override;
public:
    GestorPlantas(Matriz* matriz, std::mutex& mutexMatriz, ControlTurnos& control)
        : ControlHilos(matriz, mutexMatriz, control) {}
};

#endif //PROYECTO3_MATRIZ_GESTORPLANTAS_H