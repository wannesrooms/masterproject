#ifndef VERTICALPLATFORM_H
#define VERTICALPLATFORM_H

#include "DynamicPlatform.h"
#include "Random.h"
#include "EntityVisitor.h" // Include de visitor

namespace GhanaJump {
    namespace Entities {
        /**
         * @class VerticalPlatform
         * @brief Een concreet platform dat verticaal heen en weer beweegt.
         */
        class VerticalPlatform : public DynamicPlatform {
        public:
            VerticalPlatform(float x, float y);
            ~VerticalPlatform() override = default; // Regel van 3
            VerticalPlatform(const VerticalPlatform&) = default;
            VerticalPlatform& operator=(const VerticalPlatform&) = default;

            void update(const float& deltaTime) override;
            void accept(Logic::EntityVisitor& visitor) override; 
        };

    }
}

#endif //VERTICALPLATFORM_H


