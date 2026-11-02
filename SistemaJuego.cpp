//
// Created by Manol on 10/31/2026.
//

#include "SistemaJuego.h"

#include <iostream>

SistemaJuego::SistemaJuego()
    : matriz(),
      jugador(nullptr),
      carnivoros(nullptr),
      cantidadCarnivoros(0),
      capacidadCarnivoros(10),
      gestorCarnivoros(nullptr) {

    inicializarJugador();
    inicializarCarnivoros();
}

SistemaJuego::~SistemaJuego() {

    // Primero detener el hilo.
    detener();

    delete gestorCarnivoros;

    // La cadena de Decorators libera al jugador original.
    delete jugador;

    // Liberar los carnívoros.
    for (int i = 0; i < cantidadCarnivoros; i++) {
        delete carnivoros[i];
    }

    delete[] carnivoros;
}

void SistemaJuego::inicializarJugador() {

    jugador = new Jugador(7, 7);

    matriz.setPosicion(
        jugador->obtenerFila(),
        jugador->obtenerColumna(),
        jugador
    );
}

void SistemaJuego::inicializarCarnivoros() {

    carnivoros = new Carnivoro*[capacidadCarnivoros];

    for (int i = 0; i < capacidadCarnivoros; i++) {
        carnivoros[i] = nullptr;
    }

    agregarCarnivoro(new Carnivoro(3, 4, 1));
    agregarCarnivoro(new Carnivoro(10, 5, 2));
}

bool SistemaJuego::agregarCarnivoro(Carnivoro* carnivoro) {

    if (cantidadCarnivoros >= capacidadCarnivoros ||
        carnivoro == nullptr) {
        return false;
        }

    bool colocado = matriz.setPosicion(
        carnivoro->obtenerFila(),
        carnivoro->obtenerColumna(),
        carnivoro
    );

    if (!colocado) {
        return false;
    }

    carnivoros[cantidadCarnivoros] = carnivoro;
    cantidadCarnivoros++;

    return true;
}

void SistemaJuego::iniciar() {

    if (gestorCarnivoros == nullptr) {

        gestorCarnivoros = new GestorCarnivoros(
            carnivoros,
            cantidadCarnivoros,
            &matriz,
            mutexMatriz
        );
    }

    gestorCarnivoros->iniciar();
}

void SistemaJuego::detener() {

    if (gestorCarnivoros != nullptr) {
        gestorCarnivoros->detener();
    }
}

bool SistemaJuego::moverJugador(
    int desplazamientoFila,
    int desplazamientoColumna
) {

    std::lock_guard<std::mutex> bloqueo(mutexMatriz);

    int filaActual = jugador->obtenerFila();
    int columnaActual = jugador->obtenerColumna();

    int nuevaFila = filaActual + desplazamientoFila;
    int nuevaColumna = columnaActual + desplazamientoColumna;

    if (!matriz.posicionValida(nuevaFila, nuevaColumna)) {
        return false;
    }

    if (matriz.getPosicion(nuevaFila, nuevaColumna) != nullptr) {
        return false;
    }

    matriz.eliminar(filaActual, columnaActual);

    jugador->cambiarPosicion(nuevaFila, nuevaColumna);

    matriz.setPosicion(nuevaFila, nuevaColumna, jugador);

    return true;
}

std::string SistemaJuego::obtenerMapa() {

    std::lock_guard<std::mutex> bloqueo(mutexMatriz);

    return matriz.mostrar();
}

int SistemaJuego::obtenerVidaJugador() const {

    std::lock_guard<std::mutex> bloqueo(mutexMatriz);

    return jugador->getVida();
}

int SistemaJuego::obtenerProteccionJugador() const {

    std::lock_guard<std::mutex> bloqueo(mutexMatriz);

    return jugador->getProteccion();
}