# Autorski silnik gier 2D w C++ oraz kosmiczna strzelanka w stylu retro

Projekt polegający na stworzeniu prostego, zorientowanego obiektowo silnika do gier 2D oraz implementacja kosmicznej strzelanki w stylu retro. 

## Główne założenia projektu
Celem projektu jest stworzenie silnika, który oddzieli logikę samej gry od zarządzania grafiką, dźwiękiem, fizyką oraz pamięcią.

Projekt dzieli się na dwie warstwy:
1. **Silnik:** Odpowiada za główną pętlę gry, zarządzanie pamięcią i zasobami, obsługę wejścia oraz system detekcji kolizji.
2. **Logika gry:** Klasy reprezentujące konkretne obiekty w grze (gracz, przeciwnik, pociski), które dziedziczą po klasach bazowych silnika.

## Technologie
* **Język:** C++
* **Biblioteka multimedialna:** SFML
* **System budowania:** CMake
