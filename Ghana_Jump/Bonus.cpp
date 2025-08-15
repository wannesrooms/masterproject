#include "Bonus.h"

GhanaJump::Entities::Bonus::Bonus(float x, float y) : Entity(x, y, 50.f, 50.f), isActive(true), type(Type::Jetpack) { // dummy variabele
    GhanaJump::Utilities::Random& rng = GhanaJump::Utilities::Random::getInstance();
    float percentage = rng.getFloat(0, 100); // Procentuele kans berekenen op type bonus

    if (percentage < 75) { // 75 procent kans op energy
        setType(Type::Energy);
    }
    else { // 25 procent kans op jetpack
        setType(Type::Jetpack);
    }
};

void GhanaJump::Entities::Bonus::update(const float& deltaTime) {
    // Statisch, geen updates nodig
}

void GhanaJump::Entities::Bonus::accept(Logic::EntityVisitor& visitor) {
    visitor.visit(*this);
}

// Getters en setters
void GhanaJump::Entities::Bonus::setType(Type whichType) {
    type = whichType;
}

GhanaJump::Entities::Bonus::Type GhanaJump::Entities::Bonus::getType() const {
    return type;
}

bool GhanaJump::Entities::Bonus::getIsActive() const {
	return isActive;
}

void GhanaJump::Entities::Bonus::deactivate() {
    isActive = false;
}