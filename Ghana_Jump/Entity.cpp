#include "Entity.h"

GhanaJump::Entities::Entity::Entity(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {};

// Getters
float GhanaJump::Entities::Entity::getX() const { return x; }
float GhanaJump::Entities::Entity::getY() const { return y; }
float GhanaJump::Entities::Entity::getWidth() const { return width; }
float GhanaJump::Entities::Entity::getHeight() const { return height; }

// Setters
void GhanaJump::Entities::Entity::setPosition(float xPos, float yPos) {
    x = xPos;
    y = yPos;
}
