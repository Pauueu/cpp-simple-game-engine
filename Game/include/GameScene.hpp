#pragma once
#include "Scene.hpp"

class GameScene: public Scene {
    public:
        void onStart() override;
        void onUpdate(float dt) override;
        void onStop() override;
};