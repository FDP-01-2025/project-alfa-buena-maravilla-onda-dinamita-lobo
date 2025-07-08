//Desarrollamos "definiciones.cpp", para definir las funciones declaradas en "header.h", con ello buscamos hacer el codigo mas optimizado."
//LLAMAMOS A DONDE DECLARAMOS LAS FUNCIONES.
#include "header.h"
//DECLARAMOS Y DEFINIMOS LAS FUNCIONES.

//Declaramos el nombre de las cartas.
string deck[TOTAL_CARDS] = {
    "Rey", "Rey", "Rey", "Rey", "Rey","Rey", // 6 Reyes
    "Reina", "Reina", "Reina", "Reina", "Reina","Reina", // 6 Reinas
    "As", "As", "As", "As", "As","As", // 6 Ases
    "Jocker", "Jocker"}; // 2 Jockers (para un total de 20 cartas)

// función para obtener el arte ASCII como un vector de strings (una string por línea).
vector<string> getCardASCII(const string &card)
{
    // Se utiliza un vector de strings para almacenar cada línea de la representación ASCII de la carta.
    vector<string> ascii_art;

    if (card == "Rey")
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
    else if (card == "Reina")
    {
        ascii_art.push_back("┌───────┐");
        ascii_art.push_back("│ Q     │");
        ascii_art.push_back("│   ♠   │");
        ascii_art.push_back("│ / _ \\ │");
        ascii_art.push_back("│ ( o ) │");
        ascii_art.push_back("│   \\~/ │");
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
        ascii_art.push_back("│   ^   │");
        ascii_art.push_back("│ |o_o| │");
        ascii_art.push_back("│  \\_/  │");
        ascii_art.push_back("│   JKR │");
        ascii_art.push_back("└───────┘");

    }
    return ascii_art;
}

// Ahora realizamos una funcion para poder hacer el barajeo
void shuffleDeck(string deck[], int n)
{
    // Se utiliza un generador de números aleatorios más moderno y se mezcla el mazo.
    random_device rd;
    mt19937 g(rd());
    shuffle(deck, deck + n, g);
}

// repartimos en una funcion las cartas a los jugadores
void dealCards(string hands[MAX_PLAYERS][CARDS_PER_PLAYER], int numPlayers, string deck[])
{
    int pos = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        for (int j = 0; j < CARDS_PER_PLAYER; j++)
        {
            hands[i][j] = deck[pos++];
        }
    }
}

// Se modifica la función para mostrar las cartas horizontalmente.
void showHand(string hand[], int size)
{
    // Se obtiene el arte ASCII de todas las cartas en la mano y se almacena en un vector de vectores de strings.
    vector<vector<string>> cards_ascii;
    for (int i = 0; i < size; i++)
    {
        if (hand[i] != "")
        {
            cards_ascii.push_back(getCardASCII(hand[i]));
        }
    }

    // Se asume que todas las cartas tienen el mismo número de líneas para la representación ASCII.
    if (!cards_ascii.empty())
    {
        int num_lineas_carta = cards_ascii[0].size();
        // Se itera a través de cada línea del arte ASCII de las cartas.
        for (int i = 0; i < num_lineas_carta; i++)
        {
            // Se itera a través de cada carta en la mano.
            for (const auto &card_art : cards_ascii)
            {
                // Se imprime la línea actual de la carta seguida de un espacio.
                cout << card_art[i] << " ";
            }
            // Se imprime un salto de línea después de imprimir la misma línea de todas las cartas.
            cout << endl;
        }
    }
    cout << endl;
}
// hacemor una funcion para comprobar las cartas que tendra cada jugador
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
    // Usamos un índice 'write_idx' para mantener un seguimiento de dónde colocar la próxima carta no eliminada.
    int write_idx = 0;
    for (int i = 0; i < size; i++)
    {
        // Si la carta actual NO es la que queremos eliminar O ya hemos eliminado la cantidad deseada,
        // entonces la mantenemos en la mano.
        if (hand[i] != card || quantity <= 0)
        {
            hand[write_idx++] = hand[i];
        }
        else
        {
            // Si es la carta a eliminar y todavía necesitamos eliminar más,
            // simplemente la "saltamos" (no la copiamos a write_idx) y decrementamos la cantidad.
            quantity--;
        }
    }

    // Rellenar el resto de la mano con cadenas vacías para los espacios que quedaron libres.
    for (int i = write_idx; i < size; i++)
    {
        hand[i] = "";
    }
}

//Estructura y funcion de tabla de puntuaciones
struct player_scores {
    string nombre;
    int victorias;
};

void loadScoreboard() {
    ifstream scores_file("puntuaciones.txt");
    
    if (scores_file.is_open()) {
        cout << "\n--- Tabla de Puntuaciones ---\n";
        cout << "Jugador          Victorias \n";
        cout << "---------------------------\n";
        
        player_scores player;
        while (scores_file >> player.nombre >> player.victorias) {
            cout << player.nombre << "                " << player.victorias << endl;
        }
        scores_file.close();
    } else {
        cout << "No se pudo cargar la tabla de puntuaciones. ¡Juega para empezar a registrar!\n";
    }
}

void saveScore(const string& playerName) {
    // Cargar puntuaciones existentes
    vector<player_scores> scores_table;
    ifstream infile("puntuaciones.txt");
    if (infile.is_open()) {
        player_scores p;
        while (infile >> p.nombre >> p.victorias) {
            scores_table.push_back(p);
        }
        infile.close();
    }

    // Actualizar puntuación del jugador actual
    bool found = false;
    for (auto& p : scores_table) {
        if (p.nombre == playerName) {
            p.victorias++;
            found = true;
            break;
        }
    }
    if (!found) {
        scores_table.push_back({playerName, 1});
    }

    // Guardar todas las puntuaciones de nuevo
    ofstream outfile("puntuaciones.txt");
    if (outfile.is_open()) {
        for (const auto& p : scores_table) {
            outfile << p.nombre << " " << p.victorias << endl;
        }
        outfile.close();
    } else {
        cout << "Error al guardar la puntuación.\n";
    }
}

// Función de ayuda para obtener entrada entera válida
int getValidInteger(const string& message) {
    int value;
    while (true) {
        cout << message;
        cin >> value;

        if (cin.fail()) { // Si la entrada no fue un número
            system("cls");
            cout << "Entrada inválida. Por favor, ingrese un número.\n";
            cin.clear(); // Limpiar el estado de error de cin
            // Ignorar el resto de la línea actual para evitar bucles infinitos
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        } else {
            // Limpiar el buffer de entrada para la siguiente lectura (por si el usuario ingresó más de lo necesario)
            system("cls");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}