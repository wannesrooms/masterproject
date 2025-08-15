#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <memory>
#include "Platform.h"
#include "Bonus.h"
#include "Player.h"
#include "EntityView.h"

namespace GhanaJump {
    namespace Factories {
        /**
         * @class AbstractFactory
         * @brief De abstracte interface voor fabrieken die families van gerelateerde objecten creëren.
         *
         * Dit patroon zorgt ervoor dat een systeem onafhankelijk is van hoe zijn objecten
         * (in dit geval een Entity en zijn bijbehorende EntityView) worden gecreëerd.
         */
        class AbstractFactory {
        public:
            virtual std::shared_ptr<Entities::Entity> createEntity(float x, float y) = 0;
            // Speler wordt vaak op een volledig andere manier gebruikt dan andere entiteiten, dus krijgt een aparte functie
            virtual std::shared_ptr<Entities::Player> createPlayer() = 0; 
            virtual std::shared_ptr<Graphics::EntityView> createEntityView(std::shared_ptr<Entities::Entity> entity) = 0;

            virtual ~AbstractFactory() = default; // Virtuele destructor, geen regel van 3

        };
    }
}

#endif // ABSTRACTFACTORY_H

