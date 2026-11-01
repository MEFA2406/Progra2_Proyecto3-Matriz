//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_CARNIVORO_H
#define PROYECTO3_MATRIZ_CARNIVORO_H

#include "Entidad.h"
#include "Personaje.h"

class Carnivoro : public Entidad {
private:
    int nivel;
public:
    Carnivoro(int nivel, int fila, int columna);

    void setNivel(int nivel);
    int getNivel() const;

    int getAtaque() const;

    void atacar(Personaje* objetivo);

    char obtenerSimbolo() const override;
};


#endif //PROYECTO3_MATRIZ_CARNIVORO_H