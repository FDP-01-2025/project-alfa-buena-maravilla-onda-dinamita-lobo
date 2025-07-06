//Incorporación del archivo def.cpp
#include "src/header.h"

int main () {
    srand(time(0));
    int numPlayers;
    bool gameActive = true;
    int turn = 0;
    char response;
    int accusingPlayer;
    int accusedPlayer;
    string names[MAX_PLAYERS];
    string hands[MAX_PLAYERS][CARDS_PER_PLAYER];

    // damos la bienvenida a los usuarios , con código ascii para que sea bonito también
    cout << "╔══════════════════════════════════════════════════════╗\n";
    cout << "║        Bienvenido a la mesa de los mentirosos!       ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";
    cout << "El mazo de cartas contiene: Rey, Reina, As y Jocker.\n";
    cout << "Cada jugador recibira 5 cartas al inicio del juego.\n";
    cout << "El juego comenzara con un jugador reclamando una carta, los demas jugadores podran ingresar que cartas de su mano quieren tirar.\n";
    cout << "Si el jugador que reclama tiene 3 cartas de la que reclamo, gana, si no, pierde.\n";
    cout << "El juego continuara hasta que un jugador se quede sin cartas o nunca mienta.\n";
    cout << "Presione Enter para comenzar el juego..." << endl;
    cin.ignore();

    // los jugadores no pueden ser menos de 2 por lo que preguntamos y de una comprobamos
    cout << "Cuantos jugadores participaran en el juego? (2-4 jugadores): ";
    cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 4) {
        cout << "Numero de jugadores invalido. Por favor ingrese un numero entre 2 y 4: ";
        cin >> numPlayers;
    }

    // pedimos los nombres de los jugadores para referirnos a ellos 
    cout << "Ingresa los nombres de los jugadores:" << endl;
    for (int i = 0; i < numPlayers; i++) {
        cout << "Jugador " << (i + 1) << ": ";
        cin >> names[i];
    }

    // llamamos las funciones para barajar y repartir
    shuffleDeck(deck, TOTAL_CARDS);
    dealCards(hands, numPlayers, deck);

    // iniciamos el juego
    while (gameActive) {
        cout << "\n═══════════════════════════════════════════════════════\n";
        cout << "Turno de " << names[turn] << endl;
        cout << "Tus cartas: " << endl;
        showHand(hands[turn], CARDS_PER_PLAYER);

        // Reclamar carta
        string claim;
        cout << "¿Qué carta reclamas (Rey, Reina, As, Jocker)? ";
        cin >> claim;

        // Los demás jugadores tiran cartas (pueden mentir)
        for (int j = 0; j < numPlayers; j++) {
            if (j == turn) continue;
            cout << names[j] << ", estas son tus cartas:" << endl;
            showHand(hands[j], CARDS_PER_PLAYER);
            cout << names[j] << ", ¿cuántas cartas quieres tirar como '" << claim << "'? ";
            int quantity;
            cin >> quantity;
            removeCards(hands[j], CARDS_PER_PLAYER, claim, quantity);
        }

        // Espacio para probar la función de delatar un jugador mentiroso
        cout << "¿Alguien quiere acusar? (S/N)" << endl;
        cin >> response;

        while (response != 's' && response != 'S' && response != 'n' && response != 'N') {
            cout << "Has ingresado una respuesta incorrecta. Ingresa (S) o (N): ";
            cin >> response;
            system("cls"); // limpiar consola
        }

        if (response == 's' || response == 'S') {
            cout << "Seleccione su nombre de jugador" << endl;
            for (int i = 0; i < numPlayers; i++) {
                cout << i + 1 << ". " << names[i] << endl;
            }
            cin >> accusingPlayer;
            system("cls");

            while (accusingPlayer < 1 || accusingPlayer > numPlayers) {
                system("cls");
                cout << "Seleccione un jugador valido" << endl;
                cin >> accusingPlayer;
            }
            system("cls");

            // Jugadores a delatar
            cout << "¿A qué jugador deseas delatar?" << endl;
            for (int i = 0; i < numPlayers; i++) {
                cout << i + 1 << ". " << names[i] << endl;
            }
            cin >> accusedPlayer;

            while (accusedPlayer < 1 || accusedPlayer > numPlayers || accusedPlayer == accusingPlayer) {
                if (accusedPlayer == accusingPlayer) {
                    cout << "No te puedes delatar a ti mismo" << endl;
                }
                cout << "Seleccione un jugador valido" << endl;
                for (int i = 0; i < numPlayers; i++) {
                    cout << i + 1 << ". " << names[i] << endl;
                }
                cin >> accusedPlayer;
            }

            // Proceso en el que se comprueba si la acusación es verdadera
            cout << "El jugador " << names[accusingPlayer - 1] << " ha acusado a " << names[accusedPlayer - 1] << " de mentiroso." << endl;
        }
    }

    return 0;
}
