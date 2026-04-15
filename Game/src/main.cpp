#include "Engine.hpp"
#include "Player.hpp"
#include <iostream>

int main(){
    Engine engine;

    Player* player = new Player("assets/player.png", 200.0f, 200.0f, "Player");

    GameObject* wall1 = new GameObject("assets/wall.png", 200.0f, 500.0f, "Wall", false, true);

    GameObject* coin1 = new GameObject("assets/coin.png", 600.0f, 300.0f, "Coin", true, true);
    new GameObject("assets/coin.png", 400.0f, 300.0f, "Coin", true, true);
    new GameObject("assets/coin.png", 600.0f, 400.0f, "Coin", true, true);

    GameObject* coin2 = new GameObject("assets/coin.png", 600.0f, 200.0f);

    engine.run();

    return 0;
}
