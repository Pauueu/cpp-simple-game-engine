#include "Engine.hpp"
#include "SceneManager.hpp"
#include "scenes.hpp"

#include <iostream>

int main(){
    Engine engine;

    engine.setWindowSize(1920, 1080);

    SceneManager::loadScene(new MainMenuScene());

    engine.run();

    return 0;
}
