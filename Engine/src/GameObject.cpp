#include "GameObject.hpp"
#include "ResourceManager.hpp"
#include <algorithm>

// Inicjalizacja listy obiektów
std::vector<GameObject*> GameObject::gameObjects;

// Konstruktor, z listą inicjalizującą ustawiającą pozycje i texture sprita
GameObject::GameObject(const std::string& path, float startX, float startY, float scaleX, float scaleY, const std::string& objTag, bool trigger, bool staticObj)
    : sprite(ResourceManager::get().getTexture(path)), position(startX, startY), scaleX(scaleX), scaleY(scaleY), tag(objTag), isTrigger(trigger), isStatic(staticObj), isDead(false)
    {
    
    sf::FloatRect bounds = sprite.getLocalBounds(); // Pobranie granic sprita
    sprite.setOrigin({bounds.size.x / 2.0f, bounds.size.y / 2.0f}); // Ustawienie punktu początkowego na środek

    sprite.setPosition(position); // Ustawienie pozycji sprita
    setScale(scaleX, scaleY); // Zmiana skali, wielkości tego obiektu
    
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

// Funkcja ustawiająca skalę obiektu
void GameObject::setScale(float scaleX, float scaleY) {
    sprite.setScale({scaleX, scaleY});
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