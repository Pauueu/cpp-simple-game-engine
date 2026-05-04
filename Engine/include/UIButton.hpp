#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <functional>
#include "Vector2f.hpp"
#include "UIElement.hpp"
#include "ResourceManager.hpp"


class UIButton : public UIElement {
    private:
        sf::RectangleShape background;
        sf::Text label;
        std::function<void()> function;

    public:
        UIButton(float width, float height, const sf::String& labelText, const std::string& fontPath, unsigned int labelSize=24)
            : label(ResourceManager::get().getFont(fontPath), labelText, labelSize) {

            background.setSize(sf::Vector2f(width, height));
            background.setOrigin(sf::Vector2f(width/2, height/2));
            background.setFillColor(sf::Color::White);

            // Ustawienie tekstu na środek tła przycisku
            sf::FloatRect textRect = label.getLocalBounds();
            label.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f));
            label.setFillColor(sf::Color::Black); // Ustawienie koloru tekstu
        }

        void update(float dt) override {};

        // Ustawienie funkcji, która wykona się po naciśnięciu przycisku
        void setFunction(std::function<void()> fun) {
            function = fun;
        }

        // Funkcja sprawdzająca kliknięcie obiektu
        virtual bool checkClick(Vector2f mousePos) override { 
            if(background.getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y))) {
                // Sprawdzenie czy jest przypisana funkcja i wywołanie jej
                if (function) {
                    function();
                }
                return true;
            }   
            return false;
        }

        // Ustawienie pozycji przycisku
        void setPosition(Vector2f newPos) override final {
            UIElement::setPosition(newPos);

            background.setPosition(sf::Vector2f(position.x, position.y));
            label.setPosition(sf::Vector2f(position.x, position.y));
        }

        // Zmiana koloru tła przycisku
        void setBackgroundColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255) {
            background.setFillColor(sf::Color(r, g, b, a));
        }
        
        // Zmiana koloru tekstu przycisku
        void setLabelColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255) {
            label.setFillColor(sf::Color(r, g, b, a));
        }

        // Rysowanie przycisku
        void draw(sf::RenderWindow& window) override {
            window.draw(background);
            window.draw(label);
        }
};