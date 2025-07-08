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

#include "./src/def.cpp" // Incluimos el archivo de cabecera con declaraciones

int main()
{
    system("cls"); 
    // Establece la codificación de la consola a UTF-8 para que los caracteres especiales se muestren correctamente.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand(time(0));
    int option = 0;
    int numPlayers;
    bool gameActive = true;
    int currentTurn = 0; // El primer turno es para el jugador 0.
    string playerNames[MAX_PLAYERS];
    string hands[MAX_PLAYERS][CARDS_PER_PLAYER];
    // Array para rastrear los turnos perdidos.
    bool lostTurns[MAX_PLAYERS] = {false};

    do { //do
        cout << "\n=========================================\n";
        cout << "Bienvenido al juego: 'La Mesa de los Mentirosos'\n";
        cout << "=========================================\n";
        cout << " 1. Jugar\n 2. Tabla de puntuaciones\n 3. Salir\n";
        
        // Validación para la opción del menú principal
        cout<<"Ingrese una opcion: "; cin>>option;
        system("cls");

        if (cin.fail()) { // Si la entrada no fue un número
            cin.clear(); // Limpiar el estado de error de cin
            // Ignorar el resto de la línea actual para evitar bucles infinitos
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        } else {
            // Limpiar el buffer de entrada para la siguiente lectura (por si el usuario ingresó más de lo necesario)
            system("cls");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        while (option < 1 || option > 3) {
            cout << "\n=========================================\n";
            cout << "Bienvenido al juego: 'La Mesa de los Mentirosos'\n";
            cout << "=========================================\n";
            cout << " 1. Jugar\n 2. Tabla de puntuaciones\n 3. Salir\n";
            cout<<"Opcion inválida. Ingrese una opcion correcta: "; cin>>option;
            
            if (cin.fail()) { // Si la entrada no fue un número
            system("cls");
            cin.clear(); // Limpiar el estado de error de cin
            // Ignorar el resto de la línea actual para evitar bucles infinitos
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        } else {
            // Limpiar el buffer de entrada para la siguiente lectura (por si el usuario ingresó más de lo necesario)
            system("cls");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        }

        switch (option) {
            case 1: { // Se utiliza un bloque para la declaración de variables dentro del case
                cout << "\n";
                cout << " || Bienvenido a la mesa de los mentirosos! ||\n";
                cout << "\n";
                cout << "El mazo de cartas contiene: Rey, Reina, As y Jocker (5 de cada uno, para un total de 20 cartas).\n";
                cout << "Cada jugador recibira " << CARDS_PER_PLAYER << " cartas al inicio del juego.\n";
                cout << "En tu turno, reclamaras una carta y decidiras cual tirar realmente. Los demas jugadores podran tirar una carta (pueden mentir).\n";
                cout << "Cualquier jugador puede acusar a otro de mentiroso. Si la acusacion es correcta, el mentiroso pierde el siguiente turno. Si es incorrecta, el acusador pierde el siguiente turno.\n";
                cout << "El juego termina cuando un jugador se queda sin cartas o no hay mas jugadores activos.\n";
                cout << "Presione Enter para comenzar el juego..." << endl;
                cin.get();    // Esperar a que el usuario presione Enter
                system("cls"); // Borra la consola

                // Número de jugadores con validación
                numPlayers = getValidInteger("¿Cuantos jugadores participaran en el juego? (2-4 jugadores): ");

                while (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
                    numPlayers = getValidInteger("Numero de jugadores invalido. Por favor ingrese un numero entre 2 y 4: ");
                    system("cls"); // Borra la consola
                }

                // pedimos los nombres de los jugadores para referirnos a ellos
                cout << "Ingresa los nombres de los jugadores:" << endl;
                for (int i = 0; i < numPlayers; i++) {
                    cout << "Jugador " << (i + 1) << ": ";
                    cin >> playerNames[i];
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer después de cin >> string
                }

                // llamamos las funciones para abrajear y repartir
                // Barajar y repartir cartas
                shuffleDeck(deck, TOTAL_CARDS);
                dealCards(hands, numPlayers, deck);

                // Reestablecer juegoActivo para la nueva partida
                gameActive = true;
                currentTurn = 0; // El juego siempre empieza con el jugador 0.
                for(int i = 0; i < MAX_PLAYERS; ++i) {
                    lostTurns[i] = false;
                }

                while (gameActive) {
                    int playersWithCards = 0;
                    int lastPlayerWithCards = -1;

                    // Contar jugadores con cartas y verificar condición de victoria/fin de juego
for (int i = 0; i < numPlayers; ++i) {
    int currentCards = 0;
    for (int j = 0; j < CARDS_PER_PLAYER; ++j) {
        if (hands[i][j] != "") {
            currentCards++;
        }
    }
    if (currentCards > 0) {
        playersWithCards++;
        lastPlayerWithCards = i;
    } else {
        // Verificar si este jugador se quedó sin cartas (condición de victoria)
        cout << "\n¡Felicidades, " << playerNames[i] << " se ha quedado sin cartas y ha ganado la ronda!\n";
        saveScore(playerNames[i]);
        gameActive = false;
        break;
    }
}

if (gameActive && playersWithCards == 0) {
    cout << "\n¡El juego ha terminado! No quedan cartas en juego ni jugadores activos.\n";
    gameActive = false;
}
                    
                    // --- LÓGICA PARA DETERMINAR EL JUGADOR DEL TURNO ---
                    // Esta lógica asegura que 'currentTurn' siempre apunte al jugador correcto para el turno.
                    // Se itera hasta encontrar un jugador que NO esté penalizado y tenga cartas.
                    bool turnFound = false;
                    int rotationAttempts = 0; // Contador para evitar bucles infinitos si todos pierden turnos/cartas
                    int candidatePlayer = currentTurn; // Empieza la búsqueda desde el último jugador que tuvo el turno.

                    do {
                    // Si el jugador candidato está penalizado, se consume la penalización y se salta su turno.
                        if (lostTurns[candidatePlayer]) {
            cout << "\n¡" << playerNames[candidatePlayer] << " pierde su turno por penalización!\n"; 
            lostTurns[candidatePlayer] = false; // La penalización se cumple y se remueve.
        // Continúamos buscando al siguiente jugador
    } else {
        // Si el jugador no está penalizado, verificamos si tiene cartas
        int playerCards = 0;
        for (int k = 0; k < CARDS_PER_PLAYER; ++k) {
            if (hands[candidatePlayer][k] != "") {
                playerCards++;
            }
        }

        if (playerCards > 0) {
            // ¡Se encontró un jugador válido para tomar este turno!
            currentTurn = candidatePlayer; // Actualizamos el 'currentTurn' global
            turnFound = true;
            break; // Salir del bucle do-while de búsqueda
        } else {
            // Si el jugador no tiene cartas (y no está penalizado), se salta su turno.
            cout << "\n" << playerNames[candidatePlayer] << " no tiene mas cartas. Saltando su turno.\n";
        }
    }

    candidatePlayer = (candidatePlayer + 1) % numPlayers; // Avanza al siguiente jugador SOLO después de chequear el actual
    rotationAttempts++;

    // Si hemos dado una vuelta completa a todos los jugadores y no encontramos un turno válido
    if (rotationAttempts >= numPlayers) {
        cout << "\n¡El juego ha terminado! No hay jugadores disponibles para jugar.\n";
        gameActive = false;
        break; // Salir del bucle do-while de búsqueda
    }

} while (!turnFound); // Continúa buscando hasta encontrar un turno válido o terminar el juego

                    if (!gameActive) { // Si el juego se marcó como inactivo dentro del bucle de búsqueda
                        break; // Salir del bucle principal del juego
                    }
                    // --- FIN DE LA LÓGICA PARA DETERMINAR EL JUGADOR DEL TURNO ---
                    
                    system("cls");

                    cout << "\n=========================================\n";
                    cout << "Turno de " << playerNames[currentTurn] << endl;
                    cout << "Tus cartas: " << endl;
                    showHand(hands[currentTurn], CARDS_PER_PLAYER);

                    string claim;
                    while (true) {
                        cout << "¿Que carta reclamas tirar (Rey, Reina, As, Jocker)? ";
                        cin >> claim;
                        transform(claim.begin(), claim.end(), claim.begin(), ::tolower);
                        if (claim == "rey" || claim == "reina" || claim == "as" || claim == "jocker") {
                            claim[0] = toupper(claim[0]);
                            break;
                        } else {
                            system("cls");
                            cout << "\n=========================================\n";
                            cout << "Turno de " << playerNames[currentTurn] << endl;
                            cout << "Tus cartas: " << endl;
                            showHand(hands[currentTurn], CARDS_PER_PLAYER);
                            cout << "Reclamo invalido. Por favor, ingrese Rey, Reina, As o Jocker.\n";

                        }
                    }

                    string actualCardPlayed = "";
                    int cardsToPlay = 0;
                    system("cls");
                    cout << "\n=========================================\n";
                    cout << "Turno de " << playerNames[currentTurn] << endl;
                    cout << "Tus cartas: " << endl;
                    showHand(hands[currentTurn], CARDS_PER_PLAYER);
                    while (true) {
                        cout << playerNames[currentTurn] << ", ¿que carta REALMENTE tiras de tu mano?: ";
                        cin >> actualCardPlayed;
                        transform(actualCardPlayed.begin(), actualCardPlayed.begin() + 1, actualCardPlayed.begin(), ::toupper);

                        int availableCards = countCard(hands[currentTurn], CARDS_PER_PLAYER, actualCardPlayed);
                        if (availableCards == 0) {
                            system("cls");
                            cout << "\n=========================================\n";
                            cout << "Turno de " << playerNames[currentTurn] << endl;
                            cout << "Tus cartas: " << endl;
                            showHand(hands[currentTurn], CARDS_PER_PLAYER);
                            cout << "No tienes esa carta en tu mano. Por favor, elige una carta que tengas.\n";
                            continue;
                        }

                        // Validación para cantidad_tirar
                        cardsToPlay = getValidInteger("¿Cuantas cartas de '" + actualCardPlayed + "' quieres tirar (1-" + to_string(availableCards) + ")? ");

                        if (cardsToPlay >= 1 && cardsToPlay <= availableCards) {
                            break;
                        } else {
                            cout << "\n=========================================\n";
                            cout << "Turno de " << playerNames[currentTurn] << endl;
                            cout << "Tus cartas: " << endl;
                            showHand(hands[currentTurn], CARDS_PER_PLAYER);
                            cout << "Cantidad invalida. Debes tirar entre 1 y " << availableCards << " cartas de ese tipo.\n";
                        }
                    }

                    removeCards(hands[currentTurn], CARDS_PER_PLAYER, actualCardPlayed, cardsToPlay);

                    cout << playerNames[currentTurn] << " ha tirado " << cardsToPlay << " carta(s) y reclamado que eran: " << claim << endl;

                    cout << "\nLos demas jugadores estan tirando sus cartas...\n";

                    char accuseResponse;
                    int accuserIndex = -1;
                    int accusedIndex = currentTurn; // El jugador en turno es el acusado por defecto

                    cout << "\n¿Alguien quiere acusar al jugador " << playerNames[currentTurn] << " de mentiroso? (S/N): ";
                    cin >> accuseResponse;

                    while (accuseResponse != 's' && accuseResponse != 'S' && accuseResponse != 'n' && accuseResponse != 'N') {
                        cout << "Has ingresado una respuesta incorrecta. Ingresa (S) o (N): ";
                        cin >> accuseResponse;
                    }

                    system("cls");

                    if (accuseResponse == 's' || accuseResponse == 'S') {
                        cout << "Seleccione su nombre de jugador para acusar:" << endl;
                        for (int i = 0; i < numPlayers; i++) {
                            if (i != currentTurn) { // No se puede acusar a sí mismo
                                cout << i + 1 << ". " << playerNames[i] << endl;
                            }
                        }
                        // Validación para jugador_que_delata_index
                        accuserIndex = getValidInteger("Ingrese el numero del jugador que acusa: ");
                        accuserIndex--; // Ajustar índice.

                        while (accuserIndex < 0 || accuserIndex >= numPlayers || accuserIndex == currentTurn) {
                            if (accuserIndex == currentTurn) {
                                cout << "No puedes delatarte a ti mismo. ";
                            }
                            accuserIndex = getValidInteger("Seleccione un jugador valido para acusar: ");
                            accuserIndex--;
                        }

                        system("cls");

                        cout << playerNames[accuserIndex] << " ha acusado a " << playerNames[accusedIndex] << " de mentiroso." << endl;
                        cout << playerNames[accusedIndex] << " dijo que tiro la carta: '" << claim << "'" << endl;
                        cout << "Y REALMENTE tiro la carta: '" << actualCardPlayed << "'" << endl;

                        bool isLie = (claim != actualCardPlayed);

                        if (isLie) {
                            // Acusador acertó, el jugador en turno MINTIÓ.
                            cout << "\n¡Acusacion correcta! " << playerNames[accusedIndex] << " mintio." << endl;
                            cout << playerNames[accusedIndex] << " pierde el siguiente turno." << endl;
                            lostTurns[accusedIndex] = true; // El mentiroso pierde el turno
                        } else {
                            // Acusador se equivocó, porque el jugador en turno SÍ dijo la verdad.
                            cout << "\n¡Acusacion incorrecta! " << playerNames[accusedIndex] << " no mintio." << endl;
                            cout << playerNames[accuserIndex] << " pierde el siguiente turno." << endl;
                            lostTurns[accuserIndex] = true; // El acusador incorrecto pierde el turno
                        }
                    }

                    cout << "\nPresione Enter para continuar al siguiente turno o al menu principal...\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
                    system("cls"); // Borra la consola
                    int nextTurn = (currentTurn + 1) % numPlayers;
int attempts = 0;
while (attempts < numPlayers) {
    // Si el jugador no está penalizado y tiene cartas, le toca el turno
    if (!lostTurns[nextTurn]) {
        int cards = 0;
        for (int k = 0; k < CARDS_PER_PLAYER; ++k) {
            if (hands[nextTurn][k] != "") cards++;
        }
        if (cards > 0) {
            currentTurn = nextTurn;
            break;
        }
    } else {
        // Si está penalizado, consume la penalización
        lostTurns[nextTurn] = false;
    }
    nextTurn = (nextTurn + 1) % numPlayers;
    attempts++;
}
                } // Fin del while (gameActive)
                break;
            } // Fin case 1

            case 2:
                loadScoreboard();
                cout << "\nPresione Enter para salir al menu principal..." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
                system("cls"); // Borra la consola
                break;

            case 3:
                cout << "\n¡Gracias por jugar a La Mesa de los Mentirosos! Hasta pronto.\n";
                break;
        } // Fin switch menu principal
    } while (option != 3);

    return 0;
}