//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_JUGADOR_H
#define PROYECTO3_MATRIZ_JUGADOR_H
#include <string>
#include "Personaje.h"

class Jugador : public Personaje{
private:
    int movimientos;
    int vida;
public:
    Jugador(int fila,int columna);

    int getVida() const override;

    int getProteccion() const override;

    int getMovimientos() const override;

    void recuperarVida( int cantidad) override;

    void recibirAtaque(int ataque) override;

    void incrementarMovimientos() override;

    char obtenerSimbolo() const override;

};


#endif //PROYECTO3_MATRIZ_JUGADOR_H