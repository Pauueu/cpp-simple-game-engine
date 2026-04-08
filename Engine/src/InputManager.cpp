#include "InputManager.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


// Inicjalizacja tablic, same wartości false
std::array<bool, static_cast<int>(KeyCode::Count)> InputManager::currentKeys{};
std::array<bool, static_cast<int>(KeyCode::Count)> InputManager::previousKeys{};

// Stworzenie mapy przycisków klawiatury z Input Manager na SFML
static const std::pair<KeyCode, sf::Keyboard::Key> keyboardKeyMap[] = {
    {KeyCode::A, sf::Keyboard::Key::W},
    {KeyCode::B, sf::Keyboard::Key::A},
    {KeyCode::C, sf::Keyboard::Key::S},
    {KeyCode::D, sf::Keyboard::Key::D},
    {KeyCode::E, sf::Keyboard::Key::Q},
    {KeyCode::F, sf::Keyboard::Key::W},
    {KeyCode::G, sf::Keyboard::Key::A},
    {KeyCode::H, sf::Keyboard::Key::S},
    {KeyCode::I, sf::Keyboard::Key::D},
    {KeyCode::J, sf::Keyboard::Key::Q},
    {KeyCode::K, sf::Keyboard::Key::W},
    {KeyCode::A, sf::Keyboard::Key::A},
    {KeyCode::S, sf::Keyboard::Key::S},
    {KeyCode::D, sf::Keyboard::Key::D},
    {KeyCode::Q, sf::Keyboard::Key::Q},
    {KeyCode::W, sf::Keyboard::Key::W},
    {KeyCode::A, sf::Keyboard::Key::A},
    {KeyCode::S, sf::Keyboard::Key::S},
    {KeyCode::D, sf::Keyboard::Key::D},
    {KeyCode::Q, sf::Keyboard::Key::Q},
    {KeyCode::W, sf::Keyboard::Key::W},
    {KeyCode::A, sf::Keyboard::Key::A},
    {KeyCode::S, sf::Keyboard::Key::S},
    {KeyCode::D, sf::Keyboard::Key::D},
    {KeyCode::Q, sf::Keyboard::Key::Q},
    {KeyCode::W, sf::Keyboard::Key::W},
    {KeyCode::A, sf::Keyboard::Key::A},
    {KeyCode::S, sf::Keyboard::Key::S},
    {KeyCode::D, sf::Keyboard::Key::D},
    {KeyCode::Q, sf::Keyboard::Key::Q},
    {KeyCode::W, sf::Keyboard::Key::W},
    {KeyCode::A, sf::Keyboard::Key::A},
    {KeyCode::S, sf::Keyboard::Key::S},
    {KeyCode::D, sf::Keyboard::Key::D},
    {KeyCode::Q, sf::Keyboard::Key::Q}
};


// Stworzenie mapy przycisków myszki z Input Manager na SFML
static const std::pair<KeyCode, sf::Mouse::Button> mouseKeyMap[] = {
    {KeyCode::MouseLeft, sf::Mouse::Button::Left},
    {KeyCode::MouseRight, sf::Mouse::Button::Right},
    {KeyCode::MouseMiddle, sf::Mouse::Button::Middle}
};


void InputManager::SetPreviousState() {
    previousKeys = currentKeys;
}

void InputManager::SetCurrentState() {
    for (const auto& key : keyboardKeyMap) {
        // Sprawdza każdy klawisz z mapy czy jest wciśniety i zapisuje jego stan w tablicy stanów
        currentKeys[static_cast<int>(key.first)] = sf::Keyboard::isKeyPressed(key.second);
    }

    for (const auto& key : mouseKeyMap) {
        // Sprawdza każdy klawisz z mapy czy jest wciśniety i zapisuje jego stan w tablicy stanów
        currentKeys[static_cast<int>(key.first)] = sf::Mouse::isButtonPressed(key.second);
    }
}

bool InputManager::GetKey(KeyCode key) {
    return currentKeys[static_cast<int>(key)];
}

bool InputManager::GetKeyDown(KeyCode key) {
    // Porównuje wartoście, czy przycisk jest wciśnięty w obecnej klatce, a nie był w poprzedniej
    return currentKeys[static_cast<int>(key)] && !previousKeys[static_cast<int>(key)];
}

bool InputManager::GetKeyUp(KeyCode key) {
    // Porównuje wartoście, czy przycisk był wciśnięty w poprzedniej klatce, a nie jest w obecnej
    return !currentKeys[static_cast<int>(key)] && previousKeys[static_cast<int>(key)];
}