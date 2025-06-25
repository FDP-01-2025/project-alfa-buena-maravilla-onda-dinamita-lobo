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
#include <ctime>
using namespace std;

//determinamos unas constantes, para tener el numeros de cartas 
const int MAX_JUGADORES = 4;
const int CARTAS_POR_JUGADOR = 5;
const int TOTAL_CARTAS = 16;

//desarrollo de tarjetas
string mazo[TOTAL_CARTAS] = {
    "Rey", "Rey", "Rey", "Rey", "Rey",
    "Reina", "Reina", "Reina", "Reina", "Reina",
    "As", "As", "As", "As", "As",
    "Jocker"
};

//desarrollamos el arte ASCII de las cartas.
void mostrarCartaASCII(const string& carta) {
    if (carta == "Rey") {
        cout << "┌─────┐\n";
        cout << "│  K  │\n";
        cout << "│ ♚   │\n";
        cout << "└─────┘\n";
    } else if (carta == "Reina") {
        cout << "┌─────┐\n";
        cout << "│  Q  │\n";
        cout << "│ ♛   │\n";
        cout << "└─────┘\n";
    } else if (carta == "As") {
        cout << "┌─────┐\n";
        cout << "│  A  │\n";
        cout << "│ ♠   │\n";
        cout << "└─────┘\n";
    } else if (carta == "Jocker") {
        cout << "┌─────┐\n";
        cout << "│ JKR │\n";
        cout << "│ ★   │\n";
        cout << "└─────┘\n";
    }
}

//ahora realizamos una funcion para poder hacer el barajeo
void barajarMazo(string m[], int n) {
    for (int i = 0; i < n; i++) { //esto a travez de un bucle
        int j = rand() % n;
        string temp = m[i];
        m[i] = m[j];
        m[j] = temp;
    }
}




int main (){


    return 0;
}

