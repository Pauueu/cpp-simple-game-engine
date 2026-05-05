#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Vector2f.hpp"
#include "UIElement.hpp"
#include "ResourceManager.hpp"


class UIImage : public UIElement {
    private:
        sf::Sprite sprite;

    public:
        UIImage( float width, float height, const std::string& texturePath)
            : sprite(ResourceManager::get().getTexture(texturePath)) {

            sf::FloatRect bounds = sprite.getLocalBounds(); // Wymiary tekstury

            sprite.setOrigin(sf::Vector2f(bounds.size.x / 2.0f, bounds.size.y / 2.0f)); // Ustawienie środka na środku tekstury

            // Przeskalowanie tekstury do rozmiarów
            float scaleX = width / bounds.size.x;
            float scaleY = height / bounds.size.y;

            sprite.setScale(sf::Vector2f(scaleX, scaleY)); // Zmiana skali elementu
        }

        void update(float dt) override {};

        // Ustawienie pozycji elementu
        void setPosition(Vector2f newPos) override final {
            UIElement::setPosition(newPos);

            sprite.setPosition(sf::Vector2f(position.x, position.y));
        }

        // Rysowanie elementu
        void draw(sf::RenderWindow& window) override {
            window.draw(sprite);
        }
};