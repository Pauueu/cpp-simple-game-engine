#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2f.hpp"
#include <vector>

class UIElement {
    protected:
        Vector2f position; // Pozycja elementu
    
    public:
        UIElement();
        virtual ~UIElement(); // Destruktor

        // Lista obiektów UI
        static std::vector<UIElement*> UIElement::uiElements;

        int zOrder = 0; // Numer warstwy, określenie co na czym się rysuje

        virtual void update(float dt) = 0; // Funkcja aktualizująća stan obiektu wraz z główną pętlą gry

        // Funkcja sprawdzająca kliknięcie obiektu
        virtual bool checkClick(Vector2f mousePos);

        virtual void setPosition(Vector2f newPos); // Funkcja do zmiany pozycji
    
        virtual void draw(sf::RenderWindow& window) = 0; // Funkcja do rysowania obiektu na kranie
};