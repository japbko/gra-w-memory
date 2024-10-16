#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include <memory>
#include "Game.h"

void displayMenu()
{
    std::cout << "================= Memory Game =================\n";
    std::cout << "1. Nowa gra\n";
    std::cout << "2. Wczytaj grę\n";
    std::cout << "3. Wyjście\n";
    std::cout << "Wybierz opcję: ";
}

int getValidIntInput(const std::string& prompt)
{
    int input;
    std::cout << prompt;
    if (!(std::cin >> input))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Błąd: Wprowadź liczbę całkowitą.");
    }
    return input;
}

int main()
{

    std::locale::global(std::locale(""));

    int choice;
    std::string player1Name, player2Name;
    Game* game = nullptr;

    while (true)
    {
        displayMenu();
        try
        {
            choice = getValidIntInput("");

            switch (choice)
            {
            case 1:
            {
                // Nowa gra
                std::cout << "Podaj nazwę gracza 1: ";
                std::cin >> player1Name;
                std::cout << "Podaj nazwę gracza 2: ";
                std::cin >> player2Name;

                int rows, cols;

                std::cout << "Podaj liczbe wierszy: ";
                if (!(std::cin >> rows) || rows <= 0 || rows > 10)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Pamiętaj że liczba wierszy musi być liczbą całkowitą więszką od 0 i mniejszą niż 10\n");
                }

                std::cout << "Podaj liczbe kolumn: ";
                if (!(std::cin >> cols) || cols <= 0 || cols > 10)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Pamiętaj że liczba column musi być liczbą całkowitą więszką od 0 i mniejszą niż 10\n");
                }

                if ((rows * cols) % 2 != 0)
                {
                    throw std::invalid_argument("Błąd: Iloczyn wierszy i kolumn musi być liczbą parzystą.");
                }

                game = new Game(rows, cols, player1Name, player2Name);
                game->startGame();
                delete game;

                break;
            }
            case 2:
            {
                // Wczytaj grę
                std::string filename;
                std::cout << "Podaj nazwę pliku do wczytania: ";
                std::cin >> filename;

                game = new Game(0, 0, "", ""); // Tworzenie pustego obiektu gry
                game->loadGame(filename);
                game->startGame();
                delete game; // Zwalniamy pamięć po zakończeniu gry
                break;
            }
            case 3:
                std::cout << "Dziękujemy za grę! Do zobaczenia!\n";
                return 0;
            default:
                throw std::invalid_argument("Niepoprawna opcja. Spróbuj ponownie.");
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Wystąpił błąd" << std::endl;
        }
    }
}