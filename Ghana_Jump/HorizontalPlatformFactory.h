#ifndef HORIZONTALPLATFORMFACTORY_H
#define HORIZONTALPLATFORMFACTORY_H

#include "AbstractFactory.h"
#include <memory>
#include "platform.h"
#include "HorizontalPlatform.h"
#include "Bonus.h"
#include "PlatformView.h"

namespace GhanaJump {
    namespace Factories {
        /**
         * @class HorizontalPlatformFactory
         * @brief Een concrete fabriek voor het creëren van HorizontalPlatform-objecten.
         */
        class HorizontalPlatformFactory : public AbstractFactory {
        public:
            std::shared_ptr<Entities::Entity> createEntity(float x, float y) override {
                return std::make_shared < Entities::HorizontalPlatform >(x, y); // Maakt het platform
            }

            std::shared_ptr<Entities::Player> createPlayer() override {
                return nullptr; // Heeft niet de taak een speler te maken
            }

            // Maakt de bijhorende view
            std::shared_ptr<Graphics::EntityView> createEntityView(std::shared_ptr<Entities::Entity> entity) override {
                return std::make_shared<Graphics::PlatformView>(std::dynamic_pointer_cast<Entities::HorizontalPlatform>(entity));
            }
        };
    }
}

#endif //HORIZONTALPLATFORMFACTORY_H

