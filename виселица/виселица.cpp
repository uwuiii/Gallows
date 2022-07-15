#include "Gallows.h"

int main()
{
    srand(time(NULL));

    char letter;
    Gallows game;

    game.chooseWord();
    game.cypherInit();
    game.display();

    while (!game.isEnd())
    {
        cout << "Input letter: ";
        cin >> letter;

        game.move(letter);
    }

    game.final();
}
