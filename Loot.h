//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_LOOT_H
#define PROYECTO3_MATRIZ_LOOT_H
#include <string>

#include "Entidad.h"

enum class TipoLoot{CASCO,BOTAS,ARMADURA};


class Loot : public Entidad{
private:
    TipoLoot tipo;
public:
    Loot(TipoLoot tipo,int fila=0,int col=0);

    TipoLoot getTipo() const;

    char obtenerSimbolo() const override;
};



#endif //PROYECTO3_MATRIZ_LOOT_H
