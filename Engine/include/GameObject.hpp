#pragma once
#include <SFML/Graphics.hpp>


// Klasa reprezentująca obiekt gry, który może być używany do różnych celów, takich jak postacie, przedmioty, itp.s
class GameObject{
    protected:
        sf::Sprite sprite; // Sprite reprezentujący obiekt gry
        sf::Vector2f position; // Pozycja obiektu gry

    public:
        GameObject(const std::string& path, float startX, float startY); // Konstruktor
        virtual ~GameObject() = default; // Destruktor

        virtual void update(float deltaTime); // Metoda aktualizująca stan obiektu, przyjmuje deltaTime czyli czas między kolejnymi klatkami
        virtual void draw(sf::RenderWindow& window); // Metoda do rysowania obiektu na ekranie

        sf::Vector2f getPosition() const; // Metoda zwracająca pozycje obiektu
        sf::FloatRect getBounds() const; // Metoda zwracająca granice obietu
};