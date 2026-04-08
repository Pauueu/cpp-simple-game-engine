#include "Player.hpp"
#include "InputManager.hpp"
#include <iostream>

Player::Player(const std::string& path, float startX, float startY): GameObject(path, startX, startY) 
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
    if (InputManager::GetKeyDown(KeyCode::MouseLeft)) {
        std::cout<<"Nacisnieto przycisk \n" << static_cast<int>(KeyCode::Count);

    }
}