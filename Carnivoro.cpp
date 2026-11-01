//
// Created by Manol on 10/31/2026.
//

#include "Carnivoro.h"

Carnivoro::Carnivoro(int nivel,int fila,int columna) :nivel(nivel), Entidad(fila,columna) {
}

void Carnivoro::setNivel(int nivel) {
    this->nivel = nivel;
}

int Carnivoro::getNivel() const {
    return this->nivel;
}

int Carnivoro::getAtaque() const {
    return nivel*5;
}

void Carnivoro::atacar(Personaje *objetivo) {
    objetivo->recibirAtaque(getAtaque());
}

char Carnivoro::obtenerSimbolo() const {
    return 'E';
}
