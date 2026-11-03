//
// Created by Manol on 10/31/2026.
//

#ifndef SISTEMAJUEGO_H
#define SISTEMAJUEGO_H

#include <mutex>
#include <string>

#include "Matriz.h"
#include "Jugador.h"
#include "Carnivoro.h"
#include "Casco.h"
#include "Armadura.h"
#include "Botas.h"
#include "GestorCarnivoros.h"

class SistemaJuego {
private:
    Matriz matriz;

    Personaje* jugador;

    Carnivoro** carnivoros;
    int cantidadCarnivoros;
    int capacidadCarnivoros;

    mutable std::mutex mutexMatriz;

    GestorCarnivoros* gestorCarnivoros;

    void inicializarJugador();
    void inicializarCarnivoros();

    bool agregarCarnivoro(Carnivoro* carnivoro);
    void aplicarEquipo(Personaje* nuevo);

public:
    SistemaJuego();
    ~SistemaJuego();

    void iniciar();
    void detener();

    bool moverJugador(int desplazamientoFila,
                      int desplazamientoColumna);

    void equiparCasco();
    void equiparBotas();
    void equiparArmadura();

    std::string obtenerMapa();

    int obtenerVidaJugador() const;
    int obtenerProteccionJugador() const;
};

#endif // SISTEMAJUEGO_H