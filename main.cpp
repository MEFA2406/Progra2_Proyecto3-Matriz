#include <iostream>
#include "SistemaJuego.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// main TEMPORAL para probar la mecanica a mano (w/a/s/d).
// Cada movimiento valido lanza un turno de los 4 hilos antes de redibujar.
int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    SistemaJuego juego;
    juego.iniciar();   // arranca los 4 hilos
    char tecla;

    while (juego.obtenerVidaJugador() > 0) {
        cout << juego.obtenerMapa();
        cout << "Vida: " << juego.obtenerVidaJugador()
             << "  Proteccion: " << juego.obtenerProteccionJugador()
             << "  Movimientos: " << juego.obtenerMovimientosJugador() << endl;
        cout << "Mover (w/a/s/d, q para salir): ";
        cin >> tecla;

        int df = 0, dc = 0;
        switch (tecla) {
            case 'w': df = -1; break;
            case 's': df = 1;  break;
            case 'a': dc = -1; break;
            case 'd': dc = 1;  break;
            case 'q': return 0;
            default: cout << "Tecla no valida\n"; continue;
        }

        switch (juego.ejecutarTurno(df, dc)) {
            case ResultadoMovimiento::INVALIDO: cout << "Movimiento invalido\n"; break;
            case ResultadoMovimiento::COMIO:    cout << "Comiste: recuperaste vida\n"; break;
            case ResultadoMovimiento::EQUIPO:   cout << "Recogiste equipamiento\n"; break;
            case ResultadoMovimiento::ATAQUE:  cout << "Un carnivoro te ataco!\n"; break;
            case ResultadoMovimiento::MOVIO:    break;
        }
    }

    cout << juego.obtenerMapa() << "Has muerto. Fin del juego.\n";
    return 0;
}