#ifndef STATICPLATFORMFACTORY_H
#define STATICPLATFORMFACTORY_H

#include "AbstractFactory.h"
#include <memory>
#include "Platform.h"
#include "StaticPlatform.h"
#include "Bonus.h"
#include "PlatformView.h"

namespace GhanaJump {
    namespace Factories {
        /**
         * @class HorizontalPlatformFactory
         * @brief Een concrete fabriek voor het creëren van StaticPlatform-objecten.
         */
        class StaticPlatformFactory : public AbstractFactory {
        public:
            std::shared_ptr<Entities::Entity> createEntity(float x, float y) override {
                return std::make_shared<Entities::StaticPlatform>(x, y); // Maakt het platform aan
            }

            std::shared_ptr<Entities::Player> createPlayer() override {
                return nullptr; // Heeft niet de taak een speler te maken
            }

            // Maakt de bijhorende view aan
            std::shared_ptr<Graphics::EntityView> createEntityView(std::shared_ptr<Entities::Entity> entity) override {
                return std::make_shared<Graphics::PlatformView>(std::dynamic_pointer_cast<Entities::StaticPlatform>(entity));
            }
        };
    }
}

#endif //STATICPLATFORMFACTORY_H


