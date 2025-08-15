#ifndef GRAYPLATFORM_H
#define GRAYPLATFORM_H

#include "Platform.h"
#include "EntityVisitor.h" // Include de visitor

namespace GhanaJump {
	namespace Entities {
		/**
		 * @class GrayPlatform
		 * @brief Een concreet platform dat verdwijnt na één keer springen.
		 *
		 * Dit platform is statisch maar heeft een extra staat (`isUsed`) om bij
		 * te houden of de speler er al op geland is.
		 */
		class GrayPlatform : public Platform {
		private:
			bool isUsed; // We kijken of er al op het platform is gesprongen
		public:
			GrayPlatform(float x, float y); // Regel van drie
			~GrayPlatform() override = default;
			GrayPlatform(const GrayPlatform&) = default; 
			GrayPlatform& operator=(const GrayPlatform&) = default; 

			void update(const float& deltaTime) override; // Is een statische entiteit
			void accept(Logic::EntityVisitor& visitor) override;
			void use(); // Verandert de variabele isUsed
			bool getIsUsed() const; // Getter
		};
	}
}

#endif //GRAYPLATFORM_H



