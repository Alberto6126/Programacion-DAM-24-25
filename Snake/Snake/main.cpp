#define FRAME_RATE 200
const short WIDTH = 20;
const short HEIGHT = 10;

#include <iostream>
#include <thread>
#include <chrono>
#include<Windows.h>
#include"keyboard.h"
#include"visualitems.h"
#include<vector>
#include<random>
#include<time.h>
#include"printfunctions.h"
#include"gamelogic.h";





void main() {
    char tablero[HEIGHT][WIDTH];
    short puntos = 0; 
    short ManzanasComidas = 0;
    short coordX = WIDTH / 2;
    short coordY = HEIGHT / 2;
    short coordXFruta;
    short coordYFruta; 
    std::vector<char> cuerpoSerpiente;
    std::vector<short> coordXMemoria;
    std::vector<short> coordYMemoria;
    char dir = 'n';
    bool crecerSerpiente = false;
    bool generarFruta = true;
    bool estatuspartida = 1;
    bool bGameOver = false;
    cuerpoSerpiente.push_back('X');
    coordXMemoria.push_back(coordX);
    coordYMemoria.push_back(coordY);

    
    //Bucle de la partida
    while (!bGameOver) {


        //esta función llena el tablero
        def_table(tablero); 


        //este bloque de código llama a la función fruta para generar aleatoriamente una posición para la fruta, en el caso de que ya haya generada una fruta, esta seguirá en el mismo sitio
        if (generarFruta)
        {
            frutas(tablero, &coordXFruta, &coordYFruta); 
            generarFruta = false; 
        }
        else if (!generarFruta)
        {
            tablero[coordYFruta][coordXFruta] = 'O'; 
        }

        //estatus partida invoca a la funcion del movimiento de la serpiente, la función devolverá 1 o 0 en el caso de devolver 0 el juego acabará
        estatuspartida = snakeMovement(tablero, &coordX, &coordY, &dir, coordXFruta, coordYFruta, &generarFruta, &crecerSerpiente, coordXMemoria, coordYMemoria, &ManzanasComidas);

        //guardo la posición de la serpiente
        coordXMemoria.push_back(coordX); 
        coordYMemoria.push_back(coordY); 

        //en el caso de comer una fruta crecerserpiente se activa, si crecerserpiente no es true se borrará la memoria para liberar espacio
        if (crecerSerpiente) {
            cuerpoSerpiente.push_back('x');
            puntos = puntos + cuerpoSerpiente.size() + 15;
        }
        else {
            coordXMemoria.erase(coordXMemoria.begin());
            coordYMemoria.erase(coordYMemoria.begin());
            if (dir != 'n') {
                puntos = puntos + cuerpoSerpiente.size();
            }
        }

        short cuerpo = cuerpoSerpiente.size() - 1;
        //coloco la serpiente en el tablero e invierto el orden para que la cabeza esté por delante del cuerpo
        for (short i = 0; i < cuerpoSerpiente.size(); i++) {
            tablero[coordYMemoria[i]][coordXMemoria[i]] = cuerpoSerpiente[cuerpo];
            cuerpo--; 
        }
        //imprimo el tablero
        print_table(tablero);
        if (estatuspartida != 1) {
            bGameOver=true;
        }
        //imprimo las estadísticas de la partida
        gameStats( puntos, ManzanasComidas);   

        //Sleep main thread to control game speed execution
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));
        system("CLS"); 

        crecerSerpiente = false;
    }
    //imprimo la pantalla de game over donde se indican los puntos finales
    game_over(puntos); 
}
