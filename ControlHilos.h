//
// Created by Manol on 11/3/2026.
//

#ifndef PROYECTO3_MATRIZ_CONTROLHILOS_H
#define PROYECTO3_MATRIZ_CONTROLHILOS_H

#include <mutex>
#include <thread>

#include "ControlTurnos.h"
#include "Matriz.h"


class ControlHilos {
private:
    std::thread hilo;
    ControlTurnos& control;

    void ejecutar();

protected:
    Matriz* matriz;
    std::mutex& mutexMatriz;

    virtual void actualizar() =0;

    template<typename T>
    int recolectar(T** destino) {
        int cantidad = 0;
        for (int f = 0; f < matriz->getFilas(); f++) {
            for (int c = 0; c < matriz->getColumnas(); c++) {
                T* entidad = dynamic_cast<T*>(matriz->getPosicion(f, c));
                if (entidad != nullptr) {
                    destino[cantidad++] = entidad;
                }
            }
        }
        return cantidad;
    }

    bool moverAleatorio(Entidad* entidad);

    bool posicionVaciaAleatoria(int& fila, int& columna);

public:
    ControlHilos(Matriz* matriz, std::mutex& mutexMatriz, ControlTurnos& control);
    virtual ~ControlHilos();

    ControlHilos(const ControlHilos&) = delete;
    ControlHilos& operator=(const ControlHilos&) = delete;

    void iniciar();

    void detener();
};


#endif //PROYECTO3_MATRIZ_CONTROLHILOS_H