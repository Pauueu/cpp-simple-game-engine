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
        UIImage(const std::string& texturePath, float width = 0.0f, float height = 0.0f)
            : sprite(ResourceManager::get().getTexture(texturePath)) {

            sf::FloatRect bounds = sprite.getLocalBounds(); // Wymiary tekstury

            sprite.setOrigin(sf::Vector2f(bounds.size.x / 2.0f, bounds.size.y / 2.0f)); // Ustawienie środka na środku tekstury

            // Skala do zmiany rozmiaru
            float scaleX = 1.0f;
            float scaleY = 1.0f;

            // Zmiana wysokości i szereokości
            if (width > 0.0f && height > 0.0f) {
                scaleX = width / bounds.size.x;
                scaleY = height / bounds.size.y;
            }

            // Zmiana tylko szereokości
            else if (width > 0.0f && height <= 0.0f) {
                scaleX = width / bounds.size.x;
                scaleY = scaleX;
            }

            // Zmiana tylko wysokości
            else if (width <= 0.0f && height > 0.0f) {
                scaleY = height / bounds.size.y;
                scaleX = scaleY;
            }

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