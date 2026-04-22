#include "SceneManager.hpp"
#include "GameObject.hpp"
#include <iostream>


Scene* SceneManager::currentScene = nullptr;
Scene* SceneManager::nextScene = nullptr;

void SceneManager::loadScene(Scene* newScene) {
    nextScene = newScene;
}

void SceneManager::update(float dt) {
    if (nextScene != nullptr) {

        // Usuwanie starej sceny
        if (currentScene != nullptr) {
            currentScene->onStop();
            delete currentScene;
        }

        // Usuwanie wszystkich obiektów z pamięci
        for (GameObject* obj : GameObject::gameObjects) {
            delete obj;
        }
        GameObject::gameObjects.clear();

        // Przypisanie nowej sceny do obecnej
        currentScene = nextScene;
        nextScene = nullptr;

        currentScene->onStart();
    }

    if (currentScene != nullptr) {
        // Wywołanie funkcji onUpdate sceny
        currentScene->onUpdate(dt);
    }
}