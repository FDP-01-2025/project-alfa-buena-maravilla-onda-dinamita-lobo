//Declaracion de librerias
#ifndef HEADER_H  // Guarda para evitar inclusiones múltiples
#define HEADER_H
#include <iostream>
//ya usada en clase que nos ayudara con cadenas de texto 
#include <string>
//esta libreria nos ayudara con la generación de números random o utilidades randomizando ciertas cosas.
#include <cstdlib>
//esta libreria es en función al tiempo, utilizada para poder inicializar el barajeo random, la idea es que haga que
//cada barajeo sea diferente
#include <ctime>
//Fin declaración de librerías
using namespace std;

//determinamos unas constantes, para tener el número de cartas 
const int MAX_PLAYERS = 4;
const int CARDS_PER_PLAYER = 5;
const int TOTAL_CARDS = 16;

//Declaración de funciones
extern string deck[TOTAL_CARDS];
void showCardASCII(const string& card);
void shuffleDeck(string d[], int n);
void dealCards(string hands[MAX_PLAYERS][CARDS_PER_PLAYER], int numPlayers, string d[]);
void showHand(string hand[], int size);
int countCard(string hand[], int size, string card);
void removeCards(string hand[], int size, string card, int quantity);

//Fin declaración de funciones
#endif
