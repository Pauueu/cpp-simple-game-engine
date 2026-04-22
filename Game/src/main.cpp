#include "Engine.hpp"
#include "SceneManager.hpp"
#include "scenes.hpp"

#include <iostream>

int main(){
    Engine engine;

    SceneManager::loadScene(new GameScene1());

    engine.run();

    return 0;
}
