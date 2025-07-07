//Desarrollamos "definiciones.cpp", para definir las funciones declaradas en "header.h", con ello buscamos hacer el codigo mas optimizado."
                                    //LLAMAMOS A DONDE DECLARAMOS LAS FUNCIONES.
#include "header.h"
                                    //DECLARAMOS Y DEFINIMOS LAS FUNCIONES.
                        
//Declaramos el nombre de las cartas.
string mazo[TOTAL_CARTAS] = {
    "Rey", "Rey", "Rey", "Rey",
    "Reina", "Reina", "Reina", "Reina",
    "As", "As", "As", "As",
    "Jocker", "Jocker", "Jocker", "Jocker"}; // Se balancea el mazo con 4 Jockers

// función para obtener el arte ASCII como un vector de strings (una string por línea).
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
        ascii_art.push_back("│ / _ \\ │");
        ascii_art.push_back("│ ( o ) │");
        ascii_art.push_back("│  \\~/  │");
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
        ascii_art.push_back("│   ^   │");
        ascii_art.push_back("│ |o_o| │");
        ascii_art.push_back("│  \\_/  │");
        ascii_art.push_back("│   JKR │");
        ascii_art.push_back("└───────┘");

    }
    return ascii_art;
}

// Ahora realizamos una funcion para poder hacer el barajeo
void barajarMazo(string m[], int n)
{
    // Se utiliza un generador de números aleatorios más moderno y se mezcla el mazo.
    random_device rd;
    mt19937 g(rd());
    shuffle(m, m + n, g);
}

// repartimos en una funcion las cartas a los jugadores
void repartirCartas(string manos[MAX_JUGADORES][CARTAS_POR_JUGADOR], int numJugadores, string m[])
{
    int pos = 0;
    for (int i = 0; i < numJugadores; i++)
    {
        for (int j = 0; j < CARTAS_POR_JUGADOR; j++)
        {
            manos[i][j] = m[pos++];
        }
    }
}

// Se modifica la función para mostrar las cartas horizontalmente.
void mostrarMano(string mano[], int tam)
{
    // Se obtiene el arte ASCII de todas las cartas en la mano y se almacena en un vector de vectores de strings.
    vector<vector<string>> cartas_ascii;
    for (int i = 0; i < tam; i++)
    {
        if (mano[i] != "")
        {
            cartas_ascii.push_back(obtenerCartaASCII(mano[i]));
        }
    }

    // Se asume que todas las cartas tienen el mismo número de líneas para la representación ASCII.
    if (!cartas_ascii.empty())
    {
        int num_lineas_carta = cartas_ascii[0].size();
        // Se itera a través de cada línea del arte ASCII de las cartas.
        for (int i = 0; i < num_lineas_carta; i++)
        {
            // Se itera a través de cada carta en la mano.
            for (const auto &carta_art : cartas_ascii)
            {
                // Se imprime la línea actual de la carta seguida de un espacio.
                cout << carta_art[i] << " ";
            }
            // Se imprime un salto de línea después de imprimir la misma línea de todas las cartas.
            cout << endl;
        }
    }
    cout << endl;
}
// hacemor una funcion para comprobar las cartas que tendra cada jugador
int contarCarta(string mano[], int tam, string carta)
{
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (mano[i] == carta)
            cont++;
    }
    return cont;
}

// cuando un jugador tire una carta, hacemos una funcion para que este elimine dicha carta
void eliminarCartas(string mano[], int tam, string carta, int cantidad)
{
    // Usamos un índice 'write_idx' para mantener un seguimiento de dónde colocar la próxima carta no eliminada.
    int write_idx = 0;
    for (int i = 0; i < tam; i++)
    {
        // Si la carta actual NO es la que queremos eliminar O ya hemos eliminado la cantidad deseada,
        // entonces la mantenemos en la mano.
        if (mano[i] != carta || cantidad <= 0)
        {
            mano[write_idx++] = mano[i];
        }
        else
        {
            // Si es la carta a eliminar y todavía necesitamos eliminar más,
            // simplemente la "saltamos" (no la copiamos a write_idx) y decrementamos la cantidad.
            cantidad--;
        }
    }

    // Rellenar el resto de la mano con cadenas vacías para los espacios que quedaron libres.
    for (int i = write_idx; i < tam; i++)
    {
        mano[i] = "";
    }
}

//Estructura y funcion de tabla de puntuaciones
struct puntos_jugadores {
    string nombre;
    int victorias;
};

void cargar_tabla_de_puntos() {
    ifstream tabla_puntos("puntuaciones.txt"); // Nombre de archivo más descriptivo
    puntos_jugadores puntos;

    if (tabla_puntos.is_open()) {
        cout << "\n--- Tabla de Puntuaciones ---\n";
        cout << "Nombre ---------- Victorias \n";
        while (tabla_puntos >> puntos.nombre >> puntos.victorias) {
            cout << puntos.nombre << " ------------- " << puntos.victorias << endl;
        }
        tabla_puntos.close();
    } else {
        cout << "No se pudo cargar la tabla de puntuaciones. ¡Juega para empezar a registrar!\n";
    }
}

void guardar_puntuacion(const string& nombre_jugador) {
    // Cargar puntuaciones existentes
    vector<puntos_jugadores> tabla;
    ifstream infile("puntuaciones.txt");
    if (infile.is_open()) {
        puntos_jugadores p;
        while (infile >> p.nombre >> p.victorias) {
            tabla.push_back(p);
        }
        infile.close();
    }

    // Actualizar puntuación del jugador actual
    bool encontrado = false;
    for (auto& p : tabla) {
        if (p.nombre == nombre_jugador) {
            p.victorias++;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        tabla.push_back({nombre_jugador, 1});
    }

    // Guardar todas las puntuaciones de nuevo
    ofstream outfile("puntuaciones.txt");
    if (outfile.is_open()) {
        for (const auto& p : tabla) {
            outfile << p.nombre << " " << p.victorias << endl;
        }
        outfile.close();
    } else {
        cout << "Error al guardar la puntuación.\n";
    }
}

