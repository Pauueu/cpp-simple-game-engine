#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager {
private:
    // Mapy do przechowywania zasobów
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
    // std::map<std::string, sf::SoundBuffer> soundBuffers;

    ResourceManager() {}; // Konstruktor

    // Zablokowanie możliwośći kopiowania obiektu
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager& operator= (const ResourceManager &) = delete;

public:
    // Stworzenie jednej instancji obiektu
    static ResourceManager& get(){
        static ResourceManager instance;

        return instance;
    }

    // Funkcje do zapisu zasobów
    sf::Texture& getTexture(const std::string& path);
    sf::Font& getFont(const std::string& path);
    // sf::SoundBuffer& getSoundBuffer(const std::string& path);

    void clear(); // Funkcja do czyszczenia zasobów


};