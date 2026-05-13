#include "bullet.hpp"
#include "InputManager.hpp"
#include <iostream>

Bullet::Bullet(const std::string& path, float bulletSpeed, float startX, float startY, float scaleX, float scaleY, const std::string& tag): GameObject(path, startX, startY, scaleX, scaleY, tag) 
{
    speed = bulletSpeed;
    isTrigger = true;
}

void Bullet::onUpdate(float deltaTime) {
    position.y += speed * deltaTime; // Poruczanie w górę albo w dół cały czas
}

void Bullet::onCollision(GameObject* other) {
    if (other->tag == "Wall") {
        this->isDead = true; // Usunięcie obietku po dotknięciu go
    }
}