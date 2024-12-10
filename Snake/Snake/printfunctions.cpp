const short WIDTH = 20; 
const short HEIGHT = 10;  

#include<iostream>
#include"visualitems.h"
void print_table(char tablero[HEIGHT][WIDTH]) {
    //creo un array con los símbolos para construir la tabla visualmente
    char symbols[2] = { '-','|' };
    ASCIIsnake();
    visuals(symbols[0]);
    //IMPRESIÓN DEL TABLERO
    for (short i = 0; i < HEIGHT; i++)
    {
        std::cout << "\n";
        std::cout << "                  ";
        visuals(symbols[1]);
        for (short j = 0; j < WIDTH; j++)
        {
            std::cout << tablero[i][j];

        }
        visuals(symbols[1]);
    }
    std::cout << "\n";
    visuals(symbols[0]);


}

void gameStats(short puntos, short ManzanasComidas) {
    std::cout << "\n                  Puntuacion: " << puntos;
    std::cout << "\n                  Manzanas comidas: " << ManzanasComidas;
}

void game_over(short puntos) {
    ASCIIgameOver();
    std::cout << "\n                    | -- YOUR SCORE WAS: " << puntos << " -- |\n";
}

