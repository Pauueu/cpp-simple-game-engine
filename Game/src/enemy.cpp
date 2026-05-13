#include "enemy.hpp"
#include "InputManager.hpp"
#include <iostream>

#include "bullet.hpp"

Enemy::Enemy(const std::string& path, float startX, float startY, float scaleX, float scaleY, const std::string& tag): GameObject(path, startX, startY, scaleX, scaleY, tag) 
{
    speed = 300.0f;
    bulletSpeed = 500.0f;
    currentHP = 3;

    shootCooldownTime = 2.0f;
    currentCooldownTime = 0.0f;
}

void Enemy::onUpdate(float deltaTime) {
    // Opoóźnienie strzelania
    if(currentCooldownTime > 0.0f) {
        currentCooldownTime -= deltaTime;
    }

    // Strzelanie
    if (currentCooldownTime <= 0.0f) {
        new Bullet("assets/EnemyBullet1.png", bulletSpeed, position.x, position.y, 0.5f, 0.5f, "EnemyBullet"); // Tworzenie nowgo pocisku
        currentCooldownTime = shootCooldownTime;
    }

    // Zniszczenie przeciwnika
    if (currentHP <= 0) {
        isDead = true;
    }
}

void Enemy::onCollision(GameObject* other) {

    if (other->tag == "PlayerBullet") {
        other->isDead = true; // Usunięcie pocsku
        currentHP -= 1;
    }
}