#ifndef HORIZONTALPLATFORM_H
#define HORIZONTALPLATFORM_H

#include "DynamicPlatform.h"
#include "EntityVisitor.h"

namespace GhanaJump {
    namespace Entities {
        /**
         * @class HorizontalPlatform
         * @brief Een concreet platform dat horizontaal heen en weer beweegt.
         */
        class HorizontalPlatform : public DynamicPlatform {
        public:
            HorizontalPlatform(float x, float y); // Regel van drie
            ~HorizontalPlatform() override = default;
            HorizontalPlatform(const HorizontalPlatform&) = default;
            HorizontalPlatform& operator=(const HorizontalPlatform&) = default;

            void update(const float& deltaTime) override; // Dynamische entiteit, heeft updates nodig
            void accept(Logic::EntityVisitor& visitor) override;
        };
    }
}

#endif //HORIZONTALPLATFORM_H
