//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_MATRIZ_H
#define PROYECTO3_MATRIZ_MATRIZ_H
#include <string>

#include "Entidad.h"


class Matriz {
private:
    Entidad*** matriz;
    int filas;
    int columnas;
    void inicializar();
public:
    Matriz();
    virtual ~Matriz();

    bool posicionValida(int x,int y) const;

    Entidad* getPosicion(int x,int y);
    bool setPosicion(int x,int y,Entidad* entidad);

    void eliminar(int x,int y);

    std::string  mostrar() const;
};


#endif //PROYECTO3_MATRIZ_MATRIZ_H