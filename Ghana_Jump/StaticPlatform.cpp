#include "StaticPlatform.h"

GhanaJump::Entities::StaticPlatform::StaticPlatform(float x, float y) : Platform(x, y) {};

void GhanaJump::Entities::StaticPlatform::update(const float& deltaTime) {
	// Statische entiteit, geen update nodig
}

void GhanaJump::Entities::StaticPlatform::accept(Logic::EntityVisitor& visitor) {
	visitor.visit(*this);
}