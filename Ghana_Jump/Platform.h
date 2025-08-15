#ifndef PLATFORM_H
#define PLATFORM_H

#include "Entity.h"

namespace GhanaJump {
    namespace Entities {
        /**
         * @class Platform
         * @brief Een abstracte basisklasse voor alle platform-objecten in het spel.
         *
         * Definieert de basisfunctionaliteit die alle platformen delen, zoals de
         * mogelijkheid om te controleren op botsingen.
         */
        class Platform : public Entity {
        public:
            Platform(float x, float y); // Regel van drie
            virtual ~Platform() override= default;
            Platform(const Platform&) = default;
            Platform& operator=(const Platform&) = default;

            virtual void update(const float& deltaTime) override = 0; // Soms statisch, soms dynamisch
            bool isColliding(float x, float y) const; // Om te controleren of speler een platform aanraakt
        };
    }
}

#endif //PLATFORM_H



