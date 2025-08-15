#include "Platform.h"

GhanaJump::Entities::Platform::Platform(float x, float y) : Entity(x, y, 100.f, 40.f) {};

bool GhanaJump::Entities::Platform::isColliding(float x, float y) const {
    // Controleer of de speler zich boven het platform bevindt
    return (x >= getX() && x <= getX() + getWidth() && y >= getY() && y <= getY() + getHeight());
}