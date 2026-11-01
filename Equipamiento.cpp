//
// Created by Manol on 10/31/2026.
//

#include "Equipamiento.h"

Equipamiento::Equipamiento(Personaje *personaje, int proteccion) : proteccion(proteccion),
Personaje(personaje->obtenerFila(), personaje->obtenerColumna()){
    this->personaje = personaje;
}

Equipamiento::~Equipamiento() {
    delete personaje;
}

int Equipamiento::getVida() const {
    return personaje->getVida();
}

int Equipamiento::getProteccion() const {
    return proteccion + personaje->getProteccion();
}

int Equipamiento::getMovimientos() const {
    return personaje->getMovimientos();
}

void Equipamiento::recuperarVida(int cantidad) {
    personaje->recuperarVida(cantidad);
}

void Equipamiento::incrementarMovimientos() {
    personaje->incrementarMovimientos();
}

int Equipamiento::obtenerFila() const {
    return personaje->obtenerFila();
}

int Equipamiento::obtenerColumna() const {
    return personaje->obtenerColumna();
}

void Equipamiento::cambiarPosicion(int fila, int columna) {
    personaje->cambiarPosicion(fila, columna);
}

char Equipamiento::obtenerSimbolo() const {
    return personaje->obtenerSimbolo();
}

void Equipamiento::recibirAtaque(int ataque) {
    int absorbido = ataque < proteccion ? ataque: proteccion;
    ataque -= absorbido;
    proteccion -= absorbido;

    if (ataque > 0) {
        personaje->recibirAtaque(ataque);
    }
}
