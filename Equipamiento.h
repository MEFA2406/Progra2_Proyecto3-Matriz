//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_EQUIPAMIENTO_H
#define PROYECTO3_MATRIZ_EQUIPAMIENTO_H
#include "Personaje.h"


class Equipamiento : public Personaje{
protected:
    Personaje* personaje;
    int proteccion;
public:
    Equipamiento(Personaje* personaje, int proteccion);
    virtual ~Equipamiento();

    int getVida() const override;
    int getProteccion() const override;
    int getMovimientos() const override;

    void recibirAtaque(int ataque) override;
    void recuperarVida(int cantidad) override;
    void incrementarMovimientos() override;

    int obtenerFila() const;
    int obtenerColumna() const;
    void cambiarPosicion(int fila,int columna);
    char obtenerSimbolo() const override;

};


#endif //PROYECTO3_MATRIZ_EQUIPAMIENTO_H