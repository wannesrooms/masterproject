#include "BonusView.h"
#include <memory>
#include <iostream>

GhanaJump::Graphics::BonusView::BonusView(std::shared_ptr<GhanaJump::Entities::Bonus> bonus) : bonus(bonus) {
    // Laad de juiste textuur op basis van het type platform
    if (bonus->getType() == GhanaJump::Entities::Bonus::Type::Energy) { // Textuur 1
        if (!texture.loadFromFile("resources/Energy_Drink.png")) {
            std::cerr << "Error: Could not load energy drink texture" << std::endl;
            throw std::runtime_error("Failed to load static platform texture");
        }
    }
    else if (bonus->getType() == GhanaJump::Entities::Bonus::Type::Jetpack) { // Textuur 2
        if (!texture.loadFromFile("resources/Jetpack.png")) {
            std::cerr << "Error: Could not load gray platform texture" << std::endl;
            throw std::runtime_error("Failed to load jetpack texture");
        }
    }

    // Stel de sprite in op de geladen textuur
    sprite.setTexture(texture);
    sprite.setPosition(bonus->getX(), bonus->getY()); // Zelfde positie als entiteit

    // Schaal de sprite naar 50x50 (grootte van een bonus)
    sprite.setScale(50.f / sprite.getGlobalBounds().width, 50.f / sprite.getGlobalBounds().height);
}

void GhanaJump::Graphics::BonusView::render(sf::RenderWindow& window) {  
    window.draw(sprite); // Teken de sprite
}

void GhanaJump::Graphics::BonusView::update(float cameraY) {
    // Alle bonussen zijn statisch
}

// Getter
std::shared_ptr<GhanaJump::Entities::Bonus> GhanaJump::Graphics::BonusView::getBonus() const {
    return bonus;
}
