#include <iostream>
#include <stdlib.h>

int main()
{
    bool repeat = true;

    while (repeat)
    {
        int posSpieler = 1U;
        int lenSpielbrett = 10U;
        bool isFinished = false;
        char playersMove = 'X';
        system("clear");
        std::cout << "Please move the player with A to the left and with D to the right : \n ";

        do
        {
            // Ausgabe des Spielbretts
            for (int i = 1; i <= lenSpielbrett; i++)
            {
                if (i == posSpieler)
                {
                    std::cout << "P";
                }
                else if (i == 1 || i == lenSpielbrett)
                {
                    std::cout << "|";
                }
                else if (i != posSpieler)
                {
                    std::cout << ".";
                }
            }
            std::cout << "\n";
            if (posSpieler != lenSpielbrett)
            {
                std::cin >> playersMove;
                system("clear");
                if (playersMove == 'A' || playersMove == 'a')
                {
                    posSpieler = std::max(1, --posSpieler);
                }
                if (playersMove == 'D' || playersMove == 'd')
                {
                    posSpieler = std::min(10, ++posSpieler);
                }
            }
            else
            {
                isFinished = true;
            }
        } while (isFinished == false);

        std::cout << "Play again (0=No, 1=Yes) : \n ";
        std::cin >> repeat;
    }

    return 0;
}
