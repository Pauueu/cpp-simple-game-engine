# Autorski silnik gier 2D w C++ oraz gra Space Invaders

Projekt semestralny polegający na stworzeniu prostego, zorientowanego obiektowo frameworka (silnika) do gier 2D oraz implementacji klasycznej gry zręcznościowej Space Invaders. 

## Główne założenia projektu
Celem projektu jest oddzielenie obsługi multimediów od logiki samej gry. 

Projekt dzieli się na dwie warstwy:
1. **Silnik:** Odpowiada za główną pętlę gry, zarządzanie pamięcią i zasobami, obsługę wejścia oraz system detekcji kolizji.
2. **Logika gry:** Klasy reprezentujące konkretne obiekty w grze (gracz, przeciwnik, pociski), które dziedziczą po klasach bazowych silnika.

## Technologie
* **Język:** C++
* **Biblioteka multimedialna:** SFML
* **System budowania:** CMake
