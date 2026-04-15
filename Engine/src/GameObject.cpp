#include "GameObject.hpp"
#include "ResourceManager.hpp"
#include <algorithm>

// Inicjalizacja listy obiektów
std::vector<GameObject*> GameObject::gameObjects;

// Konstruktor, z listą inicjalizującą ustawiającą pozycje i texture sprita
GameObject::GameObject(const std::string& path, float startX, float startY, const std::string& objTag, bool trigger, bool staticObj)
    : position(startX, startY), sprite(ResourceManager::get().getTexture(path)), tag(objTag), isTrigger(trigger), isStatic(staticObj), isDead(false)
    {

    sprite.setPosition(position); // Ustawienie pozycji sprita

    gameObjects.push_back(this); // Automatyczne dodanie do listy obiektów
}

// Destruktor
GameObject::~GameObject() {
    // Usunięce danego obiektu z listy obiektów
}

// Funkcja update
void GameObject::update(float deltaTime) {
    onUpdate(deltaTime);
    sprite.setPosition(position);
}

void GameObject::onUpdate(float deltaTime) {}

// Funkcja renderująca obiekt na ekranie
void GameObject::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Funkcja zwracająca pozycje obiektu
sf::Vector2f GameObject::getPosition() const {
    return position;
}

// Funkcja zwracająca granice obiektu
sf::FloatRect GameObject::getBounds() const {
    return sprite.getGlobalBounds();
}

void GameObject::onCollision(GameObject* other) {}

// Odsuwa obiekt od obiektu na który nadchodzi
void GameObject::moveOut(float dx, float dy) {
    position.x += dx;
    position.y += dy;
}