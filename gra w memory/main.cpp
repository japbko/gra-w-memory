#include <iostream>
#include "Game.h"

void displayMenu() {
    std::cout << "================= Memory Game =================\n";
    std::cout << "1. Nowa gra\n";
    std::cout << "2. Wczytaj grę\n";
    std::cout << "3. Zapisz grę\n"; // Nowa opcja
    std::cout << "4. Wyjście\n";
    std::cout << "Wybierz opcję: ";
}


int main() {

    std::locale::global(std::locale("")); // Ustawienie lokalizacji dla wszystkich strumieni znakowych

    int choice;
    std::string player1Name, player2Name;
    Game* game = nullptr; // Wskaźnik na obiekt gry

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 1) {
            // Nowa gra
            
            

                int rows, cols;
                std::cout << "Podaj nazwę gracza 1: ";
                std::cin >> player1Name;
                std::cout << "Podaj nazwę gracza 2: ";
                std::cin >> player2Name;

                try
                {
                    std::cout << "Podaj liczbę wierszy: ";
                    std::cin >> rows;
                    std::cout << "Podaj liczbę kolumn: ";
                    std::cin >> cols;

                    if ((rows * cols) % 2 != 0)
                    {
                        throw std::invalid_argument("liczba kart na planszy musi być parzysta");
                    }

                    game = new Game(rows, cols, player1Name, player2Name);
                    game->startGame();
                    delete game; // Zwalniamy pamięć po zakończeniu gry

                }
                catch (const std::invalid_argument& e)
                {
                    std::cerr << "liczba kart na planszy musi być parzysta. spróbuj ponownie";
                }
               
            
        }
        else if (choice == 2) {
            // Wczytaj grę
            std::string filename;
            std::cout << "Podaj nazwę pliku do wczytania: ";
            std::cin >> filename;

            game = new Game(0, 0, "", ""); // Tworzenie pustego obiektu gry
            game->loadGame(filename);
            game->startGame();
            delete game; // Zwalniamy pamięć po zakończeniu gry
        }
        else if (choice == 3) {
            // Zapisz grę
            if (game != nullptr) { // Sprawdź, czy gra jest aktywna
                std::string filename;
                std::cout << "Podaj nazwę pliku do zapisu gry: ";
                std::cin >> filename;
                game->saveGame(filename);
            }
            else {
                std::cout << "Nie ma aktywnej gry do zapisania.\n";
            }

        }
        else if (choice == 4) {
            // Wyjście
            std::cout << "Dziękujemy za grę! Do zobaczenia!\n";
            break;

        }
        else {
            std::cout << "Niepoprawna opcja. Spróbuj ponownie.\n";
        }
    }

    return 0;
}
