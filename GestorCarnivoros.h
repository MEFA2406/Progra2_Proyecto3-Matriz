//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_GESTORCARNIVOROS_H
#define PROYECTO3_MATRIZ_GESTORCARNIVOROS_H

#include <thread>
#include <mutex>
#include <atomic>

#include "Carnivoro.h"
#include "Matriz.h"

class GestorCarnivoros {
    Carnivoro** carnivoros;
    int cantidad;

    Matriz* matriz;
    std::mutex& mutexMatriz;

    std::thread hilo;
    std::atomic<bool> activo;

    void ejecutar();
    void moverCarnivoros();
public:
    GestorCarnivoros(Carnivoro** carnivoros, int cantidad,Matriz* matriz, std::mutex& mutexMatriz);
    ~GestorCarnivoros();

    void iniciar();
    void detener();
};



#endif //PROYECTO3_MATRIZ_GESTORCARNIVOROS_H
