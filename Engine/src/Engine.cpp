#include "Engine.hpp"
#include "InputManager.hpp"
#include <optional>
#include <iostream>

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

        // Wywołanie funkcji Input Managera
        InputManager::SetPreviousState();
        InputManager::SetCurrentState();

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
    // Logika aktualizacji stanu gry, np. ruch postaci, kolizje, itp.

    for (GameObject* obj : GameObject::gameObjects) {
        obj->update(dt);
    }

    // KOLIZJE
    // Sprawdzenie każdego obiektu z każdym
    for (int i = 0; i < GameObject::gameObjects.size(); i++) {
        for (int j = i + 1; j < GameObject::gameObjects.size(); j++) {
            GameObject* objA = GameObject::gameObjects[i];
            GameObject* objB = GameObject::gameObjects[j];

            // Pominięcie sprawdzania dla obiektów, które są oznaczone jako do zniszczenia (isDead = true)
            if (objA->isDead || objB->isDead) {
                continue;
            }

            auto intersection = objA->getBounds().findIntersection(objB->getBounds()); // Powierzchnia jaką pokrywają się dwa obiekty

            if (intersection) {
                // Jeżeli obiekty są fizyczne, czyli działa na nie odpychanie (isTrigger = false)
                if (!objA->isTrigger && !objB->isTrigger) {
                    // Sprawdzenie w jakim stopniu obiekty nachodzą na siebie
                    if (intersection->size.x > 0.0f && intersection->size.y > 0.0f) {
                        float moveX = 0.0f;
                        float moveY = 0.0f;

                        // Dobranie wktora w którym kierunku obiekt zostanie wypchany (x lub y)
                        if (intersection->size.x > intersection->size.y) {
                            if (objA->getPosition().y < objB->getPosition().y) {
                                moveY = -intersection->size.y;
                            }
                            else {
                                moveY = intersection->size.y;
                            }
                        }
                        else {
                            if (objA->getPosition().x < objB->getPosition().x) {
                                moveX = -intersection->size.x;
                            }
                            else {
                                moveX = intersection->size.x;
                            }
                        }

                        // Określa który obiekt ma być wypchnięty
                        if (!objA->isStatic && objB->isStatic) {
                            objA->moveOut(moveX, moveY);
                        }
                        else if (objA->isStatic && !objB->isStatic) {
                            objB->moveOut(-moveX, -moveY);
                        }
                        else if (!objA->isStatic && !objB->isStatic) {
                            objA->moveOut(moveX * 0.5f, moveY * 0.5f);
                            objB->moveOut(-moveX * 0.5f, -moveY * 0.5f);
                        }
                    }
                }
                
                // Wywołanie funkcji onCollision dla obu obiektów
                objA->onCollision(objB);
                objB->onCollision(objA);
            }
        }
    }

    // Usuwanie obiektó, które mają być zniszczone
    for (auto it = GameObject::gameObjects.begin(); it != GameObject::gameObjects.end();) {

        if ((*it)->isDead) {
            delete *it; // Usunięcie obiektu z pamięci
            it = GameObject::gameObjects.erase(it); // Usunięcie wskaźnika, zwraca wskażnik do następnego 
        }

        else {
            it++;
        }
    }

}

void Engine::render(){
    // Czyszczenie okna
    window.clear(sf::Color::Black);

    for (GameObject* obj : GameObject::gameObjects) {
        obj->draw(window);
    }

    // Wyświetlenie okna
    window.display();
}