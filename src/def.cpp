//Incorporación del archivo .h 
#include "header.h"

//Funciones
string deck[TOTAL_CARDS] = {
    "Rey", "Rey", "Rey", "Rey", "Rey",
    "Reina", "Reina", "Reina", "Reina", "Reina",
    "As", "As", "As", "As", "As",
    "Jocker"
};

//desarrollamos el arte ASCII de las cartas.
void showCardASCII(const string& card) {
    if (card == "Rey") {
        cout << "┌─────┐\n";
        cout << "│  K  │\n";
        cout << "│ ♚   │\n";
        cout << "└─────┘\n";
    } else if (card == "Reina") {
        cout << "┌─────┐\n";
        cout << "│  Q  │\n";
        cout << "│ ♛   │\n";
        cout << "└─────┘\n";
    } else if (card == "As") {
        cout << "┌─────┐\n";
        cout << "│  A  │\n";
        cout << "│ ♠   │\n";
        cout << "└─────┘\n";
    } else if (card == "Jocker") {
        cout << "┌─────┐\n";
        cout << "│ JKR │\n";
        cout << "│ ★   │\n";
        cout << "└─────┘\n";
    }
}

//ahora realizamos una función para poder hacer el barajeo
void shuffleDeck(string d[], int n) {
    for (int i = 0; i < n; i++) { //esto a través de un bucle
        int j = rand() % n;
        string temp = d[i];
        d[i] = d[j];
        d[j] = temp;
    }
}

//repartimos en una función las cartas a los jugadores 
void dealCards(string hands[MAX_PLAYERS][CARDS_PER_PLAYER], int numPlayers, string d[]) {
    int pos = 0;
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < CARDS_PER_PLAYER; j++) {
            hands[i][j] = d[pos++];
        }
    }
}

//mostramos la mano de los jugadores
void showHand(string hand[], int size) {
    for (int i = 0; i < size; i++) {
        if (hand[i] != "") {
            showCardASCII(hand[i]);
        }
    }
    cout << endl;
}

//hacemos una función para comprobar las cartas que tendrá cada jugador
int countCard(string hand[], int size, string card) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (hand[i] == card) count++;
    }
    return count;
}

//cuando un jugador tire una carta, hacemos una función para que este elimine dicha carta
void removeCards(string hand[], int size, string card, int quantity) {
    for (int i = 0; i < size && quantity > 0; i++) {
        if (hand[i] == card) {
            hand[i] = "";
            quantity--;
        }
    }
}
