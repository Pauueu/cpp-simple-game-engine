#include "GameScene.hpp"
#include "GameOverScene.hpp"
#include "VictoryScene.hpp"
#include "SceneManager.hpp"
#include "GameManager.hpp"
#include "UIElement.hpp"
#include "UIButton.hpp"
#include "UIText.hpp"
#include "Vector2f.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "GameObject.hpp"
#include "UIElement.hpp"
#include "UIImage.hpp"
#include <string>

// Konstruktor
GameScene::GameScene(GameLevel level): currentLevel(level) {

}


void GameScene::onStart() {

    GameObject* background = new GameObject("assets/Background.png", 0.0, 0.0);
    background->isStatic = true;
    background->isTrigger = true;
    background->setScale(1.5f, 1.5f);

    player = new Player("assets/Player.png", 0.0f, 400.0f, 0.4f, 0.4f);
    player->setCurrentHP(GameManager::playerHP);

    GameObject* bottomWall = new GameObject("assets/empty.png", 0.0f, 590.0f);
    bottomWall->isStatic = true;
    bottomWall->setScale(20.0f, 1.0f);
    bottomWall->tag = "BottomWall";

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


    // Stworzenie przeciwników dla dlanego poziomu
    switch(currentLevel) {
        case GameLevel::Level1:
            new Enemy(EnemyType::Enemy1, 600.0f, -300.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy1, -600.0f, -300.0f, 0.5f, 0.5f);
            break;

        case GameLevel::Level2:
            new Enemy(EnemyType::Enemy1, 600.0f, -300.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy1, -600.0f, -300.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy2, 0.0f, -300.0f, 0.5f, 0.5f);
    
            break;

        case GameLevel::Level3:
            new Enemy(EnemyType::Enemy1, 700.0f, -100.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy1, -500.0f, -100.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy2, 100.0f, -100.0f, 0.5f, 0.5f);

            new Enemy(EnemyType::Enemy1, 600.0f, -250.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy1, -600.0f, -250.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy2, 0.0f, -250.0f, 0.5f, 0.5f);
            
            break;

        case GameLevel::Level4:
            new Enemy(EnemyType::Enemy1, 700.0f, -60.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy1, -500.0f, -60.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy2, 100.0f, -60.0f, 0.5f, 0.5f);

            new Enemy(EnemyType::Enemy3, -200.0f, -300.0f, 0.5f, 0.5f);

            new Enemy(EnemyType::Enemy1, 600.0f, -380.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy1, -600.0f, -380.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy2, 0.0f, -380.0f, 0.5f, 0.5f);
            
            break;

        case GameLevel::Level5:
            new Enemy(EnemyType::Enemy1, 700.0f, -50.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy1, -500.0f, -50.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy2, 100.0f, -50.0f, 0.5f, 0.5f);

            new Enemy(EnemyType::Enemy3, 600.0f, -320.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy4, 0.0f, -320.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy3, -600.0f, -320.0f, 0.5f, 0.5f);

            new Enemy(EnemyType::Enemy1, 600.0f, -560.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy1, -600.0f, -560.0f, 0.5f, 0.5f);
            new Enemy(EnemyType::Enemy2, 0.0f, -560.0f, 0.5f, 0.5f);
            
            break;
    }
}


void GameScene::onUpdate(float dt) {

    // Aktualizowanie tekstu pokazującego wynik gracza
    if (GameManager::playerScore != lastDisplayedScore) {
        if (scoreDisplay != nullptr) {
            auto it = std::find(UIElement::uiElements.begin(), UIElement::uiElements.end(), scoreDisplay);
            if (it != UIElement::uiElements.end()) {
                UIElement::uiElements.erase(it);
            }
            delete scoreDisplay; 
        }

        std::string scoreString = std::to_string(GameManager::playerScore);

        scoreDisplay = new UIText(scoreString, "assets/fonts/PixelifySans.ttf", 70);
        scoreDisplay->setPosition(Vector2f(0.0f, -460.0f)); 
        scoreDisplay->setColor(170, 170, 170); 

        lastDisplayedScore = GameManager::playerScore;
    }



    int enemyCount = 0;

    for (GameObject* obj : GameObject::gameObjects ) {
        if(obj->tag == "Enemy" && !obj->isDead) {
            enemyCount++;
        }
    }

    if(enemyCount == 0) {
        int newSceneIndex = static_cast<int>(currentLevel) + 1;

        GameManager::playerHP = player->getCurrentHP();
        
        if (newSceneIndex < static_cast<int>(GameLevel::LevelsCount)) {
            GameLevel newLevel = static_cast<GameLevel>(newSceneIndex);

            SceneManager::loadScene(new GameScene(newLevel));
        }
        else {
            // wywołanie Sceny Kończącej grę (wygrana)
            SceneManager::loadScene(new VictoryScene());
        }
    }

    if(player->getCurrentHP() <= 0) {
        GameManager::playerHP = player->getCurrentHP();

       // wywołanie Sceny Kończącej grę (przegrana)
        SceneManager::loadScene(new GameOverScene());
    }
}


void GameScene::onStop() {
    
}

