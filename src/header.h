                        //Declaracion de librerias
#ifndef HEADER_H  // Guarda para evitar inclusiones múltiples
#define HEADER_H
#include <iostream>
//ya usada en clase que nos ayudara con cadenas de texto 
#include <string>
//esta libreria nos ayudara con la generacion de numeros ramdom o utilidades ramdomizando ciertas cosas.
#include <cstdlib>
//esta libreria es en funcion al tiempo, utilizda para poder inicializar el barajeo ramdoom, la idea es que haga que
//cada barajeo sea diferente
#include <ctime>
                        //Fin declaracion de librerias
using namespace std;

//determinamos unas constantes, para tener el numeros de cartas 
const int MAX_JUGADORES = 4;
const int CARTAS_POR_JUGADOR = 5;
const int TOTAL_CARTAS = 16;

//Declaracion de funciones
extern string mazo[TOTAL_CARTAS];
void mostrarCartaASCII(const string& carta);
void barajarMazo(string m[], int n);
void repartirCartas(string manos[MAX_JUGADORES][CARTAS_POR_JUGADOR], int numJugadores, string m[]);
void mostrarMano(string mano[], int tam);
int contarCarta(string mano[], int tam, string carta);
void eliminarCartas(string mano[], int tam, string carta, int cantidad);

//Fin declaracion de funciones
#endif