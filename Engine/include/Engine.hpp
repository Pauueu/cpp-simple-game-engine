#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "GameObject.hpp"

class Engine{
    private:
        sf::RenderWindow window; // Stworzenie okna gry
        
        void processInput();// Metoda przetwarzająca zdarzenia (np. klawiatura, mysz)
        void update(float dt);// Metoda aktualizująca stan gry
        void render();// Metoda do rysowania grafiki

    public:
        Engine(); //Konstruktor 

        void run(); // Metoda uruchamiająca silnik gry
};