#include "VerticalPlatform.h"

GhanaJump::Entities::VerticalPlatform::VerticalPlatform(float x, float y)
    : DynamicPlatform(x, y, 0, 0) { // Initializer list met dummy waarden
    GhanaJump::Utilities::Random& rng = GhanaJump::Utilities::Random::getInstance();
    float height = rng.getFloat(300, 700); // Bepaal willekeurig de grenzen

    // Update de dummy variabelen met de juiste hoogte
    setMinMax(y - height / 2, y + height / 2);
}

void GhanaJump::Entities::VerticalPlatform::update(const float& deltaTime) {

    prevY = getY();

    // Beweeg het platform in de x- en y-richting
    setPosition(getX(), getY() + speed * deltaTime);

    // Kijk of we de randen van het bewegingsinterval hebben bereikt en draai dan om
    if (getY() < min) {
        speed = -speed;
        setPosition(getX(), min);
    }
    else if (getY() > max) { 
        speed = -speed;
        setPosition(getX(), max);
    }
}

void GhanaJump::Entities::VerticalPlatform::accept(Logic::EntityVisitor& visitor) {
    visitor.visit(*this);
}