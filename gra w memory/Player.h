#pragma once

#include <string>

class Player {
private:
    std::string name;   // Nazwa gracza
    int score;          // Aktualna liczba punktów gracza

public:
    // Konstruktor przyjmuj¹cy nazwê gracza i inicjuj¹cy punkty na zero
    Player(const std::string& playerName);

    // Funkcja do zdobywania punktów (np. po znalezieniu pary kart)
    void addPoint();

    // Funkcja zwracaj¹ca aktualn¹ punktacjê gracza
    int getScore() const;

    // Funkcja zwracaj¹ca nazwê gracza
    std::string getName() const;
};

