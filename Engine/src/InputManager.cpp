#include "InputManager.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


// Inicjalizacja tablic, same wartości false
std::array<bool, static_cast<int>(KeyCode::Count)> InputManager::currentKeys{};
std::array<bool, static_cast<int>(KeyCode::Count)> InputManager::previousKeys{};

// Stworzenie mapy przycisków klawiatury z Input Manager na SFML
static const std::pair<KeyCode, sf::Keyboard::Key> keyboardKeyMap[] = {
    {KeyCode::A , sf::Keyboard::Key::A },
    {KeyCode::B, sf::Keyboard::Key::B},
    {KeyCode::C, sf::Keyboard::Key::C},
    {KeyCode::D, sf::Keyboard::Key::D},
    {KeyCode::E, sf::Keyboard::Key::E},
    {KeyCode::F, sf::Keyboard::Key::F},
    {KeyCode::G, sf::Keyboard::Key::G},
    {KeyCode::H, sf::Keyboard::Key::H},
    {KeyCode::I, sf::Keyboard::Key::I},
    {KeyCode::J, sf::Keyboard::Key::J},
    {KeyCode::K, sf::Keyboard::Key::K},
    {KeyCode::L, sf::Keyboard::Key::L},
    {KeyCode::M, sf::Keyboard::Key::M},
    {KeyCode::N, sf::Keyboard::Key::N},
    {KeyCode::O, sf::Keyboard::Key::O},
    {KeyCode::P, sf::Keyboard::Key::P},
    {KeyCode::Q, sf::Keyboard::Key::Q},
    {KeyCode::R, sf::Keyboard::Key::R},
    {KeyCode::S, sf::Keyboard::Key::S},
    {KeyCode::T, sf::Keyboard::Key::T},
    {KeyCode::U, sf::Keyboard::Key::U},
    {KeyCode::V, sf::Keyboard::Key::V},
    {KeyCode::W, sf::Keyboard::Key::W},
    {KeyCode::X, sf::Keyboard::Key::X},
    {KeyCode::Y, sf::Keyboard::Key::Y},
    {KeyCode::Z, sf::Keyboard::Key::Z},
    {KeyCode::Num0, sf::Keyboard::Key::Num0},
    {KeyCode::Num1, sf::Keyboard::Key::Num1},
    {KeyCode::Num2, sf::Keyboard::Key::Num2},
    {KeyCode::Num3, sf::Keyboard::Key::Num3},
    {KeyCode::Num4, sf::Keyboard::Key::Num4},
    {KeyCode::Num5, sf::Keyboard::Key::Num5},
    {KeyCode::Num6, sf::Keyboard::Key::Num6},
    {KeyCode::Num7, sf::Keyboard::Key::Num7},
    {KeyCode::Num8, sf::Keyboard::Key::Num8},
    {KeyCode::Num9, sf::Keyboard::Key::Num9},
    {KeyCode::Add, sf::Keyboard::Key::Add},
    {KeyCode::Apostrophe, sf::Keyboard::Key::Apostrophe},
    {KeyCode::Backslash, sf::Keyboard::Key::Backslash},
    {KeyCode::Backspace, sf::Keyboard::Key::Backspace},
    {KeyCode::Comma, sf::Keyboard::Key::Comma},
    {KeyCode::Delete, sf::Keyboard::Key::Delete},
    {KeyCode::Divide, sf::Keyboard::Key::Divide},
    {KeyCode::Down, sf::Keyboard::Key::Down},
    {KeyCode::End, sf::Keyboard::Key::End},
    {KeyCode::Enter, sf::Keyboard::Key::Enter},
    {KeyCode::Equal, sf::Keyboard::Key::Equal},
    {KeyCode::Escape, sf::Keyboard::Key::Escape},
    {KeyCode::Grave, sf::Keyboard::Key::Grave},
    {KeyCode::Home, sf::Keyboard::Key::Home},
    {KeyCode::Hyphen, sf::Keyboard::Key::Hyphen},
    {KeyCode::Insert, sf::Keyboard::Key::Insert},
    {KeyCode::LeftAlt, sf::Keyboard::Key::LAlt},
    {KeyCode::LeftBeacket, sf::Keyboard::Key::LBracket},
    {KeyCode::LeftCtrl, sf::Keyboard::Key::LControl},
    {KeyCode::Left, sf::Keyboard::Key::Left},
    {KeyCode::LeftShift, sf::Keyboard::Key::LShift},
    {KeyCode::LeftSystem, sf::Keyboard::Key::LSystem},
    {KeyCode::Menu, sf::Keyboard::Key::Menu},
    {KeyCode::Multiply, sf::Keyboard::Key::Multiply},
    {KeyCode::PageDown, sf::Keyboard::Key::PageDown},
    {KeyCode::PageUp, sf::Keyboard::Key::PageUp},
    {KeyCode::Period, sf::Keyboard::Key::Period},
    {KeyCode::RightAlt, sf::Keyboard::Key::RAlt},
    {KeyCode::RightBracket, sf::Keyboard::Key::RBracket},
    {KeyCode::RightCtrl, sf::Keyboard::Key::RControl},
    {KeyCode::Right, sf::Keyboard::Key::Right},
    {KeyCode::RightShift, sf::Keyboard::Key::RShift},
    {KeyCode::RightSystem, sf::Keyboard::Key::RSystem},
    {KeyCode::Semicolon, sf::Keyboard::Key::Semicolon},
    {KeyCode::Slash, sf::Keyboard::Key::Slash},
    {KeyCode::Space, sf::Keyboard::Key::Space},
    {KeyCode::Subtract, sf::Keyboard::Key::Subtract},
    {KeyCode::Tab, sf::Keyboard::Key::Tab},
    {KeyCode::Up, sf::Keyboard::Key::Up},
    {KeyCode::Numpad0, sf::Keyboard::Key::Numpad0},
    {KeyCode::Numpad1, sf::Keyboard::Key::Numpad1},
    {KeyCode::Numpad2, sf::Keyboard::Key::Numpad2},
    {KeyCode::Numpad3, sf::Keyboard::Key::Numpad3},
    {KeyCode::Numpad4, sf::Keyboard::Key::Numpad4},
    {KeyCode::Numpad5, sf::Keyboard::Key::Numpad5},
    {KeyCode::Numpad6, sf::Keyboard::Key::Numpad6},
    {KeyCode::Numpad7, sf::Keyboard::Key::Numpad7},
    {KeyCode::Numpad8, sf::Keyboard::Key::Numpad8},
    {KeyCode::Numpad9, sf::Keyboard::Key::Numpad9},
    {KeyCode::F1, sf::Keyboard::Key::F1},
    {KeyCode::F10, sf::Keyboard::Key::F10},
    {KeyCode::F11, sf::Keyboard::Key::F11},
    {KeyCode::F12, sf::Keyboard::Key::F12},
    {KeyCode::F13, sf::Keyboard::Key::F13},
    {KeyCode::F14, sf::Keyboard::Key::F14},
    {KeyCode::F15, sf::Keyboard::Key::F15},
    {KeyCode::F2, sf::Keyboard::Key::F2},
    {KeyCode::F3, sf::Keyboard::Key::F3},
    {KeyCode::F4, sf::Keyboard::Key::F4},
    {KeyCode::F5, sf::Keyboard::Key::F5},
    {KeyCode::F6, sf::Keyboard::Key::F6},
    {KeyCode::F7, sf::Keyboard::Key::F7},
    {KeyCode::F8, sf::Keyboard::Key::F8},
    {KeyCode::F9, sf::Keyboard::Key::F9}
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