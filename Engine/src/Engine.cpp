#include "Engine.hpp"
#include <optional>

Engine::Engine() : window( sf::VideoMode({800, 600}), "Okno" ){
    // Ustawienie limity klatek na 60 FPS
    window.setFramerateLimit(60);
}


// Główna pętla gry
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
    // Sprawdzanie interakcji użytkownika z oknem
    while (std::optional event = window.pollEvent())
    {
        // Zamknięcie okna, jeśli użytkownik naciśnie "X"
        if (event->is<sf::Event::Closed>()){
            window.close();
        }
    }
}

void Engine::update(float dt){
    // Tutaj będzie logika aktualizacji stanu gry, np. ruch postaci, kolizje, itp.
    // Wywoływane będą funkcje aktualizujące różne elementy gry np. player.update(dt)
}

void Engine::render(){
    // Czyszczenie okna
    window.clear(sf::Color::Black);

    // Tu będzie rusowanie grrafiki

    // Wyświetlenie okna
    window.display();
}