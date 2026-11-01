//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_COMIDA_H
#define PROYECTO3_MATRIZ_COMIDA_H
#include "Entidad.h"


class Comida : public Entidad {
private:
    int valor;
public:
    Comida(int valor,int fila,int columna);
    int getValor() const;

    char obtenerSimbolo() const override;
};


#endif //PROYECTO3_MATRIZ_COMIDA_H