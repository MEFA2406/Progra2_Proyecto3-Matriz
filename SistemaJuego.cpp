//
// Created by Manol on 10/31/2026.
//

#include "SistemaJuego.h"

#include <iostream>
#include <cstdlib>
#include <ctime>


SistemaJuego::SistemaJuego()
    : matriz(),
      jugador(nullptr),
      carnivoros(nullptr),
      cantidadCarnivoros(0),
      capacidadCarnivoros(10),
      gestorCarnivoros(nullptr) {

    inicializarJugador();
    inicializarCarnivoros();
    inicializarMapa();
}

SistemaJuego::~SistemaJuego() {
    detener();

    delete gestorCarnivoros;

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

    int cantidadCarnivoros = 4;
    carnivoros = new Carnivoro*[capacidadCarnivoros];

    for (int i = 0; i < capacidadCarnivoros; i++) {
        carnivoros[i] = nullptr;
    }

    for (int i=0;i<cantidadCarnivoros;i++) {
        agregarCarnivoro(1);
    }
}

void SistemaJuego::inicializarMapa() {
    int cantidadPlantas =12;
    int cantidadComidas = 8;
    int cantidadLoot = 2;

    for (int i=0; i<cantidadPlantas; i++) {
        poner(new Planta());
    }

    for (int i=0;i<cantidadComidas;i++) {
        poner(new Comida((rand() % 5),0,0));
    }

    for (int i=0;i<cantidadLoot;i++) {
        poner(new Loot(TipoLoot::CASCO));
        poner(new Loot(TipoLoot::BOTAS));
        poner(new Loot(TipoLoot::ARMADURA));
    }
}

bool SistemaJuego::colocarAleatorio(Entidad *entidad, int distanciaMinima) {
    int filaJugador = jugador->obtenerFila();
    int columnaJugador = jugador->obtenerColumna();

    for (int intento = 0; intento < 500; intento++) {

        int fila = rand() % matriz.getFilas();
        int columna = rand() % matriz.getColumnas();

        int dFila = fila - filaJugador;
        int dColumna = columna - columnaJugador;

        if (dFila < 0) dFila = -dFila;
        if (dColumna < 0) dColumna = -dColumna;

        if (dFila + dColumna < distanciaMinima) {
            continue;
        }

        if (matriz.setPosicion(fila, columna, entidad)) {
            return true;
        }
    }

    return false;
}


void SistemaJuego::poner(Entidad *entidad, int distanciaMinima) {
    if (!colocarAleatorio(entidad,distanciaMinima)) {
        delete entidad;
    }
}

int SistemaJuego::obtenerMovimientosJugador() const {
    std::lock_guard<std::mutex> bloqueo(mutexMatriz);

    return jugador->getMovimientos();
}

bool SistemaJuego::agregarCarnivoro(int nivel) {

    if (cantidadCarnivoros >= capacidadCarnivoros) {
        return false;
    }

    Carnivoro* nuevo = new Carnivoro(nivel,0,0);
    int distaciaJugador =3;

    if (!colocarAleatorio(nuevo,distaciaJugador)) {
        delete nuevo;
        return false;
    }
    carnivoros[cantidadCarnivoros] = nuevo;
    cantidadCarnivoros++;
    return true;
}

void SistemaJuego::aplicarEquipo(Personaje *nuevo) {
    matriz.reemplazar(jugador->obtenerFila(),jugador->obtenerColumna(),nuevo);
    jugador = nuevo;
}

void SistemaJuego::equiparCasco() {
    std::lock_guard<std::mutex> bloqueo(mutexMatriz);
    aplicarEquipo(new Casco(jugador));
}

void SistemaJuego::equiparBotas() {
    std::lock_guard<std::mutex> bloqueo(mutexMatriz);
    aplicarEquipo(new Botas(jugador));
}

void SistemaJuego::equiparArmadura() {
    std::lock_guard<std::mutex> bloqueo(mutexMatriz);
    aplicarEquipo(new Armadura(jugador));
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

ResultadoMovimiento SistemaJuego::moverJugador(
    int desplazamientoFila,
    int desplazamientoColumna
) {

    std::lock_guard<std::mutex> bloqueo(mutexMatriz);

    int filaActual = jugador->obtenerFila();
    int columnaActual = jugador->obtenerColumna();

    int nuevaFila = filaActual + desplazamientoFila;
    int nuevaColumna = columnaActual + desplazamientoColumna;

    if (!matriz.posicionValida(nuevaFila, nuevaColumna)) {
        return ResultadoMovimiento::INVALIDO;
    }

    ResultadoMovimiento resultado = ResultadoMovimiento::MOVIO;
    Entidad* destino = matriz.getPosicion(nuevaFila, nuevaColumna);

    if (destino!= nullptr) {
        if (dynamic_cast<Planta*>(destino)!= nullptr) {
            return ResultadoMovimiento::INVALIDO;
        }
        if (auto comida = dynamic_cast<Comida*>(destino)) {
            jugador->recuperarVida(comida->getValor());
            matriz.eliminar(nuevaFila,nuevaColumna);
            resultado = ResultadoMovimiento::COMIO;
        }
        else if (auto loot = dynamic_cast<Loot*>(destino)) {
            TipoLoot tipo = loot->getTipo();
            matriz.eliminar(nuevaFila,nuevaColumna);

            switch (tipo) {
                case TipoLoot::CASCO: aplicarEquipo(new Casco(jugador)); break;
                case TipoLoot::BOTAS: aplicarEquipo(new Botas(jugador)); break;
                case TipoLoot::ARMADURA: aplicarEquipo(new Armadura(jugador));break;
            }
            resultado = ResultadoMovimiento::EQUIPO;
        }
        else if (auto carnivoro = dynamic_cast<Carnivoro*>(destino)) {
            carnivoro->atacar(jugador);
            jugador->incrementarMovimientos();
            return ResultadoMovimiento::ATAQUE;
        }
        else {
            return ResultadoMovimiento::INVALIDO;
        }
    }

    matriz.mover(filaActual,columnaActual,nuevaFila,nuevaColumna);
    jugador->incrementarMovimientos();

    return resultado;
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