#include "game_class.h"

int main()
{
    bool repeat = true;


    while (repeat)
    {
        Game game;
        game.start_game();

        std::cout << "Play again (0=No, 1=Yes) : \n ";
        std::cin >> repeat;

        system("clear");
    }

    return 0;
}
