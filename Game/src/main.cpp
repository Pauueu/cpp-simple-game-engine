#include "Engine.hpp"
#include "SceneManager.hpp"
#include "MainMenuScene.hpp"

#include <iostream>

int main(){
    Engine engine;

    SceneManager::loadScene(new MainMenuScene());

    engine.run();

    return 0;
}
