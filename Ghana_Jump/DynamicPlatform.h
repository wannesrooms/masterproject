#ifndef DYNAMICPLATFORM_H
#define DYNAMICPLATFORM_H

#include "Platform.h"

namespace GhanaJump {
	namespace Entities {
		/**
		 * @class DynamicPlatform
		 * @brief Een abstracte subklasse voor alle platformen die kunnen bewegen.
		 *
		 * Deze klasse voegt basis-eigenschappen voor beweging toe, zoals snelheid
		 * en de grenzen (min/max) waarbinnen het platform beweegt.
		 */
		class DynamicPlatform : public Platform {
		protected:
			float speed; // Constant op teken na
			float min, max; // Grenzen waarbij we naar de andere kant bewegen
			float prevY;
		public:
			DynamicPlatform(float x, float y, float min, float max);

			virtual ~DynamicPlatform() override = default; // Regel van 3
			DynamicPlatform(const DynamicPlatform&) = default;
			DynamicPlatform& operator=(const DynamicPlatform&) = default;

			virtual void update(const float& deltaTime) override = 0; // Zijn niet statisch dus nuttige update functie
			void setMinMax(float mi, float ma); // Setter voor grenzen

			float getPrevY() const;
		};
	}
}

#endif //DYNAMICPLATFORM_H



