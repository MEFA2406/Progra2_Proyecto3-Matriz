//
// Created by Manol on 10/31/2026.
//

#ifndef PROYECTO3_MATRIZ_ENTIDAD_H
#define PROYECTO3_MATRIZ_ENTIDAD_H


class Entidad {
protected:
    int fila;
    int columna;
public:
    Entidad(int fila=0,int columna=0);
    virtual ~Entidad() = default;

    int obtenerFila() const;
    int obtenerColumna() const;

    void cambiarPosicion(int fila,int columna);

    virtual char obtenerSimbolo() const =0;

};


#endif //PROYECTO3_MATRIZ_ENTIDAD_H