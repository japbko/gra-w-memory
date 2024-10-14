#pragma once

#include <iostream>
#include <fstream>
#include "Board.h"
#include "Player.h"

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    Player* currentPlayer;

public:
    // Konstruktor gry: inicjalizuje planszê oraz graczy
    Game(int rows, int cols, const std::string& playerName1, const std::string& playerName2);

    // Rozpoczêcie rozgrywki
    void startGame();

    // Funkcja do wykonania ruchu przez gracza
    void makeMove();

    // Funkcja zmieniaj¹ca gracza po wykonaniu ruchu
    void switchPlayer();

    // Wyœwietlenie wyników i og³oszenie zwyciêzcy
    void displayWinner();

    // Funkcje do zapisu i wczytywania gry (do zaimplementowania póŸniej)
    void saveGame(const std::string& filename);

    void loadGame(const std::string& filename);

};
