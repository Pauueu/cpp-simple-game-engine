#include "player.hpp"
#include "InputManager.hpp"
#include <iostream>
#include "bullet.hpp"
#include "UIImage.hpp"
#include "Vector2f.hpp"


Player::Player(const std::string& path, float startX, float startY, float scaleX, float scaleY, const std::string& tag): GameObject(path, startX, startY, scaleX, scaleY, tag) 
{
    speed = 550.0f;
    bulletSpeed = -1000.0f;
    maxHP = 3;
    currentHP = maxHP;

    shootCooldownTime = 0.5f;
    currentCooldownTime = 0.0f;

    updateHPCounter(maxHP, currentHP);
}

void Player::onUpdate(float deltaTime) {
    
    // Sterowanie graczem
    if (InputManager::GetKey(KeyCode::W)) {
        position.y -= speed * deltaTime; // W górę
    }
    if (InputManager::GetKey(KeyCode::S)) {
        position.y += speed * deltaTime; // W dół
    }
    if (InputManager::GetKey(KeyCode::A)) {
        position.x -= speed * deltaTime; // W lewo
    }
    if (InputManager::GetKey(KeyCode::D)) {
        position.x += speed * deltaTime; // W prawo
    }

    // Opoóźnienie strzelania
    if(currentCooldownTime > 0.0f) {
        currentCooldownTime -= deltaTime;
    }

    // Strzelanie
    if (InputManager::GetKey(KeyCode::Space) && currentCooldownTime <= 0.0f) {
        new Bullet("assets/PlayerBullet1.png", bulletSpeed, position.x, position.y, 0.5f, 0.5f, "PlayerBullet"); // Tworzenie nowgo pocisku
        currentCooldownTime = shootCooldownTime;
    }

    if (currentHP <= 0) {
        isDead = true;
    }
}

void Player::onCollision(GameObject* other) {

    if (other->tag == "EnemyBullet") {
        other->isDead = true; // Usunięcie pocisku
        
        currentHP -= 1; // Zmniejszenie życia gracza
        updateHPCounter(maxHP, currentHP); // Atualizacja UI
    }

    // W przypadku dotknięcia przeciwnika gracz ginie
    if (other->tag == "Enemy") {
        currentHP = 0;
        isDead = true;
        updateHPCounter(maxHP, currentHP); // Atualizacja UI
    }
}

// Wyświetlanie licznika żyć gracza
void Player::updateHPCounter(int maxHP, int currentHP) {
    float posX = -880.0f;
    float posY = -460.0f;
    float gap = 7.0f;

    float elementWidth = 70.0f;

    for (int i = 0; i < maxHP; i++) {
        Vector2f position = Vector2f(posX + (elementWidth + gap) * i, posY);

        if (i < currentHP) {
            UIElement* element = new UIImage("assets/HPFilled.png", elementWidth);
            element->setPosition(position);
        }
        
        else {
            UIElement* element = new UIImage("assets/HPEmpty.png", elementWidth);
            element->setPosition(position);
        }
    }
}

// Ustawienie HP gracza
void Player::setCurrentHP(int newHP){
    currentHP = newHP;
    updateHPCounter(maxHP, currentHP);
}

// Zwraca liczbę HP
int Player::getCurrentHP(){
    updateHPCounter(maxHP, currentHP);
    return currentHP;
}