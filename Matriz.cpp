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

int Matriz::getFilas() const {
    return filas;
}

int Matriz::getColumnas() const {
    return columnas;
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
    entidad->cambiarPosicion(x,y);
    return true;
}

bool Matriz::mover(int origenX, int origenY, int destinoX, int destinoY) {
    if (!posicionValida(origenX, origenY) || !posicionValida(destinoX, destinoY)) {
        return false;
    }
    Entidad* entidad = matriz[origenX][origenY];
    if (entidad == nullptr || matriz[destinoX][destinoY] != nullptr) {
        return false;
    }
    matriz[destinoX][destinoY] = entidad;
    matriz[origenX][origenY] = nullptr;
    entidad->cambiarPosicion(destinoX, destinoY);
    return true;
}

bool Matriz::reemplazar(int x, int y, Entidad *nueva) {
    if (nueva == nullptr || !posicionValida(x, y) || matriz[x][y] == nullptr) {
        return false;
    }
    matriz[x][y] = nueva;
    return true;
}

Entidad * Matriz::quitar(int x, int y) {
    if (!posicionValida(x, y)) {
        return nullptr;
    }
    Entidad* entidad = matriz[x][y];
    matriz[x][y] = nullptr;
    return entidad;
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
    for (int j = 0; j < columnas; j++) {
        ss << std::setw(2) << std::setfill('0') << j << "   ";
    }

    ss << std::endl << std::setfill(' ');

    // Borde superior
    ss << "    +";
    for (int j = 0; j < columnas; j++) {
        ss << "----+";
    }
    ss << std::endl;

    // Contenido de la matriz
    for (int i = 0; i < filas; i++) {

        ss << std::setw(2) << std::setfill('0') << i << "  ";
        ss << std::setfill(' ');

        for (int j = 0; j < columnas; j++) {

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
        for (int j = 0; j < columnas; j++) {
            ss << "----+";
        }
        ss << std::endl;
    }
    return ss.str();
}
