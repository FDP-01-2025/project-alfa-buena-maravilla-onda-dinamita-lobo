//Incorporacion del archivo def.cpp
#include "def.cpp"

int main (){
    srand(time(0));
    int numJugadores;
    bool juegoActivo = true;
    int turno = 0;
    string nombres[MAX_JUGADORES];
    string manos[MAX_JUGADORES][CARTAS_POR_JUGADOR];

    // damos la bienvenida a los usuarios , con codigo ascii para que sea bonito tambien
    cout << "╔══════════════════════════════════════════════════════╗\n";
    cout << "║        Bienvenido a la mesa de los mentirosos!      ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";
    cout << "El mazo de cartas contiene: Rey, Reina, As y Jocker.\n";
    cout << "Cada jugador recibira 5 cartas al inicio del juego.\n";
    cout << "El juego comenzara con un jugador reclamando una carta, los demas jugadores podran ingresar que cartas de su mano quieren tirar.\n";
    cout << "Si el jugador que reclama tiene 3 cartas de la que reclamo, gana, si no, pierde.\n";
    cout << "El juego continuara hasta que un jugador se quede sin cartas o nunca mienta.\n";
    cout << "Presione Enter para comenzar el juego..." << endl;
    cin.ignore();

    //los jugadores no pueden ser menos de 2 por lo que preguntamos y de una comprobamos
     // Número de jugadores
    cout << "Cuantos jugadores participaran en el juego? (2-4 jugadores): ";
    cin >> numJugadores;
    while (numJugadores < 2 || numJugadores > 4) {
        cout << "Numero de jugadores invalido. Por favor ingrese un numero entre 2 y 4: ";
        cin >> numJugadores;
    }

    //pedimos los nombres de los jugadores para referirnos a ellos 
    cout << "Ingresa los nombres de los jugadores:" << endl;
    for (int i = 0; i < numJugadores; i++) {
        cout << "Jugador " << (i + 1) << ": ";
        cin >> nombres[i];
    }

    //llamamos las funciones para abrajear y repartir
    // Barajar y repartir cartas
    barajarMazo(mazo, TOTAL_CARTAS);
    repartirCartas(manos, numJugadores, mazo);

