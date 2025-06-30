//Incorporacio del archivo .h
#include "header.h"

//Funciones
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

//repartimos en una funcion las cartas a los jugadores 
void repartirCartas(string manos[MAX_JUGADORES][CARTAS_POR_JUGADOR], int numJugadores, string m[]) {
    int pos = 0;
    for (int i = 0; i < numJugadores; i++) {
        for (int j = 0; j < CARTAS_POR_JUGADOR; j++) {
            manos[i][j] = m[pos++];
        }
    }
}

//mostramos la mano de los jugadores
void mostrarMano(string mano[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (mano[i] != "") {
            mostrarCartaASCII(mano[i]);
        }
    }
    cout << endl;
}