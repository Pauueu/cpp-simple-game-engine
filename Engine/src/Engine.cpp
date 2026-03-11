#include "Engine.hpp"
#include <optional>

Engine::Engine() : window( sf::VideoMode({800, 600}), "Okno" ){
    // Ustawienie limity klatek na 60 FPS
    window.setFramerateLimit(60);
}

void Engine::run(){
    sf::Clock clock; // Zegar do mierzenia czasu między klatkami

    while (window.isOpen())
    {
        // Obliczenie czasu od ostatniej klatki, funkcja restart() zapisuje czas i resetuje zegar
        float dt = clock.restart().asSeconds();

        // Wywołanie głównych funkcji silnika: przetwarzanie zdarzeń, aktualizacja i renderowanie
        processInput();
        update(dt);
        render();
    }
    
}

void Engine::processInput(){

}

void Engine::update(float dt){

}

void Engine::render(){

}