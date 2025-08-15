#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "AbstractFactory.h"
#include <memory>
#include "Bonus.h"
#include "Platform.h"
#include "EntityView.h"
#include "PlayerView.h"

namespace GhanaJump {
    namespace Factories {
        /**
         * @class PlayerFactory
         * @brief Een concrete fabriek specifiek voor het creëren van de Player entiteit en zijn view.
         */
        class PlayerFactory : public AbstractFactory {
        public:
            std::shared_ptr<Entities::Entity> createEntity(float x, float y) override {
                return std::make_shared<Entities::Player>(); // Maakt een speler
            }

            std::shared_ptr<Entities::Player> createPlayer() override {
                return std::make_shared<Entities::Player>(); // Maakt een speler
            }

            // Maakt de bijhorende view
            std::shared_ptr<Graphics::EntityView> createEntityView(std::shared_ptr<Entities::Entity> entity) override {
                return std::make_shared<Graphics::PlayerView>(std::dynamic_pointer_cast<Entities::Player>(entity));
            }
        };
    }
}

#endif //PLAYERFACTORY_H

