#include "Background.h"

GhanaJump::Graphics::Background::Background(const std::string& baseTextureName, int numTextures) : numSprites(numTextures) {
    // Laad de vijf texturen
    for (int i = 1; i <= numTextures; ++i) {
        sf::Texture texture;
        std::string textureFile = baseTextureName + std::to_string(i) + ".jpg"; // Genereer de bestandsnaam
        if (!texture.loadFromFile(textureFile)) {
            throw std::runtime_error("Failed to load background texture: " + textureFile);
        }
        textures.push_back(texture); // Voeg de geladen textuur toe aan de vector
    }

    // Maak de sprites voor de achtergrond
    for (int i = 0; i < numSprites; ++i) {
        sf::Sprite sprite;
        sprite.setTexture(textures[i]); // Gebruik de juiste textuur
        sprite.setPosition(0,  -(i - 1) * textures[0].getSize().y); // Plaats de sprites onder elkaar
        sprites.push_back(sprite);
    }
}

void GhanaJump::Graphics::Background::update(float cameraY) {
    // Controleer of we nieuwe sprites moeten genereren
    for (size_t i = 0; i < sprites.size(); ++i) {
        // Als een sprite onder het zichtbare gebied komt, verplaats deze naar boven
        if (sprites[i].getPosition().y > cameraY + 750.f) {
            // Verplaats de sprite naar de bovenkant van de laatste sprite
            sprites[i].setPosition(0, sprites[(i + numSprites - 1) % numSprites].getPosition().y - textures[0].getSize().y);
        }
    }
}

void GhanaJump::Graphics::Background::render(sf::RenderWindow& window) {
    // Teken de vijf achtergronden
    for (const auto& sprite : sprites) {
        window.draw(sprite);
    }
}

void GhanaJump::Graphics::Background::reset() {
    // Reset de sprites naar hun startposities
    for (int i = 0; i < numSprites; ++i) {
        sprites[i].setPosition(0,  -(i - 1) * textures[0].getSize().y); // Plaats de sprites opnieuw
    }
}