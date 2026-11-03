#include "GestorCarnivoros.h"

#include "Personaje.h"
GestorCarnivoros::GestorCarnivoros(Matriz *matriz, std::mutex &mutexMatriz, ControlTurnos &controlTurnos) : ControlHilos(matriz, mutexMatriz, controlTurnos) {
}

void GestorCarnivoros::actualizar() {
    const int dFila[4] = {-1, 1, 0, 0};
    const int dColumna[4] = {0, 0, -1, 1};

    auto lista = new Carnivoro*[matriz->getFilas() * matriz->getColumnas()];
    int cantidad = recolectar(lista);

    for (int i = 0; i < cantidad; i++) {
        Carnivoro* carnivoro = lista[i];

        int direccion = rand() % 4;
        int nuevaFila = carnivoro->obtenerFila() + dFila[direccion];
        int nuevaColumna = carnivoro->obtenerColumna() + dColumna[direccion];

        if (!matriz->posicionValida(nuevaFila, nuevaColumna)) {
            continue;
        }

        Entidad* destino = matriz->getPosicion(nuevaFila, nuevaColumna);

        if (destino == nullptr) {
            matriz->mover(carnivoro->obtenerFila(), carnivoro->obtenerColumna(),
                          nuevaFila, nuevaColumna);
        }
        else if (auto personaje = dynamic_cast<Personaje*>(destino)) {
            carnivoro->atacar(personaje);
        }
    }

    delete[] lista;
}


