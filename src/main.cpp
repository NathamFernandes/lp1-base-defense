#include <iostream>

#include "game.h"

using namespace std;

int main()
{
    Game game;

    if (!game.init())
    {
        cout << "Erro ao inicializar o jogo." << endl;
        return 1;
    }

    game.run();

    return 0;
}