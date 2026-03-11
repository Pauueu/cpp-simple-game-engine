#pragma once
#include <SFML/Graphics.hpp>

class Engine{
    private:
        // Stworzenie okna gry
        sf::RenderWindow window;

        // Przetwarzanie zdarzeń (np. klawiatura, mysz)
        void processInput();
        // Atualizacja gry
        void update(float dt);
        // Rysowanie grafiki
        void render();


    public:
        //Konstruktor 
        Engine();

        // Metoda uruchamiająca silnik gry
        void run();
};