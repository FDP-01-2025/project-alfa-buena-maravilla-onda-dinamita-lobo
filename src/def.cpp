//Incorporacio del archivo .h
#include "header.h"

//Funciones
string mazo[TOTAL_CARTAS] = {
    "Rey", "Rey", "Rey", "Rey", "Rey",
    "Reina", "Reina", "Reina", "Reina", "Reina",
    "As", "As", "As", "As", "As",
    "Jocker"
};

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