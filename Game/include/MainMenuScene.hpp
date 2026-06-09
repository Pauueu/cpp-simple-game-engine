#pragma once
#include "Scene.hpp"

class MainMenuScene: public Scene {
    public:
        void onStart() override;
        void onUpdate(float dt) override;
        void onStop() override;
};