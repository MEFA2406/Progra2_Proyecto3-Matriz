//
// Created by Manol on 11/2/2026.
//

#ifndef PROYECTO3_MATRIZ_PLANTA_H
#define PROYECTO3_MATRIZ_PLANTA_H
#include "Entidad.h"


class Planta : public Entidad{
public:
    Planta(int fila=0,int col=0);
    char obtenerSimbolo() const override;
};


#endif //PROYECTO3_MATRIZ_PLANTA_H