#pragma once
#include "GameObject.hpp"

// Klasa Player dziedziczy po klasie GameObject
class Player : public GameObject {
private:
    float speed; // Prędkość poeuszania się gracza
    float bulletSpeed; // Prędkość pocisku gracza
    int maxHP; // maksymalna ilość żyć gracza
    int currentHP; // Obecna ilość żyć gracza
    float shootCooldownTime; // Wartość opóżnienia strzelania
    float currentCooldownTime; // Zmienna do przechowywania stanu licznika opóźnienia strzelania

protected:
    void onUpdate(float dt);
    void onCollision(GameObject* other);

public:
    // Konstruktor
    Player(const std::string& path, float startX, float startY, float scaleX=1.0f, float scaleY=1.0f, const std::string& tag="Player");
    
    void updateHPCounter(int maxHP, int currentHP); // Rysowanie licznika życia
    void setCurrentHP(int newHP); // Metoda zmieniająca wartość HP gracza
    int getCurrentHP(); // Metoda zwracająca liczbe HP gracza
};