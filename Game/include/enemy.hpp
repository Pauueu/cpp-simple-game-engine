#pragma once
#include "GameObject.hpp"

// Rodzaje przeciwników
enum class EnemyType {
    Enemy1,
    Enemy2,
    Enemy3,
    Enemy4
};

class Enemy : public GameObject {
private:
    float speed; // Prędkość poeuszania się przeciwnik
    float bulletSpeed; // Prędkość pocisku przeciwnika
    int currentHP; // Obecna ilość żyć przeciwnika
    int scoreValue; // Punkty, które zyskuje gracz po pokonaniu przeciwnika

    float shootCooldownTime; // Wartość opóżnienia strzelania
    float currentCooldownTime; // Zmienna do przechowywania stanu licznika opóźnienia strzelania
    float moveDownTime; // Czas po jakim przeciwnicy przesuwają się w dół
    float currentMoveDownTime; // Stan licznika czasu międzu kolejnymi przesunięciami w dół

    bool isMovingDown; // Określa czy przeciwnik przesuwa się w dół czy na boki
    int targetPosY; // Docelowa pozycja w trakcie przesuwania w dół

    bool isSpawning; // Określa czy przecinicy się spawnują


    std::string bulletTexturePath; // Scieżka do textury pocisku

    EnemyType type; // Wybrany rodzaj przeciwnika
    
    static std::string getTexturePath(EnemyType type); // Metoda do pobrania ściezki tekstury na podstawie typy przeciwnika

    void EnemyShooting(float deltaTime); // Logika Strzelania przeciwnika
    void EnemyMovement(float deltaTime); // Logika poruszania przeciwnika

protected:
    void onUpdate(float dt);
    void onCollision(GameObject* other);


public:
    // Konstruktor
    Enemy(EnemyType type, float startX, float startY, float scaleX=1.0f, float scaleY=1.0f, const std::string& tag="Enemy");
};