#include "PlatformView.h"
#include <memory>
#include <iostream>

GhanaJump::Graphics::PlatformView::PlatformView(std::shared_ptr<GhanaJump::Entities::Platform> platform) : platform(platform) {
    // Laad de juiste textuur op basis van het type platform
    if (auto staticPlatform = std::dynamic_pointer_cast<GhanaJump::Entities::StaticPlatform>(platform)) {
        if (!texture.loadFromFile("resources/Platform_Groen.png")) { // Stilstaand platform
            std::cerr << "Error: Could not load static platform texture" << std::endl;
            throw std::runtime_error("Failed to load static platform texture");
        }
    }
    else if (auto dynamicPlatform = std::dynamic_pointer_cast<GhanaJump::Entities::GrayPlatform>(platform)) {
        if (!texture.loadFromFile("resources/Platform_Wit.png")) { // Eenmalig platform
            std::cerr << "Error: Could not load gray platform texture" << std::endl;
            throw std::runtime_error("Failed to load dynamic platform texture");
        }
    }
    else if (auto dynamicPlatform = std::dynamic_pointer_cast<GhanaJump::Entities::HorizontalPlatform>(platform)) {
        if (!texture.loadFromFile("resources/Platform_Blauw.png")) { // Horizontaal bewegend platform
            std::cerr << "Error: Could not load horizontal platform texture" << std::endl;
            throw std::runtime_error("Failed to load dynamic platform texture");
        }
    }
    else if (auto dynamicPlatform = std::dynamic_pointer_cast<GhanaJump::Entities::VerticalPlatform>(platform)) {
        if (!texture.loadFromFile("resources/Platform_Geel.png")) { // Verticaal bewegend platform
            std::cerr << "Error: Could not load vertical platform texture" << std::endl;
            throw std::runtime_error("Failed to load dynamic platform texture");
        }
    }

    // Stel de sprite in op de geladen textuur
    sprite.setTexture(texture);
    sprite.setPosition(platform->getX(), platform->getY()); // Zelfde positie als entiteit
}

void GhanaJump::Graphics::PlatformView::render(sf::RenderWindow& window) {
    // Teken de sprite
    window.draw(sprite);
}

void GhanaJump::Graphics::PlatformView::update(float cameraY) {
    // Update de sprite positie op basis van het platform (enkel nuttig bij dynamische entiteiten)
    sprite.setPosition(platform->getX(), platform->getY());
}

// Getter
std::shared_ptr<GhanaJump::Entities::Platform> GhanaJump::Graphics::PlatformView::getPlatform() const {
    return platform;
}
