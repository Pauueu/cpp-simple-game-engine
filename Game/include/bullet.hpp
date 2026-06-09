#pragma once
#include "GameObject.hpp"

class Bullet : public GameObject {
private:
    float speed;

protected:
    void onUpdate(float dt);
    void onCollision(GameObject* other);

public:
    // Konstruktor
    Bullet(const std::string& path, float speed, float startX, float startY, float scaleX=1.0f, float scaleY=1.0f, const std::string& tag="");  
};