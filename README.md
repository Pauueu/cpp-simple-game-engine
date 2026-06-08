# Autorski silnik gier 2D w C++ oraz kosmiczna strzelanka w stylu retro

Projekt polegający na stworzeniu prostego, zorientowanego obiektowo silnika do gier 2D oraz implementacja kosmicznej strzelanki w stylu retro.

## Główne założenia projektu
Celem projektu jest stworzenie silnika, który oddzieli logikę samej gry od zarządzania grafiką, dźwiękiem, fizyką oraz pamięcią.

1. **Silnik:** Odpowiada za główną pętlę gry (Delta Time), zarządzanie pamięcią (Resource Manager), obsługę wejścia oraz system detekcji kolizji AABB.
2. **Logika gry:** Klasy reprezentujące konkretne obiekty w grze (Gracz, Przeciwnik, Pociski), które dziedziczą po klasach bazowych silnika (`GameObject`).

## Technologie
* **Język:** C++ (Standard C++17/20)
* **Biblioteka graficzna:** SFML
* **System budowania:** CMake


## Kluczowe funkcjonalności
* Dynamiczny system zarządzania scenami (Menu, Game, GameOver, Victory).
* Menedżer zasobów zapobiegający wielokrotnemu ładowaniu tekstur (wyciekom pamięci).
* System fizyki oparty na tagach, flagach (`isStatic`, `isTrigger`) i kolizjach.
* Autorski system UI i dynamiczne odświeżanie pamięci.


## Sterowanie w grze
* **W, A, S, D** - Poruszanie się statkiem we wszystkich kierunkach
* **Spacja** - Strzelanie
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