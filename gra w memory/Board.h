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
    // Konstruktor: inicjalizuje planszê o podanych rozmiarach
    Board(int rows, int cols);

    // Funkcja do inicjalizacji planszy z losowym rozmieszczeniem kart
    void initializeBoard(int rows, int cols);

    // Funkcja do wyœwietlania planszy w konsoli
    void displayBoard() const;

    // Metody do uzyskiwania wymiarów planszy
    int getRows() const;
    int getCols() const;

    // Funkcja do uzyskania referencji do konkretnej karty na planszy
    Card& getCard(int row, int col);

    // Funkcja sprawdzaj¹ca, czy wszystkie karty s¹ odkryte (czy gra siê zakoñczy³a)
    bool allCardsRevealed() const;

   


};



