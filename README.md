[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# 🎮 La Mesa de los Mentirosos
# 🎭 Tema y Ambientación
La Mesa de los Mentirosos es un juego de cartas centrado en el engaño, la sospecha y la estrategia. Ambientado en una mesa ficticia, los jugadores deben engañar a los demás o descubrir quién está mintiendo. Cada ronda pone a prueba la habilidad del jugador para engañar, acusar o defenderse en un entorno controlado. Al colocar sus cartas, los jugadores deben convencer a los demás de que la carta que pusieron realmente es la que se pidió.

# 📝 Descripción
"La Mesa de los Mentirosos" es un juego diseñado para 2 a 4 jugadores, donde a cada uno se le reparten 5 cartas.
El mazo contiene Reyes, Reinas, Ases y un solo Joker, todos barajados y distribuidos al azar.
La mesa (o un jugador por turno) pedirá una carta específica (Rey, Reina, As o Joker).
Los demás jugadores deben colocar entre 1 y 3 cartas boca abajo (nunca 4 o 5).

Después de colocar las cartas, los jugadores tienen la opción de confiar en el jugador activo o acusarlo de ser un MENTIROSO.
  -Si el jugador tiene al menos una carta de la solicitada, el acusador pierde la ronda.
  -Si el jugador no tiene la carta solicitada, el jugador activo pierde la ronda.
  
Después de cada ronda:
  -Todas las cartas se regresan al mazo, se barajan y se reparten de nuevo.
  -El jugador que pierde la ronda queda temporalmente fuera de la siguiente y debe cumplir un castigo o reto.
  
El juego está implementado en C++, utilizando:

-Funciones

-Arreglos

Estructuras de control: 
  -if
  
  -else
  
  -while
  
  -do-while
  
  -for
  
  -switch

# 🕹️ Mecánicas Básicas
-De 2 a 4 jugadores reciben 5 cartas aleatorias.

-El mazo incluye Reyes, Reinas, Ases y 1 Joker.

-Un jugador o la mesa pide una carta específica.

-Los demás jugadores colocan entre 1 y 3 cartas boca abajo.

-Los demás jugadores pueden acusar al jugador activo de mentir.

-Si el jugador tiene al menos una carta pedida: el acusador pierde.

-Si el jugador no tiene la carta pedida: el jugador pierde.

-El jugador que pierde se salta la siguiente ronda y debe cumplir un reto o castigo

# 🧠 Idea General del Juego
El objetivo principal es mantenerse en el juego el mayor tiempo posible usando estrategia y engaño. El juego se reinicia con una nueva mano de cartas en cada ronda. Un jugador se elimina temporalmente tras perder una ronda. El último jugador en pie es el ganador.

# 💡Aplicación de Conceptos de Programación
*Constantes*
Tema no visto en clase pero investigado para poder plantear la cantidad de cartas que se podra tener en el juego.

![image](https://github.com/user-attachments/assets/3ac31978-0a74-4546-b738-eedf311b1a8f)

  -MAX_JUGADORES: Número máximo de jugadores permitidos en una partida.

  -CARTAS_POR_JUGADOR: Número de cartas que recibe cada jugador.

  -TOTAL_CARTAS: Total de cartas en el mazo, incluyendo duplicados.

*Funciones a utilizar*
![image](https://github.com/user-attachments/assets/bdcc120a-b5a9-4a0c-9cee-d2112f154070)

🔁 Operaciones con Cartas:
Funciones planteadas para poder facilitar el uso en el main, cada funcion realizara algo especifico en el juego

  -barajarMazo(): Baraja el mazo de forma aleatoria.

  -repartirCartas(): Reparte las cartas a todos los jugadores.

  -contarCarta(): Cuenta cuántas cartas de un tipo tiene un jugador.

  -eliminarCartas(): Elimina cartas específicas de la mano de un jugador.

🎴 Visualización ASCII

  -mostrarCartaASCII(): Muestra el arte ASCII de una carta específica.

  -mostrarMano(): Muestra horizontalmente todas las cartas de un jugador.

🏆 Funciones de Puntuación

cargar_tabla_de_puntos(): Carga y muestra las puntuaciones desde puntuaciones.txt.

guardar_puntuacion(nombre): Incrementa y guarda la victoria de un jugador en el archivo de puntuaciones.
  
  *Realizacion del mazo*
El mazo se representa como un arreglo de strings con las siguientes cartas:
![image](https://github.com/user-attachments/assets/fe7ef5f6-ce9a-414e-a13b-19b165ea9837)



*Arte ASCII*
Cada carta se dibuja con un estilo ASCII  utilizando un vector<string> en la función obtenerCartaASCII. Las cartas se imprimen horizontalmente con mostrarMano().
![image](https://github.com/user-attachments/assets/62a6a839-5c6c-40d0-8185-b07f93bb2703)



# ⚙️ Technical Considerations of Development
  -Lenguaje de programacion en C++
  
  -Editor usado: Visual studio code
  
  -Compilador para C++, como por ejemplo G++

# 📚 Libraries Used:
![image](https://github.com/user-attachments/assets/f96f6eb6-9c28-461a-b0fd-4b832b269829)


  -#include iostream: Entrada y salida estándar

  -#include string: Cadenas para nombres de cartas y jugadores

  -#include cstdlib: Para rand(), system(), etc, usado mas que todo en system().

  -#include vector: Usado para almacenar y mostrar el arte ASCII de las cartas

  -#include windows.h: Para manipular la codificación de consola en Windows

  -#include ctime: Para semillas aleatorias basadas en el tiempo

  -#include fstream: Operaciones con archivos para guardar/cargar puntuaciones

  -#include algorithm: Para usar shuffle

  -#include random: Generadores modernos de números aleatorios

  -using namespace std: Permite escribir cout en lugar de std::cout, etc.

# Imágenes o mockups del juego

## **Nombre de el equipo**
- project alfa buena maravilla onda dinamita lobo
### **Team members' names:**
1. **Nombre** Ricardo Ernesto Iglesias Flores 
   **Carnet:** 00000725

2. **Nombre** Gael Alexander Martinez Alas 
   **Carnet:** 00033625

3. **Nombre** Daniel Alejandro Lopez Ruano 
   **Carnet** 00156625
   
4. **Nombre** Roque Ignacio Flores Jovel 
   **Carnet** 00017525
   
## 🏁 Como correr el juego
Clona el repo:


![image](https://github.com/user-attachments/assets/b9f31083-aa17-48ba-b9b8-268a248bb2c1)

git clone https://github.com/yourusername/la-mesa-de-los-mentirosos.git
cd "project-alfa-buena-maravilla-onda-dinamita-lobo"
Compilalo con el compilador de C++. 

Con g++:


![image](https://github.com/user-attachments/assets/3d710f35-01c1-41ad-8964-1481835aae99)

g++ -o game main.cpp
Luego corre el juego:


![image](https://github.com/user-attachments/assets/0fec167b-f786-40bc-8e52-84378d83cad4)

./game
