#include "MainMenuScene.hpp"
#include "UIElement.hpp"
#include "UIButton.hpp"
#include "Vector2f.hpp"
#include "SceneManager.hpp"
#include "GameScene.hpp"


void MainMenuScene::onStart() {
    UIButton* startButton = new UIButton(200, 100, "START", "assets/fonts/arial.ttf");
    startButton->setPosition(Vector2f(0.0f, 0.0f));
    startButton->setFunction([] () {
        SceneManager::loadScene(new GameScene);
    });
    startButton->setBackgroundColor(41, 104, 186);
    startButton->setLabelColor(40, 40, 40);
}


void MainMenuScene::onUpdate(float dt) {
    
}


void MainMenuScene::onStop() {
    
}

