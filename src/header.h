                            //Desarrollamos la declaracion de las librerias y funciones a utilizar en el proyecto
                                                //LIBRERIAS PARA EL PROYECTO
//investigando encontre para facilitarnos el uso de ciertas librerias
#ifndef HEADER_H  // Guarda para evitar inclusiones múltiples
#define HEADER_H
#include <iostream>
#include <string> //ya usada en clase que nos ayudara con cadenas de texto
#include <cstdlib> //esta libreria nos ayudara con la generacion de numeros ramdom o utilidades ramdomizando ciertas cosas.
#include <vector> //esta libreria es en funcion al tiempo, utilizda para poder inicializar el barajeo ramdoom
#include <windows.h> // Se incluye la librería windows.h para manipular la consola.
#include <ctime> // esta libreria es en funcion al tiempo, utilizda para poder inicializar el barajeo ramdoom
#include <fstream> //Libreria para los archivos donde se guardan las puntuaciones
#include <algorithm> // Librería para la función shuffle, para barajar de forma más eficiente.
#include <random> // Librería para el random number generator.
using namespace std;
                                                //FIN DE LAS LIBRERIAS

                                                //DECLARACION DE CONSTANTES
                //Determinamos unas constantes, para tener el numeros de cartas que usaremos en el juego. 
const int MAX_JUGADORES = 4; //Maximo de jugadores por partida.
const int CARTAS_POR_JUGADOR = 5; //Maximo de cartas por cada jugador.
const int TOTAL_CARTAS = 16; //Maximo de cartas para la partida.
                                                //FIN DE LAS CONSTANTES.

                                                //DECLARACION DE LAS FUNCIONES.
extern string mazo[TOTAL_CARTAS];
void mostrarCartaASCII(const string& carta); //Funcion utilizada para el mostreo de cartas
void barajarMazo(string m[], int n); //Funcion para desarrollar las diferentes cartas para el mazo
void repartirCartas(string manos[MAX_JUGADORES][CARTAS_POR_JUGADOR], int numJugadores, string m[]); //Funcion para repartir a la zar las cartas
void mostrarMano(string mano[], int tam); //Funcion que mostrara las mano a los usuarios
int contarCarta(string mano[], int tam, string carta); //Funcion que contara cuantas cartas tendra cada jugador
void eliminarCartas(string mano[], int tam, string carta, int cantidad); //Funcion que eliminara las cartas segun los turnos avancen.
void cargar_tabla_de_puntos();
void guardar_puntuacion(const string& nombre_jugador);

                                                    //FIN DE LAS FUNCIONES.
#endif
