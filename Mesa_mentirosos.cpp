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
const int MAX_JUGADORES = 4;
const int CARTAS_POR_JUGADOR = 4; // Se ajusta a 4 para mostrar 4 cartas.
const int TOTAL_CARTAS = 16;      // Se restaura a 16 cartas para el mazo completo.

// desarrollo de tarjetas
string mazo[TOTAL_CARTAS] = {
    "Rey", "Rey", "Rey", "Rey", "Rey",
    "Reina", "Reina", "Reina", "Reina", "Reina",
    "As", "As", "As", "As", "As",
    "Jocker"};

// Se modifica la función para obtener el arte ASCII como un vector de strings (una string por línea).
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
     for (int i = 0; i < n; i++)
    { // esto a travez de un bucle
          int j = rand() % n;
          string temp = m[i];
          m[i] = m[j];
          m[j] = temp;
        
    }
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
                  mano[i] = "";
                  cantidad--;
               
        }
         
    }
}
//Estructura y funcion de tabla de puntuaciones
struct puntos_jugadores{
    string nombre;
    int victorias;
};

void cargar_tabla_de_puntos(){
    ifstream tabla_puntos("archivo_prueba.txt");
    puntos_jugadores puntos;

    if(tabla_puntos.is_open()){
        cout<<"Nombre ---------- Victorias \n";
        while(tabla_puntos >> puntos.nombre >> puntos.victorias){
            cout<<puntos.nombre<<" -------------"<<
                puntos.victorias<<endl;
        }
        tabla_puntos.close();
    }else{
        cout<<"Error con el archivo";
    }
}

// Empezamos a trabajar en el main
int main()
{
      // Establece la codificación de la consola a UTF-8 para que los caracteres especiales se muestren correctamente.
   SetConsoleOutputCP(CP_UTF8);
      SetConsoleCP(CP_UTF8);

      srand(time(0));
      int opcion=0;
      int numJugadores;
      bool juegoActivo = true;
      int turno = 0;
      string nombres[MAX_JUGADORES];
      string manos[MAX_JUGADORES][CARTAS_POR_JUGADOR];
      // Array para rastrear los turnos perdidos.
      bool turnosPerdidos[MAX_JUGADORES] = {false};


  do{ //do
    cout << "Bienvenido al juego: 'La mesa de los mentirosos' \n";
    cout << " 1.Jugar \n 2.Tabla de puntuaciones \n 3.Salir";
    cout << "\n Ingrese una opcion: ";
    cin >> opcion;

    while (opcion < 1 || opcion > 3)
    {
        cout << "Bienvenido al juego: 'La mesa de los mentirosos'";
        cout << "1.Jugar \n 2.Tabla de puntuaciones \n 3.Salir";
        cout << "\n Ingrese una opcion correcta: ";
        cin >> opcion;
    }

    switch(opcion){
      case 1:
        // damos la bienvenida a los usuarios, con codigo ascii para que sea bonito tambien
   cout << "\n";
      cout << " || Bienvenido a la mesa de los mentirosos! ||\n";
      cout << "\n";
      cout << "El mazo de cartas contiene: Rey, Reina, As y Jocker.\n";
      cout << "Cada jugador recibira 5 cartas al inicio del juego.\n"; // Nota: En este código de demostración se repartirán 4 cartas.
      cout << "El juego comenzara con un jugador reclamando una carta, los demas jugadores podran ingresar que cartas de su mano quieren tirar.\n";
      cout << "Si el jugador que reclama tiene 3 cartas de la que reclamo, gana, si no, pierde.\n";
      cout << "El juego continuara hasta que un jugador se quede sin cartas o nunca mienta.\n";
      cout << "Presione Enter para comenzar el juego..." << endl;
      cin.ignore();

      // los jugadores no pueden ser menos de 2 por lo que preguntamos y de una comprobamos
   // Número de jugadores
   cout << "Cuantos jugadores participaran en el juego? (2-4 jugadores): ";
      cin >> numJugadores;

      while (numJugadores < 2 || numJugadores > 4)
    {
            cout << "Numero de jugadores invalido. Por favor ingrese un numero entre 2 y 4: ";
            cin >> numJugadores;
         
    }

      // pedimos los nombres de los jugadores para referirnos a ellos
   cout << "Ingresa los nombres de los jugadores:" << endl;
      for (int i = 0; i < numJugadores; i++)
    {
            cout << "Jugador " << (i + 1) << ": ";
            cin >> nombres[i];
         
    }

      // llamamos las funciones para abrajear y repartir
   // Barajar y repartir cartas
   barajarMazo(mazo, TOTAL_CARTAS);
      repartirCartas(manos, numJugadores, mazo);

      // INICIO DEL BLOQUE DE CÓDIGO AÑADIDO PARA LA DEMOSTRACIÓN
   // Este bloque asigna manualmente las cartas a la mano del primer jugador para
   // asegurar que se muestren en el orden solicitado.
   // Puedes comentar o eliminar este bloque para que el juego reparta cartas de forma aleatoria.
   if (numJugadores > 0)
    {
            manos[0][0] = "Rey";
            manos[0][1] = "Reina";
            manos[0][2] = "As";
            manos[0][3] = "Jocker";
         
    }
      // FIN DEL BLOQUE DE CÓDIGO AÑADIDO

   // iniciamos el juego
   while (juegoActivo)
    {
            // Lógica para saltar el turno si el jugador anterior perdió el turno.
     if (turnosPerdidos[turno])
        {
                  cout << "\n¡" << nombres[turno] << " pierde su turno por haber acusado incorrectamente!\n";
                  turnosPerdidos[turno] = false;      // El turno perdido solo dura una ronda.
                  turno = (turno + 1) % numJugadores; // Pasa al siguiente jugador.
                  continue;                           // Salta al siguiente ciclo del bucle.
               
        }

            cout << "\n=========================================\n";
            cout << "Turno de " << nombres[turno] << endl;
            cout << "Tus cartas: " << endl;
            mostrarMano(manos[turno], CARTAS_POR_JUGADOR);

            // Reclamar carta (la carta que el jugador en turno dice que va a tirar)
     string reclamo;
            cout << "¿Qué carta reclamas tirar (Rey, Reina, As, Jocker)? ";
            cin >> reclamo;

            string carta_real_tirada_por_turno = ""; // Variable para guardar la carta real tirada.
            
     // Pedir al jugador en turno qué carta quiere tirar realmente.
     cout << nombres[turno] << ", ¿qué carta REALMENTE tiras de tu mano?: ";
            cin >> carta_real_tirada_por_turno;

            // Eliminar la carta tirada de la mano del jugador en turno. Solo se tira 1 carta.
     eliminarCartas(manos[turno], CARTAS_POR_JUGADOR, carta_real_tirada_por_turno, 1);

            // Los demás jugadores tiran UNA CARTA (pueden mentir)
     for (int j = 0; j < numJugadores; j++)
        {
                  if (j == turno) continue; // Salta el turno del jugador actual.
                  cout << nombres[j] << ", estas son tus cartas:" << endl;
                  mostrarMano(manos[j], CARTAS_POR_JUGADOR);
                  cout << nombres[j] << ", ¿quieres tirar una carta como '" << reclamo << "'? (S/N): ";
                  char respuesta_tirar;
                  cin >> respuesta_tirar;
                  if (respuesta_tirar == 'S' || respuesta_tirar == 's')
            {
                        // Aquí solo se simula que tiran la carta, no se verifica qué tiran realmente.
         // Para la lógica de tu juego, solo nos importa la carta del jugador en turno.
         cout << nombres[j] << " ha tirado una carta." << endl;
                     
            }
               
        }

            // Espacio para probar la funcion de delatar a un jugador mentiroso
     char respuesta;
            int jugador_que_delata_index;
            int jugador_delatado_index;

            cout << "Alguien quiere acusar? (S/N): ";
            cin >> respuesta;

            while (respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
        {
                  cout << "Has ingresado una respuesta incorrecta. Ingresa (S) o (N): ";
                  cin >> respuesta;
               
        }

            system("cls"); // cls

            if (respuesta == 's' || respuesta == 'S')
        {
                  cout << "Seleccione su nombre de jugador:" << endl;
                  for (int i = 0; i < numJugadores; i++)
            {
                        cout << i + 1 << ". " << nombres[i] << endl;
                     
            }
                  cin >> jugador_que_delata_index;
                  jugador_que_delata_index--; // Ajustar índice.
                  system("cls");              // cls

                  while (jugador_que_delata_index < 0 || jugador_que_delata_index >= numJugadores)
            {
                        system("cls"); // cls
                        cout << "Seleccione un jugador valido" << endl;
                        cin >> jugador_que_delata_index;
                        jugador_que_delata_index--;
                     
            }

                  system("cls"); // cls

                  // Jugadores a delatar
       cout << "¿A qué jugador deseas delatar?" << endl;
                  // Mostramos a todos los jugadores excepto al acusador.
       for (int i = 0; i < numJugadores; i++)
            {
                        if (i != jugador_que_delata_index)
                {
                              cout << i + 1 << ". " << nombres[i] << endl;
                           
                }
                     
            }
                  cin >> jugador_delatado_index;
                  jugador_delatado_index--; // Ajustamos el índice.

                  while (jugador_delatado_index < 0 || jugador_delatado_index >= numJugadores || jugador_delatado_index == jugador_que_delata_index)
            {
                        if (jugador_delatado_index == jugador_que_delata_index)
                {
                              cout << "No te puedes delatar a ti mismo" << endl;
                           
                }
                        cout << "Seleccione un jugador valido" << endl;
                        for (int i = 0; i < numJugadores; i++)
                {
                              if (i != jugador_que_delata_index)
                    {
                                    cout << i + 1 << ". " << nombres[i] << endl;
                                 
                    }
                           
                }
                        cin >> jugador_delatado_index;
                        jugador_delatado_index--;
                     
            }

                  system("cls"); // cls

                  // Proceso en el que se comprueba si la acusacion es verdadera
       cout << "El jugador " << nombres[jugador_que_delata_index] << " ha acusado a " << nombres[jugador_delatado_index] << " de mentiroso." << endl;
                  cout << nombres[jugador_delatado_index] << " dijo que tiró la carta: '" << reclamo << "'" << endl;
                  cout << "Y REALMENTE tiró la carta: '" << carta_real_tirada_por_turno << "'" << endl;

                  // Lógica de VERIFICACIÓN
       // La acusación se basa en la declaración (reclamo) vs. la carta real tirada.
       if (reclamo == carta_real_tirada_por_turno)
            {
                        // Acusador se equivocó, porque el jugador SÍ dijo la verdad.
         cout << "\n¡Acusación incorrecta! " << nombres[jugador_delatado_index] << " no mintió." << endl;
                        cout << nombres[jugador_que_delata_index] << " pierde el siguiente turno." << endl;
                        turnosPerdidos[jugador_que_delata_index] = true;
                     
            }
            else
            {
                        // Acusador acertó, el jugador MINTIÓ.
         cout << "\n¡Acusación correcta! " << nombres[jugador_delatado_index] << " mintió." << endl;
                        cout << nombres[jugador_delatado_index] << " pierde el siguiente turno." << endl;
                        turnosPerdidos[jugador_delatado_index] = true;
                     
            }
               
        }

            // Se avanza al siguiente turno.
     turno = (turno + 1) % numJugadores;
         
    }

      break;

    case 2:
        cargar_tabla_de_puntos();
        cout << "Presione Enter para salir..." << endl;
        cin.ignore();
        break;
    } // Fin switch menu principal
    }
    while(opcion!=3);
    // fin switch menu principal
      
      return 0;
}
