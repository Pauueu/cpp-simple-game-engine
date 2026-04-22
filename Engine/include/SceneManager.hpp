#pragma once
#include "Scene.hpp"

class SceneManager {
    private:
        static Scene* currentScene; // Wskaźnik na obecną scenę
        static Scene* nextScene; // Wskaźnik na astępną scenę (scena do załadowania)

        SceneManager() = delete; // Zablokowanie tworzenia instancji klasy SceneManager

    public:
        static void loadScene(Scene* newScene); // Funkcja która ładuje nową scene
        static void update(float dt); //Funkcja do aktualizacji scen
};