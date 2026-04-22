#pragma once
#include "Scene.hpp"

class GameScene1 : public Scene {
    public:
        void onStart ();
        void onUpdate (float dt);
        void onStop ();
};

class GameScene2 : public Scene {
    public:
        void onStart ();
        void onUpdate (float dt) ;
        void onStop ();
};

class GameOverScene : public Scene {
    public:
        void onStart ();
        void onUpdate (float dt);
        void onStop ();
};