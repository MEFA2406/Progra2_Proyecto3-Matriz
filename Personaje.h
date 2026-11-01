//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_PERSONAJE_H
#define PROYECTO3_MATRIZ_PERSONAJE_H
#include "Entidad.h"


class Personaje : public Entidad {
public:
    Personaje(int fila,int columna);
    virtual ~Personaje() = default;

    virtual int getVida() const =0;
    virtual int getProteccion() const =0;
    virtual int getMovimientos() const =0;

    virtual void recibirAtaque(int ataque) = 0;
    virtual void recuperarVida(int cantidad) =0;
    virtual void incrementarMovimientos() =0;
};



#endif //PROYECTO3_MATRIZ_PERSONAJE_H
