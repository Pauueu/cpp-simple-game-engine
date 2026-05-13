#include "GameScene.hpp"
#include "UIElement.hpp"
#include "UIButton.hpp"
#include "Vector2f.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "GameObject.hpp"
#include "UIElement.hpp"
#include "UIImage.hpp"

void GameScene::onStart() {
    GameObject* player = new Player("assets/Player.png", 0.0f, 0.0f, 0.4f, 0.4f);

    GameObject* bottomWall = new GameObject("assets/empty.png", 0.0f, 590.0f);
    bottomWall->isStatic = true;
    bottomWall->setScale(20.0f, 1.0f);
    bottomWall->tag = "Wall";

    GameObject* topWall = new GameObject("assets/empty.png", 0.0f, -590.0f);
    topWall->isStatic = true;
    topWall->setScale(20.0f, 1.0f);
    topWall->tag = "Wall";

    GameObject* leftWall = new GameObject("assets/empty.png", 1010.0f, 0.0f);
    leftWall->isStatic = true;
    leftWall->setScale(1.0f, 20.0f);
    leftWall->tag = "Wall";

    GameObject* rightWall = new GameObject("assets/empty.png", -1010.0f, 0.0f);
    rightWall->isStatic = true;
    rightWall->setScale(1.0f, 20.0f);
    rightWall->tag = "Wall";

    GameObject* enemy1 = new Enemy("assets/enemy1.png", 0.0f, -300.0f, 0.5f, 0.5f);
}


void GameScene::onUpdate(float dt) {
    
}


void GameScene::onStop() {
    
}

