#pragma once
#include "UIElement.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class UIText : public UIElement {
    private:
        sf::Text text;

    public:
        UIText(const sf::String& content, const std::string& fontPath, unsigned int textSize=24) 
            : text(ResourceManager::get().getFont(fontPath), content, textSize) {

            text.setFillColor(sf::Color::White); // Ustawienie koloru tekstu
            
            // Ustawienie środka tekstu
            sf::FloatRect textRect = text.getLocalBounds();
            text.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f));
        }

        void update(float dt) override {};

        void setPosition(Vector2f newPos) override final {
            UIElement::setPosition(newPos);
            text.setPosition(sf::Vector2f(position.x, position.y));
        } 

        void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255) {
            text.setFillColor(sf::Color(r, g, b, a));
        }

        void draw(sf::RenderWindow& window) override {
            window.draw(text);
        }
};