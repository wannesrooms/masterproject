#include "HorizontalPlatform.h"

GhanaJump::Entities::HorizontalPlatform::HorizontalPlatform(float x, float y) : DynamicPlatform(x, y, 25.f, 675.f) {};

void GhanaJump::Entities::HorizontalPlatform::update(const float& deltaTime) {
    // Beweeg het platform in de x- en y-richting
    setPosition(getX() + speed * deltaTime, getY());

    // Kijk of we de randen van het bewegingsinterval hebben bereikt en draai dan om
    if (getX() < min) {
        speed = -speed;
        setPosition(min, getY());
    }
    else if (getX() > max) {
        speed = -speed;
        setPosition(max, getY());
    }
}

void GhanaJump::Entities::HorizontalPlatform::accept(Logic::EntityVisitor& visitor) {
    visitor.visit(*this);
}