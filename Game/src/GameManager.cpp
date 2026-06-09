#include "GameManager.hpp"
int GameManager::startPlayerHP = 3;
int GameManager::playerHP = startPlayerHP;
int GameManager::playerScore;

void GameManager::resetValues() {
    playerHP = startPlayerHP;
    playerScore = 0;
}