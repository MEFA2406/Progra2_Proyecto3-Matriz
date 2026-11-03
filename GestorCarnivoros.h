//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_GESTORCARNIVOROS_H
#define PROYECTO3_MATRIZ_GESTORCARNIVOROS_H

#include <thread>
#include <mutex>
#include <atomic>

#include "Carnivoro.h"
#include "ControlHilos.h"
#include "Matriz.h"

class GestorCarnivoros : public ControlHilos{
protected:
    void actualizar() override;
public:
    GestorCarnivoros(Matriz* matriz, std::mutex& mutexMatriz, ControlTurnos& controlTurnos);
};



#endif //PROYECTO3_MATRIZ_GESTORCARNIVOROS_H
