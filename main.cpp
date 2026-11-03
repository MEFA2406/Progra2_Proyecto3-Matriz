#include <iostream>
#include "SistemaJuego.h"

using namespace std;

int main() {
    srand(time(nullptr));

    SistemaJuego juego;
    juego.iniciar();
    char tecla;

    while (juego.obtenerVidaJugador() > 0) {
        cout<<juego.obtenerMapa();
        cout<<"Vida: " << juego.obtenerVidaJugador()
            <<" Proteccion: "<< juego.obtenerProteccionJugador()
            <<" Movimientos: "<<juego.obtenerMovimientosJugador()<<endl;
        cout<<"Mover (W/A/S/D , Q para salir: ";
        cin>>tecla;
        int df=0,dc=0; // desplazamientoFila, desplazamientoColumna
        switch (tecla) {
            case 'w': df=-1; break;
            case 's': df=1; break;
            case 'a': dc=-1; break;
            case 'd': dc=1; break;
            case 'q': return 0;
            default: cout<<"Tecla no valida\n";continue;
        }

        switch (juego.moverJugador(df,dc)) {
            case ResultadoMovimiento::INVALIDO: cout<<"Invalido"; break;
            case  ResultadoMovimiento::COMIO: cout<<"Comio y recupero vida";break;
            case  ResultadoMovimiento::EQUIPO: cout<<"Recogio equipamiento";break;
            case  ResultadoMovimiento::ATAQUE: cout<<"Un carnivoro te ataco";break;
            case  ResultadoMovimiento::MOVIO: break;
        }
    }

    cout<<juego.obtenerMapa() << "Has muerto. Fin del juego\n";
    return 0;
}