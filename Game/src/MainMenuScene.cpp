#include "MainMenuScene.hpp"
#include "UIElement.hpp"
#include "UIButton.hpp"
#include "UIText.hpp"
#include "UIImage.hpp"
#include "Vector2f.hpp"
#include "SceneManager.hpp"
#include "GameScene.hpp"
#include "GameManager.hpp"



void MainMenuScene::onStart() {
    // Tło
    UIImage* background = new UIImage("assets/Background-tinted.png", 1920.0, 1920.0);

    // Tytuł gry
    UIText* titleText = new UIText("RETRO SHOOTER", "assets/fonts/PixelifySans.ttf", 120);
    titleText->setPosition(Vector2f(0.0f, -200.0f));
    titleText->setColor(41, 104, 186);

    // Przycisk Start
    UIButton* startButton = new UIButton(300, 100, "START", "assets/fonts/PixelifySans.ttf", 32);
    startButton->setPosition(Vector2f(0.0f, 50.0f));
    
    startButton->setFunction([] () {
        GameManager::resetValues();
        SceneManager::loadScene(new GameScene(GameLevel::Level1));
    });
    
    startButton->setBackgroundColor(41, 104, 186);
    startButton->setLabelColor(255, 255, 255);

    // Przycisk Wyjście
    UIButton* exitButton = new UIButton(300, 100, L"WYJDŹ", "assets/fonts/PixelifySans.ttf", 32);
    exitButton->setPosition(Vector2f(0.0f, 200.0f));
    
    exitButton->setFunction([] () {
        std::exit(0);
    });
    
    exitButton->setBackgroundColor(80, 80, 80);
    exitButton->setLabelColor(255, 255, 255);
}


void MainMenuScene::onUpdate(float dt) {
    
}


void MainMenuScene::onStop() {
    
}

