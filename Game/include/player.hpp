#pragma once
#include "GameObject.hpp"

// Klasa Player dziedziczy po klasie GameObject
class Player : public GameObject {
private:
    float speed;

protected:
    void onUpdate(float dt);

public:
    // Konstruktor
    Player(const std::string& path, float startX, float startY);  
};