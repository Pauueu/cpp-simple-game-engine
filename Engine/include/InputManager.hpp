#pragma once
#include "KeyCode.hpp"
#include "array"

class InputManager {
private:
    static std::array<bool, static_cast<int>(KeyCode::Count)> currentKeys; // Tablica stanów wszystkich przycisków w obecnej klatce
    static std::array<bool, static_cast<int>(KeyCode::Count)> previousKeys; // Tablica stanów wszystkich przycisków w poprzedniej klatce

public:
    static void SetPreviousState(); // Funkcja zapisująca stan wszystkich przycisków z wcześniejszej klatki
    static void SetCurrentState(); // Funkcja zapisująca aktualny stan wszystkich przycisków w obecnej klatce

    static bool GetKey(KeyCode key); // Funkcja zwracająca stan przycisku
    static bool GetKeyDown(KeyCode key); // Funkcja zwracająca czy przycisk został naciśnięty
    static bool GetKeyUp(KeyCode key); // Funkcja zwracająca czy przycisk został puszczony
};