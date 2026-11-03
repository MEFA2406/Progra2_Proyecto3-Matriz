//
// Created by Manol on 10/31/2026.
//

#include "GestorCarnivoros.h"
#include <chrono>
#include <cstdlib>

void GestorCarnivoros::ejecutar() {
    while (activo) {
        {
            std::lock_guard<std::mutex> bloqueo(mutexMatriz);
            moverCarnivoros();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

void GestorCarnivoros::moverCarnivoros() {
    int movimientosFila[4] = {-1,1,0,0};
    int movimientosColumna[4] = {0,0,-1,1};

    for (int i = 0; i < cantidad; i++) {
        Carnivoro* carnivoro = carnivoros[i];

        int filaActual = carnivoro->obtenerFila();
        int columnaActual = carnivoro->obtenerColumna();

        int direccion = std::rand() % 4;

        int nuevaFila = filaActual + movimientosFila[direccion];
        int nuevaColumna = columnaActual + movimientosColumna[direccion];

        if (!matriz->posicionValida(nuevaFila, nuevaColumna)) {
            continue;
        }

        Entidad* destino = matriz->getPosicion(nuevaFila, nuevaColumna);

        if (destino == nullptr) {
            matriz->mover(filaActual,columnaActual,nuevaFila,nuevaColumna);
        }
        else {
            Personaje* personaje = dynamic_cast<Personaje*>(destino);
            if (personaje != nullptr) {
                personaje->recibirAtaque(carnivoro->getAtaque());
            }
        }
    }
}

GestorCarnivoros::GestorCarnivoros(Carnivoro **carnivoros, int cantidad, Matriz *matriz, std::mutex &mutexMatriz)
    :carnivoros(carnivoros), cantidad(cantidad), matriz(matriz), mutexMatriz(mutexMatriz), activo(false){
}

GestorCarnivoros::~GestorCarnivoros() {
    detener();
}

void GestorCarnivoros::iniciar() {
    if (!activo.exchange(true)) {
        hilo = std::thread(&GestorCarnivoros::ejecutar, this);
    }
}

void GestorCarnivoros::detener() {
    activo = false;
    if (hilo.joinable()) {
        hilo.join();
    }
}
