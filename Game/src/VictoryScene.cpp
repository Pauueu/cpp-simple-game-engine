#include "VictoryScene.hpp"
#include "MainMenuScene.hpp"
#include "GameScene.hpp"
#include "GameManager.hpp"
#include "UIButton.hpp"
#include "UIText.hpp"
#include "SceneManager.hpp"
#include "UIImage.hpp"

    void VictoryScene::onStart() {
        // Tło
        UIImage* background = new UIImage("assets/Background-tinted.png", 1920.0, 1920.0);

        // Tytuł
        UIText* victoryText = new UIText("WYGRANA!", "assets/fonts/PixelifySans.ttf", 120);
        victoryText->setPosition(Vector2f(0.0f, -200.0f));
        victoryText->setColor(218, 165, 32);

        // Wynik
        std::string scoreString = "Wynik: " + std::to_string(GameManager::playerScore);
        UIText* scoreText = new UIText(scoreString, "assets/fonts/PixelifySans.ttf", 56); 
        scoreText->setPosition(Vector2f(0.0f, -60.0f));
        scoreText->setColor(170, 170, 170);

        // Przycisk Zagraj ponownie
        UIButton* restartButton = new UIButton(300, 100, "Zagraj ponownie", "assets/fonts/PixelifySans.ttf", 32);
        restartButton->setPosition(Vector2f(0.0f, 60.0f));
        
        restartButton->setFunction([] () {
            GameManager::resetValues(); 
            SceneManager::loadScene(new GameScene(GameLevel::Level1)); 
        });
        
        restartButton->setBackgroundColor(41, 104, 186);
        restartButton->setLabelColor(255, 255, 255);

        // Przycisk Menu Główne
        UIButton* menuButton = new UIButton(300, 100, L"Menu Główne", "assets/fonts/PixelifySans.ttf", 32);
        menuButton->setPosition(Vector2f(0.0f, 200.0f));

        menuButton->setFunction([] () {
            GameManager::resetValues(); 
            SceneManager::loadScene(new MainMenuScene());
        });
        
        menuButton->setBackgroundColor(80, 80, 80);
        menuButton->setLabelColor(255, 255, 255);
    }
    
    void VictoryScene::onUpdate(float dt) {
        
    }

    void VictoryScene::onStop() {

    }