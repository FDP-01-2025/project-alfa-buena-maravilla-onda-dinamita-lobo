/*Desarrollaremos un juego, llamado la mesa de los mentirosos, este juego puede
ser de 2-4 jugadores los cuales se les repartiran 4 cartas a cada uno de ellos,
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
// Librería para la función shuffle, para barajar de forma más eficiente.
#include <algorithm>
// Librería para el random number generator.
#include <random>

using namespace std;

// Determinamos unas constantes, para tener el numeros de cartas
const int MAX_JUGADORES = 4;
const int CARTAS_POR_JUGADOR = 4; // Se ajusta a 4 para mostrar 4 cartas.
const int TOTAL_CARTAS = 16;      // Se restaura a 16 cartas para el mazo completo.

// desarrollo de tarjetas
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
    for (int i = 0; i < tam && cantidad > 0; i++)
    {
        if (mano[i] == carta)
        {
            mano[i] = ""; // Elimina la carta de la mano
            cantidad--;
        }
    }
    // Después de eliminar, reorganizar la mano para que las cartas vacías queden al final
    for (int i = 0; i < tam - 1; i++) {
        if (mano[i] == "") {
            for (int j = i + 1; j < tam; j++) {
                if (mano[j] != "") {
                    mano[i] = mano[j];
                    mano[j] = "";
                    break;
                }
            }
        }
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


// Empezamos a trabajar en el main
int main()
{
    // Establece la codificación de la consola a UTF-8 para que los caracteres especiales se muestren correctamente.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand(time(0));
    int opcion = 0;
    int numJugadores;
    bool juegoActivo = true;
    int turno = 0;
    string nombres[MAX_JUGADORES];
    string manos[MAX_JUGADORES][CARTAS_POR_JUGADOR];
    // Array para rastrear los turnos perdidos.
    bool turnosPerdidos[MAX_JUGADORES] = {false};


    do { //do
        cout << "\n=========================================\n";
        cout << "Bienvenido al juego: 'La Mesa de los Mentirosos'\n";
        cout << "=========================================\n";
        cout << " 1. Jugar\n 2. Tabla de puntuaciones\n 3. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        // Validación de entrada para el menú principal
        while (opcion < 1 || opcion > 3) {
            cout << "Opción inválida. Por favor, ingrese un número entre 1 y 3: ";
            cin >> opcion;
        }

        switch (opcion) {
            case 1: { // Se utiliza un bloque para la declaración de variables dentro del case
                cout << "\n";
                cout << " || Bienvenido a la mesa de los mentirosos! ||\n";
                cout << "\n";
                cout << "El mazo de cartas contiene: Rey, Reina, As y Jocker (4 de cada uno).\n";
                cout << "Cada jugador recibira 4 cartas al inicio del juego.\n";
                cout << "En tu turno, reclamaras una carta y decidiras cual tirar realmente. Los demas jugadores podran tirar una carta (pueden mentir).\n";
                cout << "Cualquier jugador puede acusar a otro de mentiroso. Si la acusacion es correcta, el mentiroso pierde el siguiente turno. Si es incorrecta, el acusador pierde el siguiente turno.\n";
                cout << "El juego termina cuando un jugador se queda sin cartas o no hay mas jugadores activos.\n";
                cout << "Presione Enter para comenzar el juego..." << endl;
                cin.ignore(); // Limpiar el buffer de entrada
                cin.get();    // Esperar a que el usuario presione Enter

                // Número de jugadores
                cout << "¿Cuantos jugadores participaran en el juego? (2-4 jugadores): ";
                cin >> numJugadores;

                while (numJugadores < 2 || numJugadores > MAX_JUGADORES) {
                    cout << "Numero de jugadores invalido. Por favor ingrese un numero entre 2 y 4: ";
                    cin >> numJugadores;
                }

                // pedimos los nombres de los jugadores para referirnos a ellos
                cout << "Ingresa los nombres de los jugadores:" << endl;
                for (int i = 0; i < numJugadores; i++) {
                    cout << "Jugador " << (i + 1) << ": ";
                    cin >> nombres[i];
                }

                // llamamos las funciones para abrajear y repartir
                // Barajar y repartir cartas
                barajarMazo(mazo, TOTAL_CARTAS);
                repartirCartas(manos, numJugadores, mazo);

                // Reestablecer juegoActivo para la nueva partida
                juegoActivo = true;
                turno = 0;
                for(int i = 0; i < MAX_JUGADORES; ++i) {
                    turnosPerdidos[i] = false;
                }

                // iniciamos el juego
                int jugadoresActivos = numJugadores;
                while (juegoActivo) {
                    // Contar jugadores con cartas
                    int jugadoresConCartas = 0;
                    for (int i = 0; i < numJugadores; ++i) {
                        int cartasRestantes = 0;
                        for (int j = 0; j < CARTAS_POR_JUGADOR; ++j) {
                            if (manos[i][j] != "") {
                                cartasRestantes++;
                            }
                        }
                        if (cartasRestantes > 0) {
                            jugadoresConCartas++;
                        }
                    }

                    if (jugadoresConCartas < 2) {
                        cout << "\n¡El juego ha terminado! No hay suficientes jugadores con cartas para continuar.\n";
                        juegoActivo = false;
                        break;
                    }

                    // Asegurarse de que el turno actual sea de un jugador activo y con cartas
                    // --- INICIO DE LA LÓGICA DE BÚSQUEDA DEL SIGUIENTE JUGADOR VÁLIDO ---
                int jugadorActual = turno; // Guardamos el turno actual
                bool siguienteJugadorEncontrado = false;
                int contadorIntentosBusqueda = 0; // Para evitar bucles infinitos si no hay jugadores

                while (!siguienteJugadorEncontrado && contadorIntentosBusqueda < numJugadores) {
                    // Mover al siguiente jugador para la verificación
                    jugadorActual = (jugadorActual + 1) % numJugadores;

                    int cartasRestantesActual = 0;
                    for (int k = 0; k < CARTAS_POR_JUGADOR; ++k) {
                        if (manos[jugadorActual][k] != "") {
                            cartasRestantesActual++;
                        }
                    }

                    if (turnosPerdidos[jugadorActual]) {
                        cout << "\n¡" << nombres[jugadorActual] << " pierde su turno por haber acusado o mentido incorrectamente!\n";
                        turnosPerdidos[jugadorActual] = false; // El turno perdido solo dura una ronda.
                    } else if (cartasRestantesActual == 0) {
                         cout << "\n" << nombres[jugadorActual] << " no tiene mas cartas. Saltando su turno.\n";
                    } else {
                        // ¡Se encontró un jugador válido!
                        turno = jugadorActual; // Actualizamos el turno al jugador válido
                        siguienteJugadorEncontrado = true;
                    }
                    contadorIntentosBusqueda++;
                }

                if (!siguienteJugadorEncontrado) {
                    cout << "\n¡El juego ha terminado! No hay jugadores disponibles para jugar con cartas o turnos activos. \n";
                    juegoActivo = false;
                    break;
                }
                // --- FIN DE LA LÓGICA DE BÚSQUEDA DEL SIGUIENTE JUGADOR VÁLIDO ---

                system("cls"); // Limpiar pantalla para un turno más limpio

                cout << "\n=========================================\n";
                cout << "Turno de " << nombres[turno] << endl;
                cout << "Tus cartas: " << endl;
                mostrarMano(manos[turno], CARTAS_POR_JUGADOR);

                

                    // Si después de intentar todos los jugadores, no se encuentra un jugador válido
                    if (contadorIntentosBusqueda == numJugadores) {
                        cout << "\n¡El juego ha terminado! No hay jugadores disponibles para jugar.\n";
                        juegoActivo = false;
                        break;
                    }

                    system("cls"); // Limpiar pantalla para un turno más limpio

                    cout << "\n=========================================\n";
                    cout << "Turno de " << nombres[turno] << endl;
                    cout << "Tus cartas: " << endl;
                    mostrarMano(manos[turno], CARTAS_POR_JUGADOR);

                    // Reclamar carta (la carta que el jugador en turno dice que va a tirar)
                    string reclamo;
                    // Bucle para validar la entrada del reclamo
                    while (true) {
                        cout << "¿Que carta reclamas tirar (Rey, Reina, As, Jocker)? ";
                        cin >> reclamo;
                        // Convertir a minúsculas para una comparación insensible a mayúsculas
                        transform(reclamo.begin(), reclamo.end(), reclamo.begin(), ::tolower);
                        if (reclamo == "rey" || reclamo == "reina" || reclamo == "as" || reclamo == "jocker") {
                            // Capitalizar la primera letra para que coincida con el mazo
                            reclamo[0] = toupper(reclamo[0]);
                            break;
                        } else {
                            cout << "Reclamo invalido. Por favor, ingrese Rey, Reina, As o Jocker.\n";
                        }
                    }

                    string carta_real_tirada_por_turno = ""; // Variable para guardar la carta real tirada.
                    int cantidad_tirar = 0;

                    // Pedir al jugador en turno qué carta quiere tirar realmente y cuántas.
                    // Bucle para validar la carta real tirada y la cantidad
                    while (true) {
                        cout << nombres[turno] << ", ¿que carta REALMENTE tiras de tu mano?: ";
                        cin >> carta_real_tirada_por_turno;
                        transform(carta_real_tirada_por_turno.begin(), carta_real_tirada_por_turno.begin() + 1, carta_real_tirada_por_turno.begin(), ::toupper); // Capitalizar la primera letra

                        int cartasDisponibles = contarCarta(manos[turno], CARTAS_POR_JUGADOR, carta_real_tirada_por_turno);
                        if (cartasDisponibles == 0) {
                            cout << "No tienes esa carta en tu mano. Por favor, elige una carta que tengas.\n";
                            continue;
                        }

                        cout << "¿Cuantas cartas de '" << carta_real_tirada_por_turno << "' quieres tirar (1-" << cartasDisponibles << ")? ";
                        cin >> cantidad_tirar;

                        if (cantidad_tirar >= 1 && cantidad_tirar <= cartasDisponibles) {
                            break;
                        } else {
                            cout << "Cantidad invalida. Debes tirar entre 1 y " << cartasDisponibles << " cartas de ese tipo.\n";
                        }
                    }

                    // Eliminar la carta tirada de la mano del jugador en turno.
                    eliminarCartas(manos[turno], CARTAS_POR_JUGADOR, carta_real_tirada_por_turno, cantidad_tirar);

                    cout << nombres[turno] << " ha tirado " << cantidad_tirar << " carta(s) y reclamado que eran: " << reclamo << endl;


                    // Los demás jugadores tiran UNA CARTA (pueden mentir)
                    // Este bloque se simplifica ya que el juego original solo se enfoca en el jugador principal
                    // y la creencia de los demás jugadores, no en lo que tiran individualmente.
                    // Si se quisiera implementar que los demás tiran y se puede delatar a cualquiera,
                    // se necesitaría un registro de lo que cada uno "declaró tirar" y "tiró realmente".
                    cout << "\nLos demas jugadores estan tirando sus cartas...\n";
                    // En esta versión, los demás jugadores no "tiran" cartas de sus manos.
                    // Solo el jugador en turno tira una carta real. Los demás reaccionan al reclamo.


                    // Espacio para probar la funcion de delatar a un jugador mentiroso
                    char respuesta_acusar;
                    int jugador_que_delata_index = -1; // Inicializar con un valor que indique que no se ha elegido
                    int jugador_delatado_index = turno; // Por defecto, se delata al jugador en turno

                    cout << "\n¿Alguien quiere acusar al jugador " << nombres[turno] << " de mentiroso? (S/N): ";
                    cin >> respuesta_acusar;

                    while (respuesta_acusar != 's' && respuesta_acusar != 'S' && respuesta_acusar != 'n' && respuesta_acusar != 'N') {
                        cout << "Has ingresado una respuesta incorrecta. Ingresa (S) o (N): ";
                        cin >> respuesta_acusar;
                    }

                    system("cls"); // cls

                    if (respuesta_acusar == 's' || respuesta_acusar == 'S') {
                        cout << "Seleccione su nombre de jugador para acusar:" << endl;
                        for (int i = 0; i < numJugadores; i++) {
                            if (i != turno) { // No se puede acusar a sí mismo
                                cout << i + 1 << ". " << nombres[i] << endl;
                            }
                        }
                        cin >> jugador_que_delata_index;
                        jugador_que_delata_index--; // Ajustar índice.

                        while (jugador_que_delata_index < 0 || jugador_que_delata_index >= numJugadores || jugador_que_delata_index == turno) {
                            if (jugador_que_delata_index == turno) {
                                cout << "No puedes delatarte a ti mismo. ";
                            }
                            cout << "Seleccione un jugador valido para acusar: ";
                            cin >> jugador_que_delata_index;
                            jugador_que_delata_index--;
                        }

                        system("cls"); // cls

                        // Proceso en el que se comprueba si la acusacion es verdadera
                        cout << nombres[jugador_que_delata_index] << " ha acusado a " << nombres[jugador_delatado_index] << " de mentiroso." << endl;
                        cout << nombres[jugador_delatado_index] << " dijo que tiro la carta: '" << reclamo << "'" << endl;
                        cout << "Y REALMENTE tiro la carta: '" << carta_real_tirada_por_turno << "'" << endl;

                        // Lógica de VERIFICACIÓN (basada en el reclamo y la carta real tirada por el jugador en turno)
                        bool esMentira = (reclamo != carta_real_tirada_por_turno);

                        if (esMentira) {
                            // Acusador acertó, el jugador en turno MINTIÓ.
                            cout << "\n¡Acusacion correcta! " << nombres[jugador_delatado_index] << " mintio." << endl;
                            cout << nombres[jugador_delatado_index] << " pierde el siguiente turno." << endl;
                            turnosPerdidos[jugador_delatado_index] = true;
                        } else {
                            // Acusador se equivocó, porque el jugador en turno SÍ dijo la verdad.
                            cout << "\n¡Acusacion incorrecta! " << nombres[jugador_delatado_index] << " no mintio." << endl;
                            cout << nombres[jugador_que_delata_index] << " pierde el siguiente turno." << endl;
                            turnosPerdidos[jugador_que_delata_index] = true;
                        }
                    }

                    // Verificar si el jugador actual se quedó sin cartas
                    int cartasRestantesEnMano = 0;
                    for (int k = 0; k < CARTAS_POR_JUGADOR; ++k) {
                        if (manos[turno][k] != "") {
                            cartasRestantesEnMano++;
                        }
                    }

                    if (cartasRestantesEnMano == 0) {
                        cout << "\n¡Felicidades, " << nombres[turno] << " se ha quedado sin cartas y ha ganado la ronda!\n";
                        guardar_puntuacion(nombres[turno]); // Guardar puntuación al ganar
                        juegoActivo = false; // Terminar la ronda
                    } else {
                        // Se avanza al siguiente turno.
                        turno = (turno + 1) % numJugadores;
                    }

                    cout << "\nPresione Enter para continuar al siguiente turno o al menu principal...\n";
                    cin.ignore();
                    cin.get();
                } // Fin del while (juegoActivo)
                break;
            } // Fin case 1

            case 2:
                cargar_tabla_de_puntos();
                cout << "\nPresione Enter para salir al menu principal..." << endl;
                cin.ignore(); // Limpiar el buffer de entrada
                cin.get();    // Esperar a que el usuario presione Enter
                break;

            case 3:
                cout << "\n¡Gracias por jugar a La Mesa de los Mentirosos! Hasta pronto.\n";
                break;
        } // Fin switch menu principal
    } while (opcion != 3);

    return 0;
}