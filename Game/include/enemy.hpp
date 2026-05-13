#pragma once
#include "GameObject.hpp"

class Enemy : public GameObject {
private:
    float speed; // Prędkość poeuszania się przeciwnik
    float bulletSpeed; // Prędkość pocisku przeciwnika
    int currentHP; // Obecna ilość żyć przeciwnika
    float shootCooldownTime; // Wartość opóżnienia strzelania
    float currentCooldownTime; // Zmienna do przechowywania stanu licznika opóźnienia strzelania

protected:
    void onUpdate(float dt);
    void onCollision(GameObject* other);

public:
    // Konstruktor
    Enemy(const std::string& path, float startX, float startY, float scaleX=1.0f, float scaleY=1.0f, const std::string& tag="Enemy");  
};