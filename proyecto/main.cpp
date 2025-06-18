/*Desarrollaremos un juego, llamado la mesa de los mentirosos, este juego puede ser de 2-4 jugadores los cuales se les 
repartiran 5 cartas a cada uno de ellos, en el mazo pueden haber reyes reinas, As y un solo joacker, repartidas las cartas
de manera aleatoria, la mesa (o un jugador siguiendo un orden), reclamaran a la mesa una carta (sea rey, reina, As o joacker), y todos tendran
que entregar cartas sea 1-2-3, pero no 4 ni 5, una vez tiradas los jugadores podran decidir si creerle a el jugador o dudar y declararlo
MENTIROSO, si el que tiro tiene cartas de las que se reclamaron, el reclamador queda como mentiroso y pierde, asi de manera contraria
si el tirador no tiene cartas de las que se reclamo y tiro, queda como mentiroso y pierde, luego se regresaran las cartas se volveran a 
barajear y se repartiran, sin el jugador que perdio esta vez, este teniendo que cumplir un castigo o reto. */
#include <iostream>
#include "proyecto.h"
using namespace std;

int main() {
    // genera la baraja completa y la mezcla
    std::vector<Carta> baraja = generarBaraja();
    barajear(baraja);

    std::vector<Jugador> jugadores;
    int cantidadJugadores = 0;

    // Pedir la cantidad de jugadores
    std::cout << "Ingrese la cantidad de jugadores (2 a 4): ";
    std::cin >> cantidadJugadores;

    // validacion para que no se asigne un numero que no está entre 2 y 4
    if (cantidadJugadores < 2 || cantidadJugadores > 4) {
        std::cout << "Cantidad inválida.\n";
        return 1; // Terminar el juego si el numero no es correcto
    }

    // Crear jugadores y repartir cartas
    inicializarJugadores(jugadores, cantidadJugadores);
    repartirCartas(jugadores, baraja);

    // Mostrar la mano de cada jugador en pantalla
    for (const auto& jugador : jugadores) {
        mostrarMano(jugador);
    }

    // hasta aqui he llegafo, falta implementar la lógica de juego por turnos y acusaciones

    return 0;
}