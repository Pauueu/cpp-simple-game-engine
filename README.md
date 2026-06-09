# Autorski silnik gier 2D w C++ oraz kosmiczna strzelanka w stylu retro

Projekt polegający na stworzeniu prostego, zorientowanego obiektowo silnika do gier 2D oraz implementacja kosmicznej strzelanki w stylu retro.

## Główne założenia projektu
Celem projektu jest stworzenie  silnika, który oddziela logikę samej gry od zarządzania niskopoziomowego (grafika, pamięć, fizyka). Projekt dzieli się na dwie główne warstwy:

1. **Silnik:** Odpowiada za główną pętlę gry (Delta Time), zarządzanie pamięcią (Resource Manager), obsługę wejścia oraz system detekcji kolizji AABB.
2. **Logika gry:** Klasy reprezentujące konkretne obiekty w grze (Gracz, Przeciwnik, Pociski), które dziedziczą po klasach bazowych silnika (`GameObject`).

## Technologie
* **Język:** C++ (Standard C++17/20)
* **Biblioteka graficzna/audio:** SFML (Simple and Fast Multimedia Library)
* **System budowania:** CMake

## Kluczowe funkcjonalności
* Dynamiczny system zarządzania scenami (Menu, Game, GameOver, Victory).
* Menedżer zasobów zapobiegający wielokrotnemu ładowaniu tekstur (wyciekom pamięci).
* System fizyki oparty na tagach, flagach (`isStatic`, `isTrigger`) i kolizjach prostokątnych.
* Autorski system UI wspierający polskie znaki (std::wstring) i dynamiczne odświeżanie pamięci.

## Kompilacja

Aby skompilować projekt, upewnij się, że posiadasz zainstalowane biblioteki **CMake** oraz **SFML**.

Kroki instalacji za pomocą terminala:

1. Sklonuj repozytorium:
   `git clone https://github.com/Pauueu/cpp-simple-game-engine`
2. Wejdź do folderu projektu:
   `cd [Nazwa Folderu]`
3. Stwórz folder budowania i przejdź do niego:
   `mkdir build && cd build`
4. Wygeneruj pliki projektowe:
   `cmake ..`
5. Skompiluj projekt:
   `cmake --build .`

## Sterowanie w grze
* **W, A, S, D** - Poruszanie się statkiem we wszystkich kierunkach
* **Spacja** - Strzelanie (posiada system Cooldown)
* **Myszka (LPM)** - Obsługa interfejsu w menu

## Szybki start (Przykład użycia silnika)

Silnik został zaprojektowany tak, aby maksymalnie uprościć tworzenie nowych scen:

```cpp
#include "Engine.hpp"
#include "MyGameScene.hpp"
#include "SceneManager.hpp"

int main() {
    Engine engine;
    SceneManager::loadScene(new MyGameScene());
    engine.run();
    return 0;
}