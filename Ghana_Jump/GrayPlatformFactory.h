#ifndef GRAYPLATFORMFACTORY_H
#define GRAYPLATFORMFACTORY_H

#include "AbstractFactory.h"
#include <memory>
#include "platform.h"
#include "Grayplatform.h"
#include "Bonus.h"
#include "EntityView.h"
#include "PlatformView.h"

namespace GhanaJump {
    namespace Factories {
        /**
         * @class HorizontalPlatformFactory
         * @brief Een concrete fabriek voor het creëren van GrayPlatform-objecten.
         */
        class GrayPlatformFactory : public AbstractFactory {
        public:
            std::shared_ptr<Entities::Entity> createEntity(float x, float y) override {
                return std::make_shared<Entities::GrayPlatform>(x, y); // Maakt een platform
            }

            std::shared_ptr<Entities::Player> createPlayer() override {
                return nullptr; // Heeft niet de taak om een speler te maken
            }

            // Maakt de bijhorende view aan
            std::shared_ptr<Graphics::EntityView> createEntityView(std::shared_ptr<Entities::Entity> entity) override {
                return std::make_shared<Graphics::PlatformView>(std::dynamic_pointer_cast<Entities::GrayPlatform>(entity));
            }
        };
    }
}

#endif //GRAYPLATFORMFACTORY_H

