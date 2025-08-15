#include "GrayPlatform.h"

GhanaJump::Entities::GrayPlatform::GrayPlatform(float x, float y) : Platform(x, y), isUsed(false) {}; // Is in het begin nog nooit gebruikt

void GhanaJump::Entities::GrayPlatform::update(const float& deltaTime) {
	// statisch platform, beweegt niet
}

void GhanaJump::Entities::GrayPlatform::accept(Logic::EntityVisitor& visitor) {
	visitor.visit(*this);
}

// Specifieke setter
void GhanaJump::Entities::GrayPlatform::use() {
	isUsed = true;
}

// Getter
bool GhanaJump::Entities::GrayPlatform::getIsUsed() const {
	return isUsed;
}
