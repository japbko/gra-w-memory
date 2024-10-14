#include "Game.h"

// Konstruktor gry: inicjalizuje planszê oraz graczy

Game::Game(int rows, int cols, const std::string& playerName1, const std::string& playerName2)
    : board(rows, cols), player1(playerName1), player2(playerName2), currentPlayer(&player1) {}

// Rozpoczêcie rozgrywki

void Game::startGame() {
    while (!board.allCardsRevealed()) {
        board.displayBoard();
        std::cout << "Kolej gracza: " << currentPlayer->getName() << std::endl;
        makeMove();
        switchPlayer();
    }
    displayWinner();
}

// Funkcja do wykonania ruchu przez gracza

void Game::makeMove() {
    try {
        int row1, col1, row2, col2;
        std::cout << "Podaj wspó³rzêdne pierwszej karty (wiersz i kolumna): ";
        std::cin >> row1 >> col1;
        
        // Sprawdzenie, czy wspó³rzêdne pierwszej karty s¹ w granicach planszy
        if (row1 < 0 || row1 >= board.getRows() || col1 < 0 || col1 >= board.getCols()) {
            throw std::out_of_range("Nieprawid³owe wspó³rzêdne.");
        }

        std::cout << "Podaj wspó³rzêdne drugiej karty (wiersz i kolumna): ";
        std::cin >> row2 >> col2;

        // Sprawdzenie, czy wspó³rzêdne drugiej karty s¹ w granicach planszy
        if (row2 < 0 || row2 >= board.getRows() || col2 < 0 || col2 >= board.getCols()) {
            throw std::out_of_range("Nieprawid³owe wspó³rzêdne.");
        }

        // Sprawdzenie, czy karta jest ju¿ odkryta
        if (board.getCard(row1, col1).isRevealed() || board.getCard(row2, col2).isRevealed()) {
            std::cout << "Jedna z tych kart jest ju¿ odkryta. Spróbuj ponownie." << std::endl;
            return; // Jeœli karta jest ju¿ odkryta, przerywamy funkcjê
        }

        // Odkrycie wybranych kart
        board.getCard(row1, col1).reveal();
        board.getCard(row2, col2).reveal();
        board.displayBoard();

        // Sprawdzenie, czy karty s¹ takie same
        if (board.getCard(row1, col1).getSymbol() == board.getCard(row2, col2).getSymbol()) {
            std::cout << "Brawo! Znalaz³eœ parê!" << std::endl;
            currentPlayer->addPoint();
        } else {
            std::cout << "Karty s¹ ró¿ne. Zakrywamy je ponownie." << std::endl;
            board.getCard(row1, col1).hide();
            board.getCard(row2, col2).hide();
        }
    } catch (const std::out_of_range&) {
        std::cerr << "B³¹d: Wprowadzi³eœ niepoprawne wspó³rzêdne. Spróbuj ponownie." << std::endl;
    }
}

// Funkcja zmieniaj¹ca gracza po wykonaniu ruchu

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}

// Wyœwietlenie wyników i og³oszenie zwyciêzcy

void Game::displayWinner() {
    std::cout << "Gra zakoñczona!" << std::endl;
    std::cout << player1.getName() << " zdoby³(a) " << player1.getScore() << " punktów." << std::endl;
    std::cout << player2.getName() << " zdoby³(a) " << player2.getScore() << " punktów." << std::endl;

    if (player1.getScore() > player2.getScore()) {
        std::cout << "Zwyciêzca: " << player1.getName() << "!" << std::endl;
    }
    else if (player2.getScore() > player1.getScore()) {
        std::cout << "Zwyciêzca: " << player2.getName() << "!" << std::endl;
    }
    else {
        std::cout << "Remis!" << std::endl;
    }
}

// Funkcje do zapisu i wczytywania gry (do zaimplementowania póŸniej)

void Game::saveGame(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Nie uda³o siê otworzyæ pliku do zapisu!" << std::endl;
        return;
    }

    // Zapisujemy wymiary planszy
    outFile << board.getRows() << ' ' << board.getCols() << std::endl;

    // Zapisujemy stan planszy (symbole i status odkrycia kart)
    for (int i = 0; i < board.getRows(); ++i) {
        for (int j = 0; j < board.getCols(); ++j) {
            outFile << board.getCard(i, j).getSymbol() << ' '
                << board.getCard(i, j).isRevealed() << ' ';
        }
        outFile << std::endl;
    }

    // Zapisujemy nazwê graczy i ich punkty
    outFile << player1.getName() << ' ' << player1.getScore() << std::endl;
    outFile << player2.getName() << ' ' << player2.getScore() << std::endl;

    // Zapisujemy, który gracz jest aktualnie w trakcie ruchu
    outFile << (currentPlayer == &player1 ? "1" : "2") << std::endl;

    std::cout << "Gra zosta³a zapisana do pliku: " << filename << std::endl;
    outFile.close();
}

void Game::loadGame(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Nie uda³o siê otworzyæ pliku do wczytania!" << std::endl;
        return;
    }

    int rows, cols;
    inFile >> rows >> cols;
    board = Board(rows, cols);  // Tworzymy now¹ planszê o tych wymiarach

    // Wczytujemy stan planszy
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char symbol;
            bool revealed;
            inFile >> symbol >> revealed;
            board.getCard(i, j).setSymbol(symbol);
            if (revealed) {
                board.getCard(i, j).reveal();
            }
        }
    }

    // Wczytujemy graczy i ich punkty
    std::string name1, name2;
    int score1, score2;
    inFile >> name1 >> score1 >> name2 >> score2;
    player1 = Player(name1);
    player2 = Player(name2);
    while (score1--) player1.addPoint();
    while (score2--) player2.addPoint();

    // Wczytujemy, który gracz jest aktualnie w trakcie ruchu
    int currentPlayerNum;
    inFile >> currentPlayerNum;
    currentPlayer = (currentPlayerNum == 1) ? &player1 : &player2;

    std::cout << "Gra zosta³a wczytana z pliku: " << filename << std::endl;
    inFile.close();
}
