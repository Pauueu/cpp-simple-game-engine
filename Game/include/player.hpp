#pragma once
#include "GameObject.hpp"

// Klasa Player dziedziczy po klasie GameObject
class Player : public GameObject {
public:
    // Konstruktor
    Player(const std::string& path, float startX, float startY);
};