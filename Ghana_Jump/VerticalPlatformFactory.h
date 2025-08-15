#ifndef VERTICALPLATFORMFACTORY_H
#define VERTICALPLATFORMFACTORY_H

#include "AbstractFactory.h"
#include <memory>
#include "platform.h"
#include "VerticalPlatform.h"
#include "Bonus.h"
#include "PlatformView.h"

namespace GhanaJump {
    namespace Factories {
        /**
         * @class VerticalPlatformFactory
         * @brief Een concrete fabriek voor het creëren van VerticalPlatform-objecten.
         */
        class VerticalPlatformFactory : public AbstractFactory {
        public:
            std::shared_ptr<Entities::Entity> createEntity(float x, float y) override {
                return std::make_shared<Entities::VerticalPlatform>(x, y);
            }

            std::shared_ptr<Entities::Player> createPlayer() override {
                return nullptr; // Heeft niet de taak een speler te maken
            }

            // Maakt de bijhorende view
            std::shared_ptr<Graphics::EntityView> createEntityView(std::shared_ptr<Entities::Entity> entity) override {
                return std::make_shared<Graphics::PlatformView>(std::dynamic_pointer_cast<Entities::VerticalPlatform>(entity));
            }
        };
    }
}

#endif //VERTICALPLATFORMFACTORY_H

