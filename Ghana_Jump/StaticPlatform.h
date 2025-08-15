#ifndef STATICPLATFORM_H
#define STATICPLATFORM_H

#include "Platform.h"
#include "EntityVisitor.h" // Include de visitor

namespace GhanaJump {
    namespace Entities {
        /**
         * @class StaticPlatform
         * @brief Een concreet platform dat niet beweegt.
         *
         * Dit is het meest eenvoudige type platform in het spel.
         */
        class StaticPlatform : public Platform {
        public:
            StaticPlatform(float x, float y);
            ~StaticPlatform() override = default; // Regel van 3
            StaticPlatform(const StaticPlatform&) = default;
            StaticPlatform& operator=(const StaticPlatform&) = default;

            void update(const float& deltaTime) override;
            void accept(Logic::EntityVisitor& visitor) override;
        };
    }
}

#endif //STATICPLATFORM_H