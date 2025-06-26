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
#include <ctime>
using namespace std;

//determinamos unas constantes, para tener el numeros de cartas 
const int MAX_JUGADORES = 4;
const int CARTAS_POR_JUGADOR = 5;
const int TOTAL_CARTAS = 16;

//desarrollo de tarjetas
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

//hacemor una funcion para comprobar las cartas que tendra cada jugador
int contarCarta(string mano[], int tam, string carta) {
    int cont = 0;
    for (int i = 0; i < tam; i++) {
        if (mano[i] == carta) cont++;
    }
    return cont;
}

//cuando un jugador tire una carta, hacemos una funcion para que este elimine dicha carta
void eliminarCartas(string mano[], int tam, string carta, int cantidad) {
    for (int i = 0; i < tam && cantidad > 0; i++) {
        if (mano[i] == carta) {
            mano[i] = "";
            cantidad--;
        }
    }
}

//empezamos a trabajar en el main
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

    //iniciamos el juego
    while (juegoActivo) {
        cout << "\n═══════════════════════════════════════════════════════\n";
        cout << "Turno de " << nombres[turno] << endl;
        cout << "Tus cartas: " << endl;
        mostrarMano(manos[turno], CARTAS_POR_JUGADOR);

        // Reclamar carta
        string reclamo;
        cout << "¿Qué carta reclamas (Rey, Reina, As, Jocker)? ";
        cin >> reclamo;

        // Los demás jugadores tiran cartas (pueden mentir)
        for (int j = 0; j < numJugadores; j++) {
            if (j == turno) continue;
            cout << nombres[j] << ", estas son tus cartas:" << endl;
            mostrarMano(manos[j], CARTAS_POR_JUGADOR);
            cout << nombres[j] << ", ¿cuántas cartas quieres tirar como '" << reclamo << "'? ";
            int cantidad;
            cin >> cantidad;
            eliminarCartas(manos[j], CARTAS_POR_JUGADOR, reclamo, cantidad);
        }
        //Espacio para probar la funcion de delatar un jugador mentiroso
        /*Las variables hay que moverlas, se encuentran acá como una simple prueba y
        comodidad a la hora de codificar.
        La funcion de system("cls") es para limpiar la consola.*/
        char respuesta;
        int jugador_que_delata;
        int jugador_delatado;

        cout<<"Alguien quiere acusar? (S/N)"<<endl;
        cin>>respuesta;
        
        while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N') {
            cout << "Has ingresado una respuesta incorrecta. Ingresa (S) o (N): ";
            cin >> respuesta;
            system("cls");//cls
        }
        if(respuesta == 's' || respuesta == 'S'){
            cout<<"Seleccione su nombre de jugador"<<endl;
            for(int i=0; i<numJugadores; i++){
                cout<<i+1<<". "<<nombres[i]<<endl;
            }
            cin>>jugador_que_delata;
            system("cls");//cls
            while(jugador_que_delata<1 || jugador_que_delata>numJugadores){
                system("cls");//cls
                cout<<"Seleccione un jugador valido"<<endl;
                cin>>jugador_que_delata;
            }
            system("cls");//cls}
            
            }
    return 0;
}

