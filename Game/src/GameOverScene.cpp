#include "GameOverScene.hpp"
#include "MainMenuScene.hpp"
#include "GameScene.hpp"
#include "GameManager.hpp"
#include "UIButton.hpp"
#include "UIText.hpp"
#include "UIImage.hpp"
#include "SceneManager.hpp"

    void GameOverScene::onStart() {
        // Tło
        UIImage* background = new UIImage("assets/Background-tinted.png", 1920.0, 1920.0);

        // Tytuł
        UIText* gameOverText = new UIText("KONIEC GRY", "assets/fonts/PixelifySans.ttf", 120); 
        gameOverText->setPosition(Vector2f(0.0f, -200.0f));
        gameOverText->setColor(220, 50, 50);

        // Wynik
        std::string scoreString = "Wynik: " + std::to_string(GameManager::playerScore);
        UIText* scoreText = new UIText(scoreString, "assets/fonts/PixelifySans.ttf", 56); 
        scoreText->setPosition(Vector2f(0.0f, -60.0f));
        scoreText->setColor(170, 170, 170);

        // Przycisk zagraj ponownie
        UIButton* restartButton = new UIButton(300, 100, "Zagraj ponownie", "assets/fonts/PixelifySans.ttf", 32);
        restartButton->setPosition(Vector2f(0.0f, 60.0f));
        
        restartButton->setFunction([] () {
            GameManager::resetValues(); 
            SceneManager::loadScene(new GameScene(GameLevel::Level1)); 
        });
        
        restartButton->setBackgroundColor(41, 104, 186);
        restartButton->setLabelColor(255, 255, 255);


        // Przycisk menu główne
        UIButton* menuButton = new UIButton(300, 100, L"Menu Główne", "assets/fonts/PixelifySans.ttf", 32);
        menuButton->setPosition(Vector2f(0.0f, 200.0f));

        menuButton->setFunction([] () {
            GameManager::resetValues(); 
            SceneManager::loadScene(new MainMenuScene());
        });
        
        menuButton->setBackgroundColor(80, 80, 80);
        menuButton->setLabelColor(255, 255, 255);
    }
    
    void GameOverScene::onUpdate(float dt) {
        
    }

    void GameOverScene::onStop() {

    }