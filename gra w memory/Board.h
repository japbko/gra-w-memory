#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include "Card.h"

class Board {
private:
    int rows;
    int cols;
    std::vector<std::vector<Card>> cards; // Dwuwymiarowa tablica kart

public:
    // Konstruktor: inicjalizuje plansz� o podanych rozmiarach
    Board(int rows, int cols);

    // Funkcja do inicjalizacji planszy z losowym rozmieszczeniem kart
    void initializeBoard(int rows, int cols);

    // Funkcja do wy�wietlania planszy w konsoli
    void displayBoard() const;

    // Metody do uzyskiwania wymiar�w planszy
    int getRows() const;
    int getCols() const;

    // Funkcja do uzyskania referencji do konkretnej karty na planszy
    Card& getCard(int row, int col);

    // Funkcja sprawdzaj�ca, czy wszystkie karty s� odkryte (czy gra si� zako�czy�a)
    bool allCardsRevealed() const;

   


};



