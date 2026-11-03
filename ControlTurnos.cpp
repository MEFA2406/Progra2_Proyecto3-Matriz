//
// Created by Manol on 11/2/2026.
//

#include "ControlTurnos.h"

ControlTurnos::ControlTurnos(int totalHilos) :turno(0),terminados(0),totalHilos(totalHilos),apagado(false){
}

bool ControlTurnos::esperarTurno(int &ultimoTurno) {
    std::unique_lock<std::mutex> bloqueo(mtx);
    cvInicio.wait(bloqueo,[&] {return apagado || turno > ultimoTurno;});
    if (apagado) {
        return false;
    }
    ultimoTurno = turno;
    return true;
}

void ControlTurnos::terminarTurno() {
    std::lock_guard<std::mutex> bloqueo(mtx);
    terminados++;
    if (terminados >= totalHilos) {
        cvFin.notify_one();
    }
}

void ControlTurnos::avanzarYEsperar() {
    std::unique_lock<std::mutex> bloqueo(mtx);
    if (apagado) {
        return;
    }
    terminados = 0;
    turno++;
    cvInicio.notify_all();
    cvFin.wait(bloqueo,[&] {return apagado || terminados >= totalHilos; });
}

void ControlTurnos::apagar() {
    std::lock_guard<std::mutex> bloqueo(mtx);
    apagado = true;
    cvInicio.notify_all();
    cvFin.notify_all();
}

void ControlTurnos::reiniciar() {
    std::lock_guard<std::mutex> bloqueo(mtx);
    apagado = false;
    turno=0;
    terminados=0;
}
