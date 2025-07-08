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
    int opcion = 0;
    int numJugadores;
    bool juegoActivo = true;
    int turnoActual = 0; // El primer turno es para el jugador 0.
    string nombres[MAX_JUGADORES];
    string manos[MAX_JUGADORES][CARTAS_POR_JUGADOR];
    // Array para rastrear los turnos perdidos.
    bool turnosPerdidos[MAX_JUGADORES] = {false};


    do { //do
        cout << "\n=========================================\n";
        cout << "Bienvenido al juego: 'La Mesa de los Mentirosos'\n";
        cout << "=========================================\n";
        cout << " 1. Jugar\n 2. Tabla de puntuaciones\n 3. Salir\n";
        
        // Validación para la opción del menú principal
        cout<<"Ingrese una opcion: "; cin>>opcion;
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


        while (opcion < 1 || opcion > 3) {
            cout << "\n=========================================\n";
            cout << "Bienvenido al juego: 'La Mesa de los Mentirosos'\n";
            cout << "=========================================\n";
            cout << " 1. Jugar\n 2. Tabla de puntuaciones\n 3. Salir\n";
            cout<<"Opcion inválida. Ingrese una opcion correcta: "; cin>>opcion;
            
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

        switch (opcion) {
            case 1: { // Se utiliza un bloque para la declaración de variables dentro del case
                cout << "\n";
                cout << " || Bienvenido a la mesa de los mentirosos! ||\n";
                cout << "\n";
                cout << "El mazo de cartas contiene: Rey, Reina, As y Jocker (5 de cada uno, para un total de 20 cartas).\n";
                cout << "Cada jugador recibira " << CARTAS_POR_JUGADOR << " cartas al inicio del juego.\n";
                cout << "En tu turno, reclamaras una carta y decidiras cual tirar realmente. Los demas jugadores podran tirar una carta (pueden mentir).\n";
                cout << "Cualquier jugador puede acusar a otro de mentiroso. Si la acusacion es correcta, el mentiroso pierde el siguiente turno. Si es incorrecta, el acusador pierde el siguiente turno.\n";
                cout << "El juego termina cuando un jugador se queda sin cartas o no hay mas jugadores activos.\n";
                cout << "Presione Enter para comenzar el juego..." << endl;
                cin.get();    // Esperar a que el usuario presione Enter
                system("cls"); // Borra la consola

                // Número de jugadores con validación
                numJugadores = obtenerEnteroValido("¿Cuantos jugadores participaran en el juego? (2-4 jugadores): ");

                while (numJugadores < 2 || numJugadores > MAX_JUGADORES) {
                    numJugadores = obtenerEnteroValido("Numero de jugadores invalido. Por favor ingrese un numero entre 2 y 4: ");
                    system("cls"); // Borra la consola
                }

                // pedimos los nombres de los jugadores para referirnos a ellos
                cout << "Ingresa los nombres de los jugadores:" << endl;
                for (int i = 0; i < numJugadores; i++) {
                    cout << "Jugador " << (i + 1) << ": ";
                    cin >> nombres[i];
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer después de cin >> string
                }

                // llamamos las funciones para abrajear y repartir
                // Barajar y repartir cartas
                barajarMazo(mazo, TOTAL_CARTAS);
                repartirCartas(manos, numJugadores, mazo);

                // Reestablecer juegoActivo para la nueva partida
                juegoActivo = true;
                turnoActual = 0; // El juego siempre empieza con el jugador 0.
                for(int i = 0; i < MAX_JUGADORES; ++i) {
                    turnosPerdidos[i] = false;
                }

                while (juegoActivo) {
                    int jugadoresConCartas = 0;
                    int ultimoJugadorConCartas = -1;

                    // Contar jugadores con cartas y verificar condición de victoria/fin de juego
for (int i = 0; i < numJugadores; ++i) {
    int cartasActuales = 0;
    for (int j = 0; j < CARTAS_POR_JUGADOR; ++j) {
        if (manos[i][j] != "") {
            cartasActuales++;
        }
    }
    if (cartasActuales > 0) {
        jugadoresConCartas++;
        ultimoJugadorConCartas = i;
    } else {
        // Verificar si este jugador se quedó sin cartas (condición de victoria)
        cout << "\n¡Felicidades, " << nombres[i] << " se ha quedado sin cartas y ha ganado la ronda!\n";
        guardar_puntuacion(nombres[i]);
        juegoActivo = false;
        break;
    }
}

if (juegoActivo && jugadoresConCartas == 0) {
    cout << "\n¡El juego ha terminado! No quedan cartas en juego ni jugadores activos.\n";
    juegoActivo = false;
}
                    
                    // --- LÓGICA PARA DETERMINAR EL JUGADOR DEL TURNO ---
                    // Esta lógica asegura que 'turnoActual' siempre apunte al jugador correcto para el turno.
                    // Se itera hasta encontrar un jugador que NO esté penalizado y tenga cartas.
                    bool turnoEncontrado = false;
                    int intentosParaRotar = 0; // Contador para evitar bucles infinitos si todos pierden turnos/cartas
                    int jugadorCandidato = turnoActual; // Empieza la búsqueda desde el último jugador que tuvo el turno.

                    do {
                        jugadorCandidato = (jugadorCandidato + 1) % numJugadores; // Avanza al siguiente jugador
                        intentosParaRotar++;

                        // Si el jugador candidato está penalizado, se consume la penalización y se salta su turno.
                        if (turnosPerdidos[jugadorCandidato]) {
                            cout << "\n¡" << nombres[jugadorCandidato] << " pierde su turno por penalización!\n"; 
                            turnosPerdidos[jugadorCandidato] = false; // La penalización se cumple y se remueve.
                            // Continúamos buscando al siguiente jugador
                        } else {
                            // Si el jugador no está penalizado, verificamos si tiene cartas
                            int cartasDelJugador = 0;
                            for (int k = 0; k < CARTAS_POR_JUGADOR; ++k) {
                                if (manos[jugadorCandidato][k] != "") {
                                    cartasDelJugador++;
                                }
                            }

                            if (cartasDelJugador > 0) {
                                // ¡Se encontró un jugador válido para tomar este turno!
                                turnoActual = jugadorCandidato; // Actualizamos el 'turnoActual' global
                                turnoEncontrado = true;
                                break; // Salir del bucle do-while de búsqueda
                            } else {
                                // Si el jugador no tiene cartas (y no está penalizado), se salta su turno.
                                cout << "\n" << nombres[jugadorCandidato] << " no tiene mas cartas. Saltando su turno.\n";
                            }
                        }

                        // Si hemos dado una vuelta completa a todos los jugadores y no encontramos un turno válido
                        if (intentosParaRotar >= numJugadores) {
                            cout << "\n¡El juego ha terminado! No hay jugadores disponibles para jugar.\n";
                            juegoActivo = false;
                            break; // Salir del bucle do-while de búsqueda
                        }

                    } while (!turnoEncontrado); // Continúa buscando hasta encontrar un turno válido o terminar el juego

                    if (!juegoActivo) { // Si el juego se marcó como inactivo dentro del bucle de búsqueda
                        break; // Salir del bucle principal del juego
                    }
                    // --- FIN DE LA LÓGICA PARA DETERMINAR EL JUGADOR DEL TURNO ---
                    
                    system("cls");

                    cout << "\n=========================================\n";
                    cout << "Turno de " << nombres[turnoActual] << endl;
                    cout << "Tus cartas: " << endl;
                    mostrarMano(manos[turnoActual], CARTAS_POR_JUGADOR);

                    string reclamo;
                    while (true) {
                        cout << "¿Que carta reclamas tirar (Rey, Reina, As, Jocker)? ";
                        cin >> reclamo;
                        transform(reclamo.begin(), reclamo.end(), reclamo.begin(), ::tolower);
                        if (reclamo == "rey" || reclamo == "reina" || reclamo == "as" || reclamo == "jocker") {
                            reclamo[0] = toupper(reclamo[0]);
                            break;
                        } else {
                            system("cls");
                            cout << "\n=========================================\n";
                            cout << "Turno de " << nombres[turnoActual] << endl;
                            cout << "Tus cartas: " << endl;
                            mostrarMano(manos[turnoActual], CARTAS_POR_JUGADOR);
                            cout << "Reclamo invalido. Por favor, ingrese Rey, Reina, As o Jocker.\n";

                        }
                    }

                    string carta_real_tirada_por_turno = "";
                    int cantidad_tirar = 0;
                    system("cls");
                    cout << "\n=========================================\n";
                    cout << "Turno de " << nombres[turnoActual] << endl;
                    cout << "Tus cartas: " << endl;
                    mostrarMano(manos[turnoActual], CARTAS_POR_JUGADOR);
                    while (true) {
                        cout << nombres[turnoActual] << ", ¿que carta REALMENTE tiras de tu mano?: ";
                        cin >> carta_real_tirada_por_turno;
                        transform(carta_real_tirada_por_turno.begin(), carta_real_tirada_por_turno.begin() + 1, carta_real_tirada_por_turno.begin(), ::toupper);

                        int cartasDisponibles = contarCarta(manos[turnoActual], CARTAS_POR_JUGADOR, carta_real_tirada_por_turno);
                        if (cartasDisponibles == 0) {
                            system("cls");
                            cout << "\n=========================================\n";
                            cout << "Turno de " << nombres[turnoActual] << endl;
                            cout << "Tus cartas: " << endl;
                            mostrarMano(manos[turnoActual], CARTAS_POR_JUGADOR);
                            cout << "No tienes esa carta en tu mano. Por favor, elige una carta que tengas.\n";
                            continue;
                        }

                        // Validación para cantidad_tirar
                        cantidad_tirar = obtenerEnteroValido("¿Cuantas cartas de '" + carta_real_tirada_por_turno + "' quieres tirar (1-" + to_string(cartasDisponibles) + ")? ");

                        if (cantidad_tirar >= 1 && cantidad_tirar <= cartasDisponibles) {
                            break;
                        } else {
                            cout << "\n=========================================\n";
                            cout << "Turno de " << nombres[turnoActual] << endl;
                            cout << "Tus cartas: " << endl;
                            mostrarMano(manos[turnoActual], CARTAS_POR_JUGADOR);
                            cout << "Cantidad invalida. Debes tirar entre 1 y " << cartasDisponibles << " cartas de ese tipo.\n";
                        }
                    }

                    eliminarCartas(manos[turnoActual], CARTAS_POR_JUGADOR, carta_real_tirada_por_turno, cantidad_tirar);

                    cout << nombres[turnoActual] << " ha tirado " << cantidad_tirar << " carta(s) y reclamado que eran: " << reclamo << endl;

                    cout << "\nLos demas jugadores estan tirando sus cartas...\n";

                    char respuesta_acusar;
                    int jugador_que_delata_index = -1;
                    int jugador_delatado_index = turnoActual; // El jugador en turno es el acusado por defecto

                    cout << "\n¿Alguien quiere acusar al jugador " << nombres[turnoActual] << " de mentiroso? (S/N): ";
                    cin >> respuesta_acusar;

                    while (respuesta_acusar != 's' && respuesta_acusar != 'S' && respuesta_acusar != 'n' && respuesta_acusar != 'N') {
                        cout << "Has ingresado una respuesta incorrecta. Ingresa (S) o (N): ";
                        cin >> respuesta_acusar;
                    }

                    system("cls");

                    if (respuesta_acusar == 's' || respuesta_acusar == 'S') {
                        cout << "Seleccione su nombre de jugador para acusar:" << endl;
                        for (int i = 0; i < numJugadores; i++) {
                            if (i != turnoActual) { // No se puede acusar a sí mismo
                                cout << i + 1 << ". " << nombres[i] << endl;
                            }
                        }
                        // Validación para jugador_que_delata_index
                        jugador_que_delata_index = obtenerEnteroValido("Ingrese el numero del jugador que acusa: ");
                        jugador_que_delata_index--; // Ajustar índice.

                        while (jugador_que_delata_index < 0 || jugador_que_delata_index >= numJugadores || jugador_que_delata_index == turnoActual) {
                            if (jugador_que_delata_index == turnoActual) {
                                cout << "No puedes delatarte a ti mismo. ";
                            }
                            jugador_que_delata_index = obtenerEnteroValido("Seleccione un jugador valido para acusar: ");
                            jugador_que_delata_index--;
                        }

                        system("cls");

                        cout << nombres[jugador_que_delata_index] << " ha acusado a " << nombres[jugador_delatado_index] << " de mentiroso." << endl;
                        cout << nombres[jugador_delatado_index] << " dijo que tiro la carta: '" << reclamo << "'" << endl;
                        cout << "Y REALMENTE tiro la carta: '" << carta_real_tirada_por_turno << "'" << endl;

                        bool esMentira = (reclamo != carta_real_tirada_por_turno);

                        if (esMentira) {
                            // Acusador acertó, el jugador en turno MINTIÓ.
                            cout << "\n¡Acusacion correcta! " << nombres[jugador_delatado_index] << " mintio." << endl;
                            cout << nombres[jugador_delatado_index] << " pierde el siguiente turno." << endl;
                            turnosPerdidos[jugador_delatado_index] = true; // El mentiroso pierde el turno
                        } else {
                            // Acusador se equivocó, porque el jugador en turno SÍ dijo la verdad.
                            cout << "\n¡Acusacion incorrecta! " << nombres[jugador_delatado_index] << " no mintio." << endl;
                            cout << nombres[jugador_que_delata_index] << " pierde el siguiente turno." << endl;
                            turnosPerdidos[jugador_que_delata_index] = true; // El acusador incorrecto pierde el turno
                        }
                    }

                    cout << "\nPresione Enter para continuar al siguiente turno o al menu principal...\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada para cin.get()
                    cin.get();
                    system("cls"); // Borra la consola
                } // Fin del while (juegoActivo)
                break;
            } // Fin case 1

            case 2:
                cargar_tabla_de_puntos();
                cout << "\nPresione Enter para salir al menu principal..." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada para cin.get()
                cin.get();
                system("cls"); // Borra la consola
                break;

            case 3:
                cout << "\n¡Gracias por jugar a La Mesa de los Mentirosos! Hasta pronto.\n";
                break;
        } // Fin switch menu principal
    } while (opcion != 3);

    return 0;
}