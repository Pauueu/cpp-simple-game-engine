#include "Engine.hpp"
#include "SceneManager.hpp"
#include "scenes.hpp"

#include <iostream>

int main(){
    Engine engine;

    SceneManager::loadScene(new MainMenuScene());

    engine.run();

    return 0;
}
