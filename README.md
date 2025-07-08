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



*Arte ASCII y interfaz en la terminal*
Cada carta se dibuja con un estilo ASCII  utilizando un vector<string> en la función obtenerCartaASCII. Las cartas se imprimen horizontalmente con mostrarMano().
![image](https://github.com/user-attachments/assets/62a6a839-5c6c-40d0-8185-b07f93bb2703)



# ⚙️ Technical Considerations of Development
  -Lenguaje de programacion en C++
  
  -Editor usado: Visual studio code
  
  -Compilador para C++, como por ejemplo G++

# Uso de if, else, else if
El uso de el if, else y else if fue muy ocupado en toda la logica de el juego mas que todo en las funciones, iniciando desde el arte ASCII, se empezo a utilizar dicha condicional, para poder imprimir de manera correcta el arte.

![image](https://github.com/user-attachments/assets/d5bd6eee-eb68-4f6e-aa30-a6f1061812e1)


Tambien se le dio uso en la funcion de "show hand" en la que   ponemos una condicion en la que toma que todas las cartas tienen el mismo numero de lineas para la representacion de el arte ACII, 
asi como para conficiones en ciclos for en la misma funcion, al igual que en funciones conmo " Count Card", "remove cards", "LoadScoreTable", "Save score" y en el string "deck" todo eso en el archivio def.cpp en la carpeta src:

![image](https://github.com/user-attachments/assets/cab4b960-b7a9-4156-a420-6ee76d180943)


# Uso de For
El uso de ciclos for fue parte importante del proyecto, ya que gracias a esto teniamos la posibilidad de:

1.Repartir las cartas segun la cantidad de jugadores.

![image](https://github.com/user-attachments/assets/88410843-ea8d-40cd-903c-ed2f0d457eb5)


2.Mostrar nuestras cartas de forma horizontal e imprimir dichas cartas.

![image](https://github.com/user-attachments/assets/83620eda-3a5c-496a-8e52-ff0252e6566c)


3.Comprobar las cartas otorgadas a cada jugador.

![image](https://github.com/user-attachments/assets/afb869e9-8e89-42bf-8421-ad09cc46ab63)

4.Comprobar las cartas a eliminar y evitar que nuestro ASCII se deforme.

![image](https://github.com/user-attachments/assets/9c03bfe1-e5da-4c71-8625-0156c7907e64)

5.Para actualizar y guardar el numero de victorias o puntos de cada jugador registrado.

![image](https://github.com/user-attachments/assets/bc8c311e-7d26-47e1-9d1d-bbe66f75139c)

Todo lo anterior se muestra dentro de nuestro archivo def.cpp, ubicado en la carpeta src. Ahora veremos las implementaciones en nuestro archivo main.cpp, ubicado en la raiz del proyecto.

6.Por medio de un for solicitamos los nombre de los jugadores, ya que con esto se guardará en su arreglo correspondiente.

![image](https://github.com/user-attachments/assets/924dc69d-5dd9-48ce-b97d-768c4cdbcc1f)

7.El for tambien nos permitió llevar el conteo de jugadores restantes con cartas y de ésta forma determinar un ganador.

![image](https://github.com/user-attachments/assets/3ab31f1c-b24b-4f4a-8424-cdbf10d1c0ee)

8.Otra de sus implementaciones fue verificar las cartas disponibles de un jugador no penalizado.

![image](https://github.com/user-attachments/assets/2d76bf50-a8b1-4074-9ec8-b8a8bcb01f6f)

9.Por último, su implementación nos ayudo a mostrar la lista de jugadores disponibles y con ello determinar quien deseaba acusar al jugador en turno.

![image](https://github.com/user-attachments/assets/418192d4-d278-4697-84c4-9a93680d1229)




# Uso de los swich
El switch es una estructura de control que se implementó durante el proyecto una vez, pero que forma parte importante de este al momento de estar en su menú principal. Su utilidad es dividir en 3 opciones nuestro menú de juego (1.Jugar, 2.Tabla de puntuaciones, 3.Salir).

1.En el primer caso tenemos la opcion de juego, al seleccionarle este ejecuta todo el codigo principal que permite la jugabilidad del proyecto.
![image](https://github.com/user-attachments/assets/a97dbabb-abbf-4a5c-90d4-f57df82b86b0)

2.En el segundo caso, el switch nos ayudó a cargar la tabla de puntuaciones de nuestro juego.
![image](https://github.com/user-attachments/assets/a65305c4-3301-4afb-8807-fe4e4dea2cc2)

3.Y por último, en el tercer caso, éste muesra un mensaje de agradecimiento al salir del juego.
![image](https://github.com/user-attachments/assets/ea654da9-ab1b-4102-8780-f992c4cc748f)




# Uso de while y do while
El uso de estos bucles nos sirvió en gran medida para la validacion de respuestas y encerrar en un rango de opciones al jugardor.

1.Primeramente el uso de do while, éste nos permitio hacer la ejecución del juego tantas veces el jugador lo desee, siempre y cuando este no ejecute la opcion 3 (salir).

![image](https://github.com/user-attachments/assets/f2fbde5d-7881-40bc-ba04-f4288cd06419)


![image](https://github.com/user-attachments/assets/a13b3efc-783b-4788-9fd4-63b5cae33f32)

2. El uso de los while, como se comentaba antes, fue necesario para la validacion de respuestas y permitir la seleccion de opciones que nosotros ofrecemos al jugador.
   
   ![image](https://github.com/user-attachments/assets/7220786b-f45c-4241-add0-ab66fd3d201a)

   
   ![image](https://github.com/user-attachments/assets/459ed496-5482-4734-a1ea-a3f3ca1a88d9)

   
   ![image](https://github.com/user-attachments/assets/1cfe0e00-f14a-46d4-8ac5-5a53001527b9)

   
   ![image](https://github.com/user-attachments/assets/6fd06c73-ea19-4a94-a4f2-f59353e4558e)

   
   ![image](https://github.com/user-attachments/assets/770844e3-1eb6-46c3-8997-be1331fae2fa)

   
   ![image](https://github.com/user-attachments/assets/8e99ba25-72cd-40c9-8ec5-a18ff0eb65ff)


5. Dentro de nuestro archivo def.cpp, el uso de while fue necesario para las funciones de getValidInteger, saveScore y loadScoreboard


![image](https://github.com/user-attachments/assets/a36c0e51-ead5-47ff-88ac-fc2d56c295aa)


En el caso de loadScoreboard nos ayudaba para insertar en un struct todos los nombres y puntos de los jugadores que habrian participado con anterioridad en el juego y asi mostrarlo en el menu de puntuaciones.


![image](https://github.com/user-attachments/assets/cad687b9-baa1-413f-a4df-df4bc565f842)


Y en el caso de saveScore, nos ayudaba a cargar la informacion que se encontraba en nuestro archivo txt para poder ser modificada con los puntos del nuevo ganador.


![image](https://github.com/user-attachments/assets/a52fe939-7fee-4286-beb6-8b641a72922b)



# Manejo de archivos
Para este punto constamos de 3 archivos muy importantes, como primer archivo, esta el main.cpp, se encuentra en la raiz principal del proyecto y es el encargado de ejecutar todas las funciones del codigo y mostrar los mensajes principales del juego.

![image](https://github.com/user-attachments/assets/13436c4e-a617-4f22-a463-2d9802f5f2b4)

Ejemplo de codigo que contiene main.cpp: 


![image](https://github.com/user-attachments/assets/7ff13f42-6039-432d-998e-3defe44a3262)


![image](https://github.com/user-attachments/assets/13babcdb-d89b-4025-9c48-b12a96c3a513)


![image](https://github.com/user-attachments/assets/b51d2f08-e423-46d6-a3a1-817ccdf4d518)


Por otra parte, dentro de nuestra carpeta src, contenemos dos archivos que permiten que la lógica del juego funcione correctamente, uno de ellos es el archivo header.h que funciona como cabecera del codigo y en donde se incorporan todas las librerias, variables globales y declaracion de funciones.

Imagen de la carpeta src con sus archivos correspondientes:


![image](https://github.com/user-attachments/assets/a171202c-3b7c-41a4-ab14-869940622ca3)

En uno de los casos mas importantes realizamos el uso de el manejo de archivos en la tabla de puntuaciones de los jugadores, el juego sera consiente de los jugadores y con ellos las partidas respectivas gandas, con eso buscamos crear un archivo de la siguiente manera:

![image](https://github.com/user-attachments/assets/fd75f045-7821-4587-86eb-8819ab14be3d)


Continuando tenemos el ejemplo de código que contiene header.h:


![image](https://github.com/user-attachments/assets/ff798449-f06e-48ac-a34b-4d6016653b29)


Y por ultimo tenemos nuestro archivo def.cpp, es el encargado de contener todas las funciones del código, éste si se encarga de la lógica del juego, dentro de él podemos encontrar funciones como: loadScoreboard, saveScore, getValidInteger, removeCards, etc.

Ejemplo de código que contiene def.cpp:


![image](https://github.com/user-attachments/assets/625338a4-7a73-40cf-af09-63d2d71e7c9e)


![image](https://github.com/user-attachments/assets/0e4db46e-60d8-48ae-83b1-17c8f950a0f2)


![image](https://github.com/user-attachments/assets/b40c1994-4f21-466a-8ea0-5df37c874d53)


![image](https://github.com/user-attachments/assets/45e2a03a-60d8-46ed-a4dd-20eaa020d3f2)



# 📚 Librarias Usadas:


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
Para poder presentar imagenes de nuestro juego haremos un estilo de pasos, en los que se mostraran

1.Primero presentamos al usuario un menu en el que se podra mover para poder saber si jugar, ver puntajes o salir

![image](https://github.com/user-attachments/assets/3c3a65c9-638c-47f2-9638-7716d7b4b615)

2. Para ver la tabla de puntuaciones el jugador debera haber jugado previamente de los contrario no podra, pero si elije jugar se le dara una pequeña decripcion de "La mesa de los mentirosos"

   ![image](https://github.com/user-attachments/assets/6d040efa-4545-4459-8ed2-ff6b668a16e8)

3.Una vez se presione enter, el jugador devera ingresar cuantos jugadores estaran y respectivamente el user o nombre que se pondra cada uno.


![image](https://github.com/user-attachments/assets/51b7b268-cfcc-48ca-a719-5ac3ada75323)


![image](https://github.com/user-attachments/assets/b4e14c46-45cb-46d2-825a-02b4fe565a8e)


4. Una vez ingresados los nombres, empezara el juegos se le daran a los jugadores turno por turno sus cartas y se les preguntara progresivamente que carta se reclamara, que carta tiraran, cuantas tiraran y si desean declarar a un mentiroso o no


![image](https://github.com/user-attachments/assets/6a09ab9a-ea6f-4657-bc9f-bd7939aef0f2)


![image](https://github.com/user-attachments/assets/72901ad9-2dcd-458d-b51c-b5e388ff12f7)


![image](https://github.com/user-attachments/assets/49115483-77db-4f7c-b53d-a3f731d006ca)


![image](https://github.com/user-attachments/assets/e41e8a59-a105-403a-aaba-ebdb495ee4f3)


5. si el jugador no declara un mentiroso seguiran los turnos asi sucesivamente hasta que un jugador tire todas sus cartas y gane.


![image](https://github.com/user-attachments/assets/12c5a221-0213-46e7-b55f-30c4c56824c8)

6. con eso se guardara el ganador y se podra ver la tabla de puntuaciones


![image](https://github.com/user-attachments/assets/fcd476c4-2278-4c61-af53-406e3779d6d6)

7.Pero si en la partida se quiere declarar un mentiroso entonces se dara un menu donde elijiran quien declara a quien y se corraborara si eso para, si es asi perdera turno.


![image](https://github.com/user-attachments/assets/3aca6bd7-b5c3-495f-95a8-8cbe36519d0d)

# Flujograma


![Mesa_mentirosos drawio](https://github.com/user-attachments/assets/1936e4fd-e38a-478b-b606-c1607f78e1cc)


## **Nombre de el equipo**
- project alfa buena maravilla onda dinamita lobo
### **Nombre de los integrantes del grupo:**
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
