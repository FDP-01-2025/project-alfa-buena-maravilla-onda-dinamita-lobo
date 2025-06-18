#include "proyecto.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

// Generar una baraja con 4 Reyes, 4 Reinas, 4 Ases y 1 Joker (como en una baraja normal)
std::vector<Carta> generarBaraja() {
    std::vector<Carta> baraja;

    for (int i = 0; i < 4; ++i) { //dejamos al joker fuera del bucle para posteriormente añadir solo 1
        baraja.push_back({"Rey"}); //usando push_back para incorporar el valor al ultimo espacio en el array 
        baraja.push_back({"Reina"});
        baraja.push_back({"As"});
    }

    //agregar un solo Joker
    baraja.push_back({"Joker"});

    return baraja;
}

// Barajear las cartas al azar usando la hora actual como semilla
void barajear(std::vector<Carta>& baraja) {
    std::srand(std::time(0)); // Semilla aleatoria basada en la hora actual
    std::random_shuffle(baraja.begin(), baraja.end()); // Mezcla las cartas
}

// repartir 5 cartas a cada jugador desde la baraja
void repartirCartas(std::vector<Jugador>& jugadores, std::vector<Carta>& baraja) {
    int cartasPorJugador = 5;
    for (int i = 0; i < jugadores.size(); ++i) {
        jugadores[i].mano.clear(); // Quitar la mano annterior si existe
        for (int j = 0; j < cartasPorJugador; ++j) {
            if (!baraja.empty()) {
                jugadores[i].mano.push_back(baraja.back()); // da una carta
                baraja.pop_back(); // La quita del mazo
            }
        }
    }
}

// Mostrar las cartas que tiene el jugador
void mostrarMano(const Jugador& jugador) {
    std::cout << jugador.nombre << " tiene: ";
    for (const auto& carta : jugador.mano) {
        std::cout << carta.nombre << " ";
    }
    std::cout << std::endl;
}

// Inicializar a los jugadores y asignarles un nombre
void inicializarJugadores(std::vector<Jugador>& jugadores, int cantidad) {
    jugadores.clear(); // Limpia jugadores previos
    for (int i = 0; i < cantidad; ++i) {
        Jugador nuevoJugador;
        nuevoJugador.nombre = "Jugador " + std::to_string(i + 1);
        jugadores.push_back(nuevoJugador);
    }
}
