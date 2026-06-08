#pragma once
#include "Scene.hpp"
#include "Player.hpp"
#include "UIText.hpp"

// Poziomy gry
enum class GameLevel {
    Level1 = 1,
    Level2,
    Level3,
    Level4,
    Level5,
    
    LevelsCount
};


class GameScene: public Scene {
    private:
        GameLevel currentLevel; // Wybrana poziom gry
        Player* player; // Wskaźnik na gracza

        int lastDisplayedScore = -1; // Zmienna śledząca poprzedni wynik gracza
        UIText* scoreDisplay = nullptr; // Wskaźnik na tekst wyniku
        
    public:
        GameScene(GameLevel level = GameLevel::Level1); // Konstruktor z przypisaniem levelu
        void onStart() override;
        void onUpdate(float dt) override;
        void onStop() override;
};