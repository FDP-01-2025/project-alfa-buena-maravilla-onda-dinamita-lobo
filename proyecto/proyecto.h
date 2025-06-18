#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <string>
//Este archivo solo declara las estructuras y sus funciones, para ver como funcionan ir a proyecto.cpp

// Estructura para representar una carta
struct Carta {
    std::string nombre;
};

// Estructura para el jugador
struct Jugador {
    std::string nombre;           // nombre del jugador
    std::vector<Carta> mano;      // Mano de cartas
};

// crear la baraja inicial
std::vector<Carta> generarBaraja();

// barajear las cartas
void barajear(std::vector<Carta>& baraja);

// Repartir 5 cartas a los jugadores
void repartirCartas(std::vector<Jugador>& jugadores, std::vector<Carta>& baraja);

// Mostrar la mano
void mostrarMano(const Jugador& jugador);

// Inicializar la lista de jugadores
void inicializarJugadores(std::vector<Jugador>& jugadores, int cantidad);

#endif
