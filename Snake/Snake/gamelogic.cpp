const short WIDTH = 20;
const short HEIGHT = 10;

#include"keyboard.h"
#include<vector>
#include<time.h> 




void def_table(char tablero[HEIGHT][WIDTH]) {
    //LLENADO DE TABLERO
    for (short i = 0; i < HEIGHT; i++)
    {
        for (short j = 0; j < WIDTH; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}
 

short snakeMovement(char tablero[HEIGHT][WIDTH], short* coordX, short* coordY, char* dir, short CoordXFruta, short CoordYFruta, bool* generarFruta, bool* crecerSerpiente, std::vector<short>coordXMem, std::vector<short>coordYMem, short* ManzanasComidas) {

    if (IsWPressed() && *dir != 's') {
        (*coordY)--;
        *dir = 'w';
    }
    else if (IsSPressed() && *dir != 'w') {
        (*coordY)++;
        *dir = 's';
    }
    else if (IsAPressed() && *dir != 'd') {
        (*coordX)--;
        *dir = 'a';
    }
    else if (IsDPressed() && *dir != 'a') {
        (*coordX)++;
        *dir = 'd';
    }
    else {
        switch (*dir) {

        case 'w':
            (*coordY)--;
            break;
        case 's':
            (*coordY)++;
            break;
        case 'a':
            (*coordX)--;
            break;
        case 'd':
            (*coordX)++;
            break;

        }
    }
    //en el caso de chocar con una pared se devuelve 0 y el juego acaba
    if (*coordY < 0 || *coordY > 9 || *coordX < 0 || *coordX > 19) {
        return 0;
    }
    // en el caso de coincidir posición con una fruta la serpiente crece
    else if (*coordX == CoordXFruta && *coordY == CoordYFruta)
    {
        *ManzanasComidas = (*ManzanasComidas)++;
        *generarFruta = true;
        *crecerSerpiente = true;
    }
    else {
        if (coordYMem.size() > 1) {
            for (short i = 0; i < coordYMem.size(); i++) {
                if (*coordX == coordXMem[i] && *coordY == coordYMem[i]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}


void frutas(char tablero[HEIGHT][WIDTH], short* coordX, short* coordY) {

    srand(time(NULL));

    *coordY = rand() % HEIGHT;
    *coordX = rand() % WIDTH;
    tablero[*coordY][*coordX] = 'O';


}