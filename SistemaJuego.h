//
// Created by Manol on 10/31/2026.
//

#ifndef SISTEMAJUEGO_H
#define SISTEMAJUEGO_H

#include <mutex>
#include <string>

#include "Matriz.h"
#include "Jugador.h"
#include "Comida.h"
#include "Carnivoro.h"
#include "Casco.h"
#include "Armadura.h"
#include "Botas.h"
#include "Planta.h"
#include "Loot.h"
#include "GestorCarnivoros.h"

enum class ResultadoMovimiento {
    INVALIDO,
    MOVIO,
    COMIO,
    EQUIPO,
    ATAQUE
};

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
    void inicializarMapa();

    bool agregarCarnivoro(int nivel);
    void aplicarEquipo(Personaje* nuevo); // agrega un decorator

    bool colocarAleatorio(Entidad* entidad, int distanciaMinima);
    void poner(Entidad* entidad, int distanciaMinima =0);

public:
    SistemaJuego();
    ~SistemaJuego();

    void iniciar();
    void detener();

    ResultadoMovimiento moverJugador(int desplazamientoFila,
                      int desplazamientoColumna);

    void equiparCasco();
    void equiparBotas();
    void equiparArmadura();

    std::string obtenerMapa();

    int obtenerVidaJugador() const;
    int obtenerProteccionJugador() const;
    int obtenerMovimientosJugador() const;

};

#endif // SISTEMAJUEGO_H