#pragma once

class Card {
private:
    char symbol;     // Symbol reprezentuj¹cy kartê
    bool revealed;   // Flaga okreœlaj¹ca, czy karta jest odkryta

public:
    // Konstruktor
    Card(char symbol = ' ');

    // Metoda zwracaj¹ca symbol karty (jeœli odkryta) lub gwiazdkê (jeœli zakryta)
    char getSymbol() const;

    // Sprawdzenie, czy karta jest odkryta
    bool isRevealed() const;

    // Odkrycie karty
    void reveal();

    // Zakrycie karty
    void hide();

    void setSymbol(char newSymbol);
};






