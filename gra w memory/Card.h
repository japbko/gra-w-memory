#pragma once

class Card {
private:
    char symbol;     // Symbol reprezentuj�cy kart�
    bool revealed;   // Flaga okre�laj�ca, czy karta jest odkryta

public:
    // Konstruktor
    Card(char symbol = ' ');

    // Metoda zwracaj�ca symbol karty (je�li odkryta) lub gwiazdk� (je�li zakryta)
    char getSymbol() const;

    // Sprawdzenie, czy karta jest odkryta
    bool isRevealed() const;

    // Odkrycie karty
    void reveal();

    // Zakrycie karty
    void hide();

    void setSymbol(char newSymbol);
};






