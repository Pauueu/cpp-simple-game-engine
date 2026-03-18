#include "ResourceManager.hpp"

// Funkcja do pobierania tekstury z mapy zasobów
sf::Texture& ResourceManager::getTexture(const std::string& path){
    // Sprawdzenie czy tekstuara istrnieje w mapie
    if(textures.find(path) != textures.end()){
        return textures[path];
    }
    
    // Jeśli nie ma tekstury w mapie

    sf::Texture texture;

    // Sprawdzenie czy ścieżka do tekstury jest poprawna i czy tekstura została poprawnie załadowana
    if(texture.loadFromFile(path)){
        // Dodanie tektury do mapy i zwrócenie jej
        // insert() zwraca parę iterator i bool, gdzie iterator wskazuje na element w mapie, a bool informuje czy element został dodany
        auto result = textures.insert({path, std::move(texture)});
        return result.first->second;
    }

    else{
        // Jeśli nie można załadować tekstury, to dodaje pustą teksture do mapy i zwraca ją
        auto result = textures.insert({path, sf::Texture()});
        return result.first->second;
    }
}


// Funkcja do pobierania fonta z mapy zasobów
sf::Font& ResourceManager::getFont(const std::string& path){
    // Sprawdzenie czy font istrnieje w mapie
    if(fonts.find(path) != fonts.end()){
        return fonts[path];
    }

    // Jeśli nie ma fonta w mapie

    sf::Font font;

    // Sprawdzenie czy ścieżka do fonta jest poprawna i czy font został poprawnie załadowany
    if(font.openFromFile(path)){
        // Dodanie fonta do mapy i zwrócenie go
        auto result = fonts.insert({path, std::move(font)});
        return result.first->second;
    }
    
    else{
        // Jeśli nie można załadować fonta, to dodaje pustego fonta do mapy i zwraca go
        auto result = fonts.insert({path, sf::Font()});
        return result.first->second;
    }
}


// getSoundBuffer


void ResourceManager::clear(){
    // Czyszczenie map z zasobami
    textures.clear();
    fonts.clear();

    // przy obsłude dźwięku
    // soundBuffers.clear();

}