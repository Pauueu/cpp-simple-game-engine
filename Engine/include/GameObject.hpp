#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


// Klasa reprezentująca obiekt gry, który może być używany do różnych celów, takich jak postacie, przedmioty, itp.s
class GameObject{
    protected:
        sf::Sprite sprite; // Sprite reprezentujący obiekt gry

        // Tu przydało by się zrobić własną strukturę Vector2
        sf::Vector2f position; // Pozycja obiektu gry

        virtual void onUpdate(float deltaTime); // Funkcja update do nadpisywania przez inne klasy

    public:
        GameObject(const std::string& path, float startX, float startY, float scaleX=1.0f, float scaleY=1.0f, const std::string& tag = "", bool isTrigger = false, bool isStatic = false); // Konstruktor
        virtual ~GameObject(); // Destruktor
        
        // skala obiektu (zmniejszanie, powiększanie)
        float scaleX;
        float scaleY; 
        std::string tag; // Tag do rozróżniania typów obiektów w grze, np. pociski albo przeciwnicy
        bool isTrigger; // Bool do stwierdzenia czy obiekt jest fizyczny, czy nie. Określa czy obiekt będzie prznikał przez inne obiekty.
        bool isStatic; // Określa czy obiekt jest statyczny, to znaczy, że nie może zmienić wartośći swojego położenia w trakcie trwania gry.
        bool isDead; // Potrzebne do bezpiecznego usunięcia obiektu z wektora obiektów. Funkcja update cały czas iteruje po obiektach, jężeli w tym momenci obiekt zostanie usunięty z wektora zmniejzy to jego długość i spowoduje błąd.

        static std::vector<GameObject*> gameObjects; // Wspólna lista dla wszystkich obiektów. Spis obiektów w grze, by np. wiedzieć jakie funkcje update wywoływać.

        void update(float deltaTime); // Metoda aktualizująca stan obiektu, przyjmuje deltaTime czyli czas między kolejnymi klatkami
        virtual void draw(sf::RenderWindow& window); // Metoda do rysowania obiektu na ekranie

        void setScale(float scaleX, float scaleY); // Metoda zmieniająca skalę obiektu

        sf::Vector2f getPosition() const; // Metoda zwracająca pozycje obiektu
        sf::FloatRect getBounds() const; // Metoda zwracająca granice obietu

        virtual void onCollision(GameObject* other); // Metoda do obsługi zdarzeń po zderzeniu się obiektów

        // Metoda służąca do wypychania obiektów nachodzących na siebie (jeżeli isTrigger = false)
        void moveOut(float dx, float dy);
};