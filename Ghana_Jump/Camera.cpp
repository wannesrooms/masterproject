#include "Camera.h"
#include <memory>

GhanaJump::GameLogic::Camera::Camera() // Constructor
    : viewX(450.f), viewY(400.f), width(800.f),height(1100.f),highestReachedY(1100.f) {}

void GhanaJump::GameLogic::Camera::update(std::shared_ptr<GhanaJump::Entities::Player> player) {
    // Zorg ervoor dat de camera alleen omhoog beweegt, niet omlaag
    if (player->getY() < highestReachedY) { // Nieuw hoogtepunt bereikt
        viewY = player->getY() + height / 4.f; // Speler iets boven het midden van het scherm
        highestReachedY = player->getY();
    }
}

// Getter
float GhanaJump::GameLogic::Camera::getViewY() const {
    return viewY;
}

void GhanaJump::GameLogic::Camera::reset() {
    // Stel de camera in op de beginpositie
    this->viewY = 400.f; // Komt neer op startpositie van de speler
    highestReachedY = 1100.f;
}
