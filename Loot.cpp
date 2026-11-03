//
// Created by Manol on 10/31/2026.
//

#include "Loot.h"

Loot::Loot(TipoLoot tipo, int fila, int col) : Entidad(fila, col), tipo(tipo) {
}

TipoLoot Loot::getTipo() const {
    return tipo;
}

char Loot::obtenerSimbolo() const {
    switch (tipo) {
        case TipoLoot::CASCO:    return 'C';
        case TipoLoot::BOTAS:    return 'B';
        case TipoLoot::ARMADURA: return 'A';
    }
    return '?';
}