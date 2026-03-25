#include "Engine.hpp"
#include "Player.hpp"
#include <iostream>

int main(){
    Engine engine;

    Player player("assets/player.png", 200.0f, 200.0f);

    engine.run();

    return 0;
}
