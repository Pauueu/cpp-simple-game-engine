#include "scenes.hpp"
#include "Player.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "SceneManager.hpp"
#include <iostream>


// Game Scene 1
void GameScene1::onStart() {
    Player* player = new Player("assets/player.png", -250.0f, -100.0f, 1.0f, 1.0f, "Player");


    GameObject* wall1 = new GameObject("assets/wall.png", 0.0f, 220.0f, 1.0f, 1.0f, "Wall", false, true);


    GameObject* coin1 = new GameObject("assets/coin.png", 0.0f, -100.0f, 1.0f, 1.0f, "Coin", true, true);

    new GameObject("assets/coin.png", -100.0f, -100.0f, 0.8f, 0.8f, "Coin", true, true);

    GameObject* coin2 = new GameObject("assets/coin.png", 0.0f, -200.0f);
        coin2->setScale(1.2f, 1.2f);
        coin2->tag = "Coin";
        coin2->isTrigger = true;
        coin2->isStatic = true;

    GameObject* coin3 = new GameObject("assets/ball.png", 0.0f, 0.0f);
}

void GameScene1::onUpdate(float dt) {
    if (InputManager::GetKeyDown(KeyCode::Enter)) {
        SceneManager::loadScene(new GameScene2);
    }
}

void GameScene1::onStop() {
    std::cout << "liczba elementow w poprzedniej scenie: " << GameObject::gameObjects.size() << std::endl;
}


// Game Scene 2
void GameScene2::onStart() {
    Player* player = new Player("assets/player.png", 0.0f, -200.0f, 1.0f, 1.0f, "Player");

    new GameObject("assets/ball.png", -200.0f, 0.0f, 1.2f, 1.2f);
    new GameObject("assets/ball.png", 0.0f, 0.0f);
    new GameObject("assets/ball.png", 200.0f, 0.0f, 0.8f, 0.8f);
}

void GameScene2::onUpdate(float dt) {
    if (InputManager::GetKeyDown(KeyCode::Enter)) {
        SceneManager::loadScene(new GameOverScene);
    }
}

void GameScene2::onStop() {
    std::cout << "liczba elementow w poprzedniej scenie: " << GameObject::gameObjects.size() << std::endl;
}



// Game Over Scene
void GameOverScene::onStart() {

}

void GameOverScene::onUpdate(float dt) {

}

void GameOverScene::onStop() {

}


