#include "GameObject.hpp"
#include "ResourceManager.hpp"

// Konstruktor, z listą inicjalizującą ustawiającą pozycje i texture sprita
GameObject::GameObject(const std::string& path, float startX, float startY): position(startX, startY), sprite(ResourceManager::get().getTexture(path)) {

    sprite.setPosition(position); // Ustawienie pozycji sprita
}

// Funkcja update
void GameObject::update(float deltaTime) {
    sprite.setPosition(position);
}

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