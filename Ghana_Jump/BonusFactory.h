#ifndef BONUSFACTORY_H
#define BONUSFACTORY_H

#include "AbstractFactory.h"
#include <memory>
#include "Bonus.h"
#include "EntityView.h"
#include "BonusView.h"

namespace GhanaJump {
    namespace Factories {
        /**
         * @class BonusFactory
         * @brief Een concrete fabriek voor het creëren van Bonus-objecten en hun views.
         */
        class BonusFactory : public AbstractFactory {
        public:
            std::shared_ptr<Entities::Entity> createEntity(float x, float y) override {
                return std::make_shared<Entities::Bonus>(x, y); // Creëer een specifieke bonus
            }

            std::shared_ptr<Entities::Player> createPlayer() override {
                return nullptr; // Heeft niet de taak om een speler te maken
            }

            // Maak een bijhorende view
            std::shared_ptr<Graphics::EntityView> createEntityView(std::shared_ptr<Entities::Entity> entity) override {
                return std::make_shared<Graphics::BonusView>(std::dynamic_pointer_cast<Entities::Bonus>(entity));
            }
        };

    }
}

#endif //BONUSFACTORY_H


