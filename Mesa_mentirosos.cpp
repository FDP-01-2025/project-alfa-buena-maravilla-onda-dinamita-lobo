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
//Libreria para los archivos donde se guardan las puntuaciones
#include <fstream>
using namespace std;

// Determinamos unas constantes, para tener el numeros de cartas
const int MAX_PLAYERS = 4;
const int CARDS_PER_PLAYER = 4; // Se ajusta a 4 para mostrar 4 cartas.
const int TOTAL_CARDS = 16;      // Se restaura a 16 cartas para el mazo completo.

// desarrollo de tarjetas
string deck[TOTAL_CARDS] = {
    "Rey", "Rey", "Rey", "Rey", "Rey",
    "Reina", "Reina", "Reina", "Reina", "Reina",
    "As", "As", "As", "As", "As",
    "Jocker"};

// Se modifica la función para obtener el arte ASCII como un vector de strings (una string por línea).
vector<string> showCardASCII(const string &card)
{
    vector<string> ascii_art;

    if (card == "Rey")
    {
        ascii_art.push_back("┌───────┐");
        ascii_art.push_back("│ K     │");
        ascii_art.push_back("│   ♥   │");
        ascii_art.push_back("│   _   │");
        ascii_art.push_back("│  / \\  │");
        ascii_art.push_back("│ /   \\ │");
        ascii_art.push_back("│     K │");
        ascii_art.push_back("└───────┘");
    }
    else if (card == "Reina")
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
    else if (card == "As")
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
    else if (card == "Jocker")
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

// Ahora realizamos una funcion para poder hacer el barajeo
void shuffleDeck(string d[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = rand() % n;
        string temp = d[i];
        d[i] = d[j];
        d[j] = temp;
    }
}

// repartimos en una funcion las cartas a los jugadores
void dealCards(string hands[MAX_PLAYERS][CARDS_PER_PLAYER], int numPlayers, string d[])
{
    int pos = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        for (int j = 0; j < CARDS_PER_PLAYER; j++)
        {
            hands[i][j] = d[pos++];
        }
    }
}

// Se modifica la función para mostrar las cartas horizontalmente.
void showHand(string hand[], int size)
{
    vector<vector<string>> cards_ascii;
    for (int i = 0; i < size; i++)
    {
        if (hand[i] != "")
        {
            cards_ascii.push_back(showCardASCII(hand[i]));
        }
    }

    if (!cards_ascii.empty())
    {
        int num_lines = cards_ascii[0].size();
        for (int i = 0; i < num_lines; i++)
        {
            for (const auto &card_art : cards_ascii)
            {
                cout << card_art[i] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

// hacer una funcion para comprobar las cartas que tendra cada jugador
int countCard(string hand[], int size, string card)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (hand[i] == card)
            count++;
    }
    return count;
}

// cuando un jugador tire una carta, hacemos una funcion para que este elimine dicha carta
void removeCards(string hand[], int size, string card, int quantity)
{
    for (int i = 0; i < size && quantity > 0; i++)
    {
        if (hand[i] == card)
        {
            hand[i] = "";
            quantity--;
        }
    }
}

//Estructura y funcion de tabla de puntuaciones
struct player_points{
    string name;
    int victories;
};

void load_scoreboard(){
    ifstream score_file("archivo_prueba.txt");
    player_points points;

    if(score_file.is_open()){
        cout << "Nombre ---------- Victorias \n";
        while(score_file >> points.name >> points.victories){
            cout << points.name << " -------------" <<
                points.victories << endl;
        }
        score_file.close();
    }else{
        cout << "Error con el archivo";
    }
}

// Empezamos a trabajar en el main
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand(time(0));
    int option = 0;
    int numPlayers;
    bool gameActive = true;
    int turn = 0;
    string names[MAX_PLAYERS];
    string hands[MAX_PLAYERS][CARDS_PER_PLAYER];
    // Array para rastrear los turnos perdidos.
    bool lostTurns[MAX_PLAYERS] = {false};

    do
    {
        cout << "Bienvenido al juego: 'La mesa de los mentirosos' \n";
        cout << " 1.Jugar \n 2.Tabla de puntuaciones \n 3.Salir";
        cout << "\n Ingrese una opcion: ";
        cin >> option;

        while (option < 1 || option > 3)
        {
            cout << "Bienvenido al juego: 'La mesa de los mentirosos'";
            cout << "1.Jugar \n 2.Tabla de puntuaciones \n 3.Salir";
            cout << "\n Ingrese una opcion correcta: ";
            cin >> option;
        }

        switch(option){
        case 1:
            cout << "\n";
            cout << " || Bienvenido a la mesa de los mentirosos! ||\n";
            cout << "\n";
            cout << "El mazo de cartas contiene: Rey, Reina, As y Jocker.\n";
            cout << "Cada jugador recibira 5 cartas al inicio del juego.\n";
            cout << "El juego comenzara con un jugador reclamando una carta, los demas jugadores podran ingresar que cartas de su mano quieren tirar.\n";
            cout << "Si el jugador que reclama tiene 3 cartas de la que reclamo, gana, si no, pierde.\n";
            cout << "El juego continuara hasta que un jugador se quede sin cartas o nunca mienta.\n";
            cout << "Presione Enter para comenzar el juego..." << endl;
            cin.ignore();

            cout << "Cuantos jugadores participaran en el juego? (2-4 jugadores): ";
            cin >> numPlayers;

            while (numPlayers < 2 || numPlayers > 4)
            {
                cout << "Numero de jugadores invalido. Por favor ingrese un numero entre 2 y 4: ";
                cin >> numPlayers;
            }

            cout << "Ingresa los nombres de los jugadores:" << endl;
            for (int i = 0; i < numPlayers; i++)
            {
                cout << "Jugador " << (i + 1) << ": ";
                cin >> names[i];
            }

            shuffleDeck(deck, TOTAL_CARDS);
            dealCards(hands, numPlayers, deck);

            // INICIO DEL BLOQUE DE CÓDIGO AÑADIDO PARA LA DEMOSTRACIÓN
            if (numPlayers > 0)
            {
                hands[0][0] = "Rey";
                hands[0][1] = "Reina";
                hands[0][2] = "As";
                hands[0][3] = "Jocker";
            }
            // FIN DEL BLOQUE DE CÓDIGO AÑADIDO

            while (gameActive)
            {
                if (lostTurns[turn])
                {
                    cout << "\n¡" << names[turn] << " pierde su turno por haber acusado incorrectamente!\n";
                    lostTurns[turn] = false;
                    turn = (turn + 1) % numPlayers;
                    continue;
                }

                cout << "\n=========================================\n";
                cout << "Turno de " << names[turn] << endl;
                cout << "Tus cartas: " << endl;
                showHand(hands[turn], CARDS_PER_PLAYER);

                string claim;
                cout << "¿Qué carta reclamas tirar (Rey, Reina, As, Jocker)? ";
                cin >> claim;

                string actual_card_thrown = "";
                cout << names[turn] << ", ¿qué carta REALMENTE tiras de tu mano?: ";
                cin >> actual_card_thrown;

                removeCards(hands[turn], CARDS_PER_PLAYER, actual_card_thrown, 1);

                for (int j = 0; j < numPlayers; j++)
                {
                    if (j == turn) continue;
                    cout << names[j] << ", estas son tus cartas:" << endl;
                    showHand(hands[j], CARDS_PER_PLAYER);
                    cout << names[j] << ", ¿quieres tirar una carta como '" << claim << "'? (S/N): ";
                    char throw_response;
                    cin >> throw_response;
                    if (throw_response == 'S' || throw_response == 's')
                    {
                        cout << names[j] << " ha tirado una carta." << endl;
                    }
                }

                char response;
                int accusingPlayer;
                int accusedPlayer;

                cout << "Alguien quiere acusar? (S/N): ";
                cin >> response;

                while (response != 's' && response != 'S' && response != 'n' && response != 'N')
                {
                    cout << "Has ingresado una respuesta incorrecta. Ingresa (S) o (N): ";
                    cin >> response;
                }

                system("cls");

                if (response == 's' || response == 'S')
                {
                    cout << "Seleccione su nombre de jugador:" << endl;
                    for (int i = 0; i < numPlayers; i++)
                    {
                        cout << i + 1 << ". " << names[i] << endl;
                    }
                    cin >> accusingPlayer;
                    accusingPlayer--;
                    system("cls");

                    while (accusingPlayer < 0 || accusingPlayer >= numPlayers)
                    {
                        system("cls");
                        cout << "Seleccione un jugador valido" << endl;
                        cin >> accusingPlayer;
                        accusingPlayer--;
                    }

                    system("cls");

                    cout << "¿A qué jugador deseas delatar?" << endl;
                    for (int i = 0; i < numPlayers; i++)
                    {
                        if (i != accusingPlayer)
                        {
                            cout << i + 1 << ". " << names[i] << endl;
                        }
                    }
                    cin >> accusedPlayer;
                    accusedPlayer--;

                    while (accusedPlayer < 0 || accusedPlayer >= numPlayers || accusedPlayer == accusingPlayer)
                    {
                        if (accusedPlayer == accusingPlayer)
                        {
                            cout << "No te puedes delatar a ti mismo" << endl;
                        }
                        cout << "Seleccione un jugador valido" << endl;
                        for (int i = 0; i < numPlayers; i++)
                        {
                            if (i != accusingPlayer)
                            {
                                cout << i + 1 << ". " << names[i] << endl;
                            }
                        }
                        cin >> accusedPlayer;
                        accusedPlayer--;
                    }

                    system("cls");

                    cout << "El jugador " << names[accusingPlayer] << " ha acusado a " << names[accusedPlayer] << " de mentiroso." << endl;
                    cout << names[accusedPlayer] << " dijo que tiró la carta: '" << claim << "'" << endl;
                    cout << "Y REALMENTE tiró la carta: '" << actual_card_thrown << "'" << endl;

                    if (claim == actual_card_thrown)
                    {
                        cout << "\n¡Acusación incorrecta! " << names[accusedPlayer] << " no mintió." << endl;
                        cout << names[accusingPlayer] << " pierde el siguiente turno." << endl;
                        lostTurns[accusingPlayer] = true;
                    }
                    else
                    {
                        cout << "\n¡Acusación correcta! " << names[accusedPlayer] << " mintió." << endl;
                        cout << names[accusedPlayer] << " pierde el siguiente turno." << endl;
                        lostTurns[accusedPlayer] = true;
                    }
                }

                turn = (turn + 1) % numPlayers;
            }
            break;

        case 2:
            load_scoreboard();
            cout << "Presione Enter para salir..." << endl;
            cin.ignore();
            break;
        }
    } while (option != 3);

    return 0;
}
