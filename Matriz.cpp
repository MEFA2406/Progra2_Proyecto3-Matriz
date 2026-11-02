//
// Created by Manol on 10/31/2026.
//

#include "Matriz.h"

#include <iomanip>
#include <sstream>

void Matriz::inicializar() {
    matriz = new Entidad**[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new Entidad*[columnas];
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = nullptr;
        }
    }
}

Matriz::Matriz() {
    filas =15;
    columnas =15;
    inicializar();
}

Matriz::~Matriz() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            delete matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}

bool Matriz::posicionValida(int x, int y) const {
    return x >= 0 && x < filas && y >= 0 && y < columnas;
}

Entidad * Matriz::getPosicion(int x, int y) {
    if (!posicionValida(x, y)) {
        return nullptr;
    }
    return matriz[x][y];
}

bool Matriz::setPosicion(int x, int y, Entidad *entidad) {
    if (!posicionValida(x, y)) {
        return false;
    }
    if (matriz[x][y] != nullptr) {
        return false;
    }
    matriz[x][y] = entidad;
    return true;
}

void Matriz::eliminar(int x, int y) {
    if (!posicionValida(x, y)) {
        return;
    }
    matriz[x][y] = nullptr;
}

std::string Matriz::mostrar() const {
    std::stringstream ss;
    ss << "      ";
    for (int j = 0; j < 15; j++) {
        ss << std::setw(2) << std::setfill('0') << j << "   ";
    }

    ss << std::endl << std::setfill(' ');

    // Borde superior
    ss << "    +";
    for (int j = 0; j < 15; j++) {
        ss << "----+";
    }
    ss << std::endl;

    // Contenido de la matriz
    for (int i = 0; i < 15; i++) {

        ss << std::setw(2) << std::setfill('0') << i << "  ";
        ss << std::setfill(' ');

        for (int j = 0; j < 15; j++) {

            if (matriz[i][j] == nullptr) {
                ss << "|    ";
            }
            else {
                ss << "| " << matriz[i][j]->obtenerSimbolo() << "  ";
            }
        }

        ss << "|" << std::endl;

        // Separación entre filas
        ss << "    +";
        for (int j = 0; j < 15; j++) {
            ss << "----+";
        }
        ss << std::endl;
    }
    return ss.str();
}
