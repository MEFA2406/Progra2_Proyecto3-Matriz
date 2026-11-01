cmake_minimum_required(VERSION 4.1)
project(Proyecto3_Matriz)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto3_Matriz main.cpp
        Jugador.cpp
        Jugador.h
        Personaje.h
        Personaje.cpp
        Equipamiento.cpp
        Equipamiento.h
        Casco.cpp
        Casco.h
        Armadura.cpp
        Armadura.h
        Botas.cpp
        Botas.h
        Carnivoro.cpp
        Carnivoro.h
        Comida.cpp
        Comida.h
        Entidad.cpp
        Entidad.h
        Loot.cpp
        Loot.h
        GestorCarnivoros.cpp
        GestorCarnivoros.h
        Matriz.cpp
        Matriz.h)
