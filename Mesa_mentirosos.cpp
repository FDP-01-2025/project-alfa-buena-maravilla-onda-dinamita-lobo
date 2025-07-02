/*Desarrollaremos un juego, llamado la mesa de los mentirosos, este juego puede
ser de 2-4 jugadores los cuales se les repartiran 5 cartas a cada uno de ellos,
en el mazo pueden haber reyes reinas, As y un solo joacker, repartidas las cartas 
de manera aleatoria, la mesa (o un jugador siguiendo un orden), reclamaran a la
mesa una carta (sea rey, reina, As o joacker), y todos tendran que entregar 
cartas sea 1-2-3, pero no 4 ni 5, una vez tiradas los jugadores podran decidir
si creerle a el jugador o dudar y declararlo MENTIROSO, si el que tiro tiene
cartas de las que se reclamaron, el reclamador queda como emntiroso y pierde, 
asi de manera contraria si el tirador no tiene cartas de las que se reclamo y
tiro, queda como mentiroso y pierde, luego se regresaran las cartas se volveran 
a barajear y se repartiran, sin el jugador que perdio esta vez, este teniendo 
que cumplir un castigo o reto.*/

//investigando encontre para facilitarnos el uso de ciertas librerias 
#include <iostream>
//ya usada en clase que nos ayudara con cadenas de texto 
#include <string>
//esta libreria nos ayudara con la generacion de numeros ramdom o utilidades ramdomizando ciertas cosas.
#include <cstdlib>
//esta libreria es en funcion al tiempo, utilizda para poder inicializar el barajeo ramdoom, la idea es que haga que
//cada barajeo sea diferente
#include <vector>
// Se incluye la librería windows.h para manipular la consola.
#include <windows.h>
// esta libreria es en funcion al tiempo, utilizda para poder inicializar el barajeo ramdoom, la idea es que haga que
// cada barajeo sea diferente
#include <ctime>
using namespace std;

// Determinamos unas constantes, para tener el numeros de cartas
const int MAX_JUGADORES = 4;
const int CARTAS_POR_JUGADOR = 4; // Se ajusta a 4 para mostrar 4 cartas.
const int TOTAL_CARTAS = 16;      // Se restaura a 16 cartas para el mazo completo.

// desarrollo de tarjetas
string mazo[TOTAL_CARTAS] = {
    "Rey", "Rey", "Rey", "Rey", "Rey",
    "Reina", "Reina", "Reina", "Reina", "Reina",
    "As", "As", "As", "As", "As",
    "Jocker"};

// Se modifica la función para obtener el arte ASCII como un vector de strings (una string por línea).
vector<string> obtenerCartaASCII(const string &carta)
{
    // Se utiliza un vector de strings para almacenar cada línea de la representación ASCII de la carta.
    vector<string> ascii_art;

    if (carta == "Rey")
    {
                ascii_art.push_back("┌───────┐"); // Se agrega la primera línea del arte ASCII.
                ascii_art.push_back("│ K     │"); // Se agrega la segunda línea.
                ascii_art.push_back("│   ♥   │");
                ascii_art.push_back("│   _   │");
                ascii_art.push_back("│  / \\  │");
                ascii_art.push_back("│ /   \\ │");
                ascii_art.push_back("│     K │");
                ascii_art.push_back("└───────┘");
           
    }
    else if (carta == "Reina")
    {
                ascii_art.push_back("┌───────┐");
                ascii_art.push_back("│ Q     │");
                ascii_art.push_back("│   ♠   │");
                ascii_art.push_back("│  / _ \\│");
                ascii_art.push_back("│ ( o ) │");
                ascii_art.push_back("│ \\_~_/ │");
                ascii_art.push_back("│     Q │");
                ascii_art.push_back("└───────┘");
           
    }
    else if (carta == "As")
    {
                ascii_art.push_back("┌───────┐");
                ascii_art.push_back("│ A     │");
                ascii_art.push_back("│   ♦   │");
                ascii_art.push_back("│  / \\  │");
                ascii_art.push_back("│ (   ) │");
                ascii_art.push_back("│  \\ /  │");
                ascii_art.push_back("│     A │");
                ascii_art.push_back("└───────┘");
           
    }
    else if (carta == "Jocker")
    {
                ascii_art.push_back("┌───────┐");
                ascii_art.push_back("│ JKR   │");
                ascii_art.push_back("│   ♣   │");
                ascii_art.push_back("│  _^_  │");
                ascii_art.push_back("│ |o_o| │");
                ascii_art.push_back("│  \\_/  │");
                ascii_art.push_back("│   JKR │");
                ascii_art.push_back("└───────┘");
           
    }
        return ascii_art;
}