#include "Player.hpp"
#include "InputManager.hpp"
#include <iostream>

Player::Player(const std::string& path, float startX, float startY, float scaleX, float scaleY, const std::string& tag): GameObject(path, startX, startY, scaleX, scaleY, tag) 
{
    speed = 300.0f;
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
}

void Player::onCollision(GameObject* other) {

    // std::cout<<"Dotknieto obiekt z tagiem: " << other->tag << "\n";

    if (other->tag == "Coin") {
        other->isDead = true; // Usunięcie obietku po dotknięciu go
    }
}