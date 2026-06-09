#include "enemy.hpp"
#include "InputManager.hpp"
#include "GameManager.hpp"
#include "SceneManager.hpp"
#include "GameOverScene.hpp"
#include <iostream>
#include <cmath>

#include "bullet.hpp"

Enemy::Enemy(EnemyType type, float startX, float startY, float scaleX, float scaleY, const std::string& tag): GameObject(getTexturePath(type), startX, startY, scaleX, scaleY, tag), type(type) 
{
    // Przypisanie wartoście na podstawie typu
    switch(type) {
        case EnemyType::Enemy1: 
                speed = 200.0f;
                bulletSpeed = 700.0f;
                currentHP = 1;
                scoreValue = 50;
                shootCooldownTime = 2.0f;
                bulletTexturePath = "assets/EnemyBullet1.png";
                break;

        case EnemyType::Enemy2: 
                speed = 100.0f;
                bulletSpeed = 500.0f;
                currentHP = 2;
                scoreValue = 75;
                shootCooldownTime = 2.5f;
                bulletTexturePath = "assets/EnemyBullet2.png";
                break;

        case EnemyType::Enemy3: 
                speed = 100.0f;
                bulletSpeed = 600.0f;
                currentHP = 3;
                scoreValue = 125;
                shootCooldownTime = 3.0f;
                bulletTexturePath = "assets/EnemyBullet3.png";
                break;

        case EnemyType::Enemy4: 
                speed = 50.0f;
                bulletSpeed = 450.0f;
                currentHP = 5;
                scoreValue = 200;
                shootCooldownTime = 4.0f;
                bulletTexturePath = "assets/EnemyBullet4.png";
                break;
    }

    currentCooldownTime = shootCooldownTime;
    moveDownTime = 5.0f;
    currentMoveDownTime = moveDownTime;

    isMovingDown = false;
    isSpawning = true;
    isTrigger = true;

    targetPosY = position.y;
    position.y -= 400;
}

void Enemy::onUpdate(float deltaTime) {

    if (isSpawning) {
        float spawningSpeed = 250.0f;

        position.y += spawningSpeed * deltaTime;

        if (position.y > targetPosY) {
            position.y = targetPosY;
            isSpawning = false;
            isTrigger = false;
        }

        return; // Zakończenie pętli jeżeli trwa spawn
    }

    EnemyShooting(deltaTime);

    EnemyMovement(deltaTime);

    // Zniszczenie przeciwnika
    if (currentHP <= 0) {
        isDead = true;
    }

}

void Enemy::onCollision(GameObject* other) {

    if (other->tag == "PlayerBullet") {
        other->isDead = true; // Usunięcie pocsku
        if (!isSpawning) {
            currentHP -= 1;

            if (currentHP <= 0 && !isDead) {
                GameManager::playerScore += scoreValue; 
            }
        }
    }

    // Zakończenie gry po dojechaniu wrogów na sam dół
    if (other->tag == "BottomWall") {
        GameManager::playerHP = 0;
        SceneManager::loadScene(new GameOverScene());
    }

    if (other->tag == "Wall") {
        speed = -speed;
    }

    if (other->tag == "Enemy") {
        Enemy* otherEnemy = static_cast<Enemy*>(other); // Zmiana other z GameObject na Enemy

        // Sprawdzenie położenia obiektów między sobą
        if (position.x < otherEnemy->position.x) {
            speed = -abs(speed);
        }
        else {
            speed = abs(speed);
        }
    }
}

std::string Enemy::getTexturePath(EnemyType type) {
    switch(type) {
        case EnemyType::Enemy1: return "assets/Enemy1.png";
        case EnemyType::Enemy2: return "assets/Enemy2.png";
        case EnemyType::Enemy3: return "assets/Enemy3.png";
        case EnemyType::Enemy4: return "assets/Enemy4.png";
    }

    return "";
}

// Logika strzelania przeciwników
void Enemy::EnemyShooting (float deltaTime) {
    // Opoóźnienie strzelania
    if(currentCooldownTime > 0.0f) {
        currentCooldownTime -= deltaTime;
    }

    // Strzelanie
    if (currentCooldownTime <= 0.0f) {

        if (type == EnemyType::Enemy3) {
            // Podwójny pocisk
            float bulletsGap = 50.0f;
            new Bullet(bulletTexturePath, bulletSpeed, position.x + bulletsGap, position.y, 0.5f, 0.5f, "EnemyBullet"); 
            new Bullet(bulletTexturePath, bulletSpeed, position.x - bulletsGap, position.y, 0.5f, 0.5f, "EnemyBullet");
        }
        else {
            new Bullet(bulletTexturePath, bulletSpeed, position.x, position.y, 0.5f, 0.5f, "EnemyBullet"); // Tworzenie nowgo pocisku
        }

        currentCooldownTime = shootCooldownTime;
    }
}

// logika poruszania się przeciwników
void Enemy::EnemyMovement (float deltaTime) {

    if (isMovingDown) {
        float moveDownSpeed = 100.0f;

        position.y += moveDownSpeed * deltaTime;

        if (position.y > targetPosY) {
            position.y = targetPosY;
            isMovingDown = false;
            currentMoveDownTime = moveDownTime;
        }

    }

    else {
        position.x += speed * deltaTime;

        if(currentMoveDownTime > 0.0f) {
            currentMoveDownTime -= deltaTime;
        }

        if(currentMoveDownTime <= 0.0f) {
            isMovingDown = true;

            int moveDownStep = 50.0f;
            targetPosY += moveDownStep;
        }
    }
}
