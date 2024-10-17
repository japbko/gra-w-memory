#include "Player.h"

// Konstruktor przyjmuj¹cy nazwê gracza i inicjuj¹cy punkty na zero

Player::Player(const std::string& playerName) : name(playerName), score(0) {}

// Funkcja do zdobywania punktów (np. po znalezieniu pary kart)

void Player::addPoint() {
    ++score;
}

// Funkcja zwracaj¹ca aktualn¹ punktacjê gracza

int Player::getScore() const {
    return score;
}

// Funkcja zwracaj¹ca nazwê gracza

std::string Player::getName() const {
    return name;
}
