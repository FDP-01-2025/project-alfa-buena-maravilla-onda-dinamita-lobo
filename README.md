[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# 🎮 The Table of Liars

# 🎭 Theme and Setting
The Table of Liars is a card game centered around deception, suspicion, and strategy. Set at a fictional table, players must either deceive others or figure out who is lying. Each round challenges the player's ability to bluff, accuse, or defend themselves in a controlled environment. When placing their cards, players must convince others that what they played is truly the requested card.

# 📝 Description
"The Liars' Table" is a game designed for 2 to 4 players, where each player is dealt 5 cards.
The deck contains Kings, Queens, Aces, and a single Joker, all shuffled and distributed randomly. The table (or a player in turn order) will request a specific card (King, Queen, Ace, or Joker). All other players must then place 1 to 3 cards face down (never 4 or 5).
After the cards are placed, players have the option to trust the active player or accuse them of being a LIAR.
If the player does have at least one of the requested cards, the accuser loses the round.
If the player does not have the requested card, the active player loses the round.
After each round:
All cards are returned to the deck, reshuffled, and re-dealt.
The player who lost the round is temporarily removed from the next one and must complete a punishment or challenge.
The game is implemented in C++, using:

  -Functions
  
  -Arrays
  
  -Control structures: if, else, while, do-while, for, and switch

# 🕹️ Core Mechanics
-2 to 4 players are each dealt 5 random cards.

-The deck includes Kings, Queens, Aces, and 1 Joker.

-A player or the table requests a specific card.

-Other players must place 1 to 3 face-down cards.

-Other players may accuse the active player of lying.

-If the player has at least one of the requested card: the accuser loses.

-If the player doesn't have the requested card: the player loses.

-The losing player sits out for the next round and must complete a challenge or punishment.

# 🧠 General Gameplay Idea
The main goal is to stay in the game as long as possible using strategy and deception. The game resets with a fresh hand of cards each round. A player is temporarily removed after losing a round. The last remaining player is the winner.

# 💡 Application of Programming Concepts (with examples)
*Constants*
![image](https://github.com/user-attachments/assets/3ac31978-0a74-4546-b738-eedf311b1a8f)

  -MAX_JUGADORES: Maximum number of players allowed in a match.

  -CARTAS_POR_JUGADOR: Number of cards each player gets.

  -TOTAL_CARTAS: Total cards in the deck, including duplicates.

*functions to be used*
![image](https://github.com/user-attachments/assets/bdcc120a-b5a9-4a0c-9cee-d2112f154070)

🔁 Card Operations:
  -barajarMazo(): Shuffles the deck randomly using modern C++ generators.

  -repartirCartas(): Distributes cards to all players.

  -contarCarta(): Counts how many cards of a certain type a player has.

  -eliminarCartas(): Removes specific cards from a player's hand.

  🎴 ASCII Display
  -mostrarCartaASCII(): Renders the ASCII art for a given card.

  -mostrarMano(): Displays all cards in a player’s hand horizontally.

  🏆 Scoreboard Functions
  -cargar_tabla_de_puntos(): Loads and displays scores from puntuaciones.txt.

  -guardar_puntuacion(nombre): Increments and saves a player’s win in the score file.
  
  *Deck Setup*
The deck is represented as an array of strings with the following cards.
![image](https://github.com/user-attachments/assets/fe7ef5f6-ce9a-414e-a13b-19b165ea9837)



*ASCII Art Rendering*
Each card is drawn with a unique ASCII art style using a vector<string> in the function obtenerCartaASCII. Cards are printed horizontally using the mostrarMano() function.
![image](https://github.com/user-attachments/assets/62a6a839-5c6c-40d0-8185-b07f93bb2703)



# ⚙️ Technical Considerations of Development
  -Programming Language: C++
  
  -Editor Used: Visual Studio Code
  
  -Compiler: g++

# 📚 Libraries Used:
![image](https://github.com/user-attachments/assets/f96f6eb6-9c28-461a-b0fd-4b832b269829)

  -#include iostream: Input and output
  
  -#include string: Strings for card names, player names
  
  -#include cstdlib: For rand(), system(), etc.
  
  -#include vector: Used to store and render ASCII art of cards
  
  -#include windows.h: For manipulating console encoding on Windows
  
  -#include ctime: For random seeding with time
  
  -#include fstream: File operations for score saving/loading
  
  -#include algorithm: For shuffle
  
  -#include random: Modern random number generators
  
  -using namespace std: Allows you to write cout instead of std::cout, etc.

# Imágenes o mockups del juego

## **Developer team name:**
- project alfa buena maravilla onda dinamita lobo
### **Team members' names:**
1. **Name** Ricardo Ernesto Iglesias Flores 
   **Student id:** 00000725

2. **Name** Gael Alexander Martinez Alas 
   **Student id:** 00033625

3. **Name** Daniel Alejandro Lopez Ruano 
   **Student id:** 00156625
   
4. **Name** Roque Ignacio Flores Jovel 
   **Student id:** 00017525
   
## 🏁 How to Run the game
Clone the repo:


![image](https://github.com/user-attachments/assets/b9f31083-aa17-48ba-b9b8-268a248bb2c1)


git clone https://github.com/yourusername/la-mesa-de-los-mentirosos.git
cd "project-alfa-buena-maravilla-onda-dinamita-lobo"
Compile using any C++ compiler. 
with g++:


![image](https://github.com/user-attachments/assets/3d710f35-01c1-41ad-8964-1481835aae99)


g++ -o game main.cpp
Run the game:


![image](https://github.com/user-attachments/assets/0fec167b-f786-40bc-8e52-84378d83cad4)


./game
