#pragma once
#include "Scene.hpp"

class VictoryScene: public Scene {
    public:
        void onStart() override;
        void onUpdate(float dt) override;
        void onStop() override;
};