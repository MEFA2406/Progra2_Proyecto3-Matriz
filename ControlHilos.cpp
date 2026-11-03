//
// Created by Manol on 11/3/2026.
//

#include "ControlHilos.h"

void ControlHilos::ejecutar() {
    int ultimoTurno = 0;
    while (control.esperarTurno(ultimoTurno)) {
        std::lock_guard<std::mutex> bloqueo(mutexMatriz);
        actualizar();
    }
    control.terminarTurno();
}

bool ControlHilos::moverAleatorio(Entidad *entidad) {
    const int dFila[4] = {-1,1,0,0};
    const int dColuna[4] = {0,0,-1,1};

    int inicio = rand() % 4;
    for (int i=0;i<4;i++) {
        int d = (inicio + i) % 4;
        int nuevaFila = entidad->obtenerFila() + dFila[d];
        int nuevaColumna = entidad->obtenerColumna() + dColuna[d];

        if (matriz->posicionValida(nuevaFila, nuevaColumna) &&
            matriz->getPosicion(nuevaFila, nuevaColumna) == nullptr) {
            return matriz->mover(entidad->obtenerFila(),entidad->obtenerColumna(),nuevaFila,nuevaColumna);
        }
    }
    return false;
}

bool ControlHilos::posicionVaciaAleatoria(int &fila, int &columna) {
}

ControlHilos::ControlHilos(Matriz *matriz, std::mutex &mutexMatriz, ControlTurnos &control) : control(control), matriz(matriz),mutexMatriz(mutexMatriz){
}

ControlHilos::~ControlHilos() {
    detener();
}

void ControlHilos::iniciar() {
    if (hilo.joinable()) {
        hilo = std::thread(&ControlHilos::ejecutar, this);
    }
}

void ControlHilos::detener() {
    if (hilo.joinable()) {
        hilo.join();
    }
}
