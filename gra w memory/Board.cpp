#include "Board.h"

// Konstruktor: inicjalizuje planszê o podanych rozmiarach

Board::Board(int rows, int cols) : rows(rows), cols(cols) {
    cards.resize(rows, std::vector<Card>(cols));
    initializeBoard(rows, cols);
}

// Funkcja do inicjalizacji planszy z losowym rozmieszczeniem kart

void Board::initializeBoard(int rows, int cols) {
    std::vector<Card> deck;
    char symbol = 'A';

    // Tworzenie par kart z unikalnymi symbolami
    for (int i = 0; i < (rows * cols) / 2; ++i) {
        deck.push_back(Card(symbol));
        deck.push_back(Card(symbol));
        ++symbol;
    }

    // Mieszanie kart, aby rozmieszczenie by³o losowe
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed dla generatora liczb losowych
    std::random_shuffle(deck.begin(), deck.end());

    // Tworzenie dwuwymiarowej tablicy kart (planszy)
    int index = 0;
    cards.resize(rows, std::vector<Card>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cards[i][j] = deck[index++];
        }
    }
}

// Funkcja do wyœwietlania planszy w konsoli

void Board::displayBoard() const {
    std::cout << "  ";
    for (int j = 0; j < cards[0].size(); ++j) {
        std::cout << j << " ";  // Wydrukuj numery kolumn
    }
    std::cout << std::endl;

    for (int i = 0; i < cards.size(); ++i) {
        std::cout << i << " ";  // Wydrukuj numery wierszy
        for (int j = 0; j < cards[i].size(); ++j) {
            std::cout << cards[i][j].getSymbol() << " ";
        }
        std::cout << std::endl;
    }
}

// Metody do uzyskiwania wymiarów planszy

int Board::getRows() const { return rows; }
int Board::getCols() const { return cols; }

// Funkcja do uzyskania referencji do konkretnej karty na planszy

Card& Board::getCard(int row, int col) {
    return cards[row][col];
}

// Funkcja sprawdzaj¹ca, czy wszystkie karty s¹ odkryte (czy gra siê zakoñczy³a)

bool Board::allCardsRevealed() const {
    for (const auto& row : cards) {
        for (const auto& card : row) {
            if (!card.isRevealed()) {
                return false; // Jeœli znajdziemy choæ jedn¹ zakryt¹ kartê, zwróæ false
            }
        }
    }
    return true; // Wszystkie karty s¹ odkryte
}
