#include "PlayerView.h"
#include <memory>
#include <iostream>

GhanaJump::Graphics::PlayerView::PlayerView(std::shared_ptr<GhanaJump::Entities::Player> player) : player(player) {
    // Laad de texturen voor de speler
    if (!textureLeft.loadFromFile("resources/Ata_Kak_Links.png")) {
        std::cerr << "Error: Could not load player_left texture" << std::endl;
        throw std::runtime_error("Failed to load player_left texture");
    }
    if (!textureRight.loadFromFile("resources/Ata_Kak_Rechts.png")) {
        std::cerr << "Error: Could not load player_right texture" << std::endl;
        throw std::runtime_error("Failed to load player_right texture");
    }

    // Stel de sprite in op de rechter afbeelding als standaard
    sprite.setTexture(textureRight);

    // Schaal de sprite naar de gewenste breedte
    float scaleX = player->getWidth() / sprite.getGlobalBounds().width; // Schaalfactor voor de breedte
    sprite.setScale(scaleX, scaleX);

    // Positioneer de sprite op zelfde plek als entiteit
    sprite.setPosition(player->getX(), player->getY());
}

void GhanaJump::Graphics::PlayerView::render(sf::RenderWindow& window) {
    // Teken de sprite
    window.draw(sprite);
}

void GhanaJump::Graphics::PlayerView::update(float cameraY) {
    // Update de sprite positie op basis van de speler
    sprite.setPosition(player->getX(), player->getY() - (sprite.getGlobalBounds().height - 144.f));

    // Vraag de kijkrichting direct op van de Player-entiteit
    if (player->getLookingDirection() == Entities::Player::Direction::LEFT) {
        sprite.setTexture(textureLeft);
    }
    else {
        sprite.setTexture(textureRight);
    }
}
