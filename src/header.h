//Desarrollamos la declaracion de las librerias y funciones a utilizar en el proyecto
//LIBRERIAS PARA EL PROYECTO
#ifndef HEADER_H // Guarda para evitar inclusiones múltiples
#define HEADER_H

#include <iostream>
#include <string>    //ya usada en clase que nos ayudara con cadenas de texto
#include <cstdlib>   //esta libreria nos ayudara con la generacion de numeros ramdom o utilidades ramdomizando ciertas cosas.
#include <vector>    //esta libreria es en funcion al tiempo, utilizda para poder inicializar el barajeo ramdoom
#include <windows.h> // Se incluye la librería windows.h para manipular la consola.
#include <ctime>     // esta libreria es en funcion al tiempo, utilizda para poder inicializar el barajeo ramdoom
#include <fstream>   //Libreria para los archivos donde se guardan las puntuaciones
#include <algorithm> // Librería para la función shuffle, para barajar de forma más eficiente.
#include <random>    // Librería para el random number generator.
#include <limits>    // Para std::numeric_limits en validación de entrada

using namespace std;
//FIN DE LAS LIBRERIAS

//DECLARACION DE CONSTANTES
//Determinamos unas constantes, para tener el numeros de cartas que usaremos en el juego.
const int MAX_PLAYERS = 4;        // Maximo de jugadores por partida.
const int CARDS_PER_PLAYER = 5;   // Maximo de cartas por cada jugador.
const int TOTAL_CARDS = 20;       // Maximo de cartas para la partida (4 jugadores * 5 cartas = 20).
//FIN DE LAS CONSTANTES.

//DECLARACION DE LAS FUNCIONES.
extern string deck[TOTAL_CARDS]; // Declaramos el mazo como extern

vector<string> getCardASCII(const string& card); // Funcion utilizada para el mostreo de cartas
void shuffleDeck(string deck[], int n); // Funcion para desarrollar las diferentes cartas para el mazo
void dealCards(string hands[MAX_PLAYERS][CARDS_PER_PLAYER], int numPlayers, string deck[]); // Funcion para repartir a la zar las cartas
void showHand(string hand[], int size); // Funcion que mostrara las mano a los usuarios
int countCard(string hand[], int size, string card); // Funcion que contara cuantas cartas tendra cada jugador
void removeCards(string hand[], int size, string card, int quantity); // Funcion que eliminara las cartas segun los turnos avancen.


void loadScoreboard();
void saveScore(const string& playerName);

// Nueva función de ayuda para la validación de entrada
int getValidInteger(const string& message);

//FIN DE LAS FUNCIONES.
#endif