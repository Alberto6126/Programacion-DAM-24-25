#pragma once
#include<vector>

void def_table(char tablero[HEIGHT][WIDTH]);
short snakeMovement(char tablero[HEIGHT][WIDTH], short* coordX, short* coordY, char* dir, short CoordXFruta, short CoordYFruta, bool* generarFruta, bool* crecerSerpiente, std::vector<short>coordXMem, std::vector<short>coordYMem, short* ManzanasComidas);
void frutas(char tablero[HEIGHT][WIDTH], short* coordX, short* coordY);

