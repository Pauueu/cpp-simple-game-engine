#pragma once
#include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
#include <map>
#include <string>

class ResourceManager {
public:
    ResourceManager() = default;

    // Funkcje do zapisu zasobów
    sf::Texture& getTexture(const std::string& path);
    sf::Font& getFont(const std::string& path);
    // sf::SoundBuffer& getSoundBuffer(const std::string& path);

    // Funkcja do czyszczenia zasobów
    void clear();

private:
    // Mapy do przechowywania zasobów
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
    // std::map<std::string, sf::SoundBuffer> soundBuffers;
};