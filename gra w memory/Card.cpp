#include "Card.h"

// Konstruktor

Card::Card(char symbol) : symbol(symbol), revealed(false) {}

// Metoda zwracaj�ca symbol karty (je�li odkryta) lub gwiazdk� (je�li zakryta)

char Card::getSymbol() const {
    return revealed ? symbol : '*';
}

// Sprawdzenie, czy karta jest odkryta

bool Card::isRevealed() const {
    return revealed;
}

// Odkrycie karty

void Card::reveal() {
    revealed = true;
}

// Zakrycie karty

void Card::hide() {
    revealed = false;
}

void Card::setSymbol(char newSymbol)
{
    symbol = newSymbol;
}
