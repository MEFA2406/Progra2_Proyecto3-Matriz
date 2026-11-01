//
// Created by Manol on 10/31/2026.
//

#include "Jugador.h"
#include <sstream>

Jugador::Jugador(int fila,int columna) : Personaje(fila,columna){
    vida =20;
    movimientos =0;
}

int Jugador::getMovimientos() const {
    return movimientos;
}

void Jugador::recuperarVida(int cantidad) {
    vida += cantidad;
}

void Jugador::incrementarMovimientos() {
    movimientos++;
}

char Jugador::obtenerSimbolo() const {
    return 'J';
}

int Jugador::getVida() const {
    return vida;
}

int Jugador::getProteccion() const {
    return 0;
}

void Jugador::recibirAtaque(int ataque) {
    vida -= ataque;
    if (vida < 0) {
        vida = 0;
    }
}
