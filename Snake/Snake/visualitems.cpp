const short WIDTH = 20;
const short HEIGHT = 10;
#include<iostream>

void ASCIIgameOver() {
    std::cout << "         _____                         ____                  \n";
    std::cout << "        / ____|                       / __ \\                 \n";
    std::cout << "       | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n";
    std::cout << "       | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|\n";
    std::cout << "       | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |\n";
    std::cout << "        \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|  \n";
    std::cout << "\n";
}

void ASCIIsnake() {
    std::cout << "                 __             _        \n";
    std::cout << "                / _\\_ __   __ _| | _____ \n";
    std::cout << "                \\ \\| '_ \\ / _` | |/ / _ \\\n";
    std::cout << "                _\\ \\ | | | (_| |   <  __/\n";
    std::cout << "               \\__/|_| |_|\\__,_|_|\\_\\___|\n";
    std::cout << "\n";
}
void visuals(char tipo_char) {
    if (tipo_char == '-') {
        std::cout << "                  ";
        std::cout << " ";
        for (short i = 0; i < WIDTH; i++)
        {
            std::cout << tipo_char;
        }
    }
    if (tipo_char == '|') {
        std::cout << tipo_char;
    }
}

