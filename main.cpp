//Incorporacion del archivo def.cpp
#include "src/header.h"

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
            system("cls");//cls

            //Jugadores a delatar
            cout<<"A que jugador deseas delatar?"<<endl;
            for(int i=0; i<numJugadores; i++){
                cout<<i+1<<". "<<nombres[i]<<endl;
            }
            cin>>jugador_delatado;

             while(jugador_delatado<1 || jugador_delatado>numJugadores || jugador_delatado==jugador_que_delata){
                if(jugador_delatado==jugador_que_delata){
                    cout<<"No te puedes delatar a ti mismo"<<endl;
                }
                cout<<"Seleccione un jugador valido"<<endl;
                for(int i=0; i<numJugadores; i++){
                cout<<i+1<<". "<<nombres[i]<<endl;
            }
                cin>>jugador_delatado;
            }
            //Fin jugador a delatar
            //Proceso en el que se comprueba si la acusacion es verdadera
            cout<<"El jugador "<<nombres[jugador_que_delata-1]<<" ha acusado a "<<nombres[jugador_delatado-1]<<" de mentiroso."<<endl;
            }
        //Fin espacio para la funcion
        
    return 0;
}


