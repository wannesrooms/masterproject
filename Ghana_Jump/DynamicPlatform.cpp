#include "DynamicPlatform.h"

GhanaJump::Entities::DynamicPlatform::DynamicPlatform(float x, float y, float min, float max) :
	Platform(x, y), speed(200.f), min(min), max(max) {
	prevY = y;
}; // Snelheid is constant in absolute waarde

// Setter
void GhanaJump::Entities::DynamicPlatform::setMinMax(float mi, float ma) {
	min = mi;
	max = ma;
}

// Getter
float GhanaJump::Entities::DynamicPlatform::getPrevY() const {
	return prevY;
}