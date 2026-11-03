//
// Created by Manol on 11/2/2026.
//

#ifndef PROYECTO3_MATRIZ_CONTROLTURNOS_H
#define PROYECTO3_MATRIZ_CONTROLTURNOS_H

#include <mutex>
#include <condition_variable>

class ControlTurnos {
private:
    std::mutex mtx;
    std::condition_variable cvInicio;
    std::condition_variable cvFin;
    int turno;
    int terminados;
    int totalHilos;
    bool apagado;

public:
    explicit ControlTurnos(int totalHilos);

    bool esperarTurno(int& ultimoTurno);
    void terminarTurno();

    void avanzarYEsperar();
    void apagar();
    void reiniciar();
};


#endif //PROYECTO3_MATRIZ_CONTROLTURNOS_H