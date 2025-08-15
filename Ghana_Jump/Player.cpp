#include "Player.h"
#include <iostream>

GhanaJump::Entities::Player::Player()
    : Entity(350.f, 400.f, 100.f, 144.f),
    velocityX(0.f), velocityY(0.f),
    gravity(750.f), jumpStrength(-875.f), inBonusState(false), lookingDirection(Direction::RIGHT) { // Initialiseer op RIGHT

    prevY = y;
}

void GhanaJump::Entities::Player::update(const float& deltaTime) {
    prevY = y;

    // Pas zwaartekracht toe
    velocityY += gravity * deltaTime;

    // Werk positie bij
    setPosition(getX() + velocityX * deltaTime, getY() + velocityY * deltaTime);

    // Wrapping rond het scherm
    if (getX() + width / 2 < 0) {
        setPosition(800.f - getWidth()/2, getY());
    }
    if (getX() + width / 2 > 800) {
        setPosition(- getWidth()/2, getY());
    }

    // Vanaf we neerwaarts bewegen is de bonusstate altijd gedaan
    if (velocityY > 0) {
        inBonusState = false;
    }
}

// Getters
float GhanaJump::Entities::Player::getVelocityX() const { return velocityX; }
float GhanaJump::Entities::Player::getVelocityY() const { return velocityY; }
GhanaJump::Entities::Player::Direction GhanaJump::Entities::Player::getLookingDirection() const {
    return lookingDirection;
}
float GhanaJump::Entities::Player::getPrevY() const {
    return prevY;
}

// Setters
void GhanaJump::Entities::Player::setVelocityX(float velocity) {
    velocityX = velocity;

    if (velocityX < 0) {
        lookingDirection = Direction::LEFT;
    }
    else if (velocityX > 0) {
        lookingDirection = Direction::RIGHT;
    }
}
void GhanaJump::Entities::Player::setVelocityY(float velocity) { velocityY = velocity; }
void GhanaJump::Entities::Player::setInBonusState() { inBonusState = true;  }
bool GhanaJump::Entities::Player::getInBonusState() const { return inBonusState; }

// Springen is de y-snelheid aanpassen
void GhanaJump::Entities::Player::jump() {
    velocityY = jumpStrength;
}

bool GhanaJump::Entities::Player::hasFallen(float cameraY) const {
    return y > cameraY + 550 + (height / 2); // Vergelijk y-waarde van de speler met de camera
}

void GhanaJump::Entities::Player::accept(Logic::EntityVisitor& visitor) {
    visitor.visit(*this);
}