#ifndef WORLD_H
#define WORLD_H

// Views en Subject zijn hier niet meer nodig
#include "Player.h"
#include <memory>
#include "PlayerFactory.h"
#include "StaticPlatformFactory.h"
#include "GrayPlatformFactory.h"
#include "HorizontalPlatformFactory.h"
#include "VerticalPlatformFactory.h"
#include "BonusFactory.h"
#include "EntityView.h"
#include "Score.h"
#include "Background.h"
#include "CollisionVisitor.h"
#include <vector> // Voor het gebruik van vectoren

namespace GhanaJump {
    namespace GameLogic {
        /**
         * @class World
         * @brief Vertegenwoordigt het Model in de MVC-architectuur.
         *
         * De World beheert de staat van alle spelentiteiten (speler, platformen, etc.),
         * de spelregels, en de interacties daartussen. Het is volledig onafhankelijk
         * van de grafische weergave en bevat de kernlogica van het spel.
         */
        class World {
        private:
            // Enkel entiteiten en logische objecten
            std::shared_ptr<Entities::Player> player;
            std::vector<std::shared_ptr<Entities::Entity>> entities;
            std::shared_ptr<Score> score;
            std::shared_ptr<Graphics::Background> background;

            // View-gerelateerde leden zijn verwijderd
            // std::shared_ptr<Graphics::EntityView> playerView;
            // std::vector<std::shared_ptr<Graphics::EntityView>> entityViews;

            // Factories
            Factories::PlayerFactory playerFactory;
            Factories::StaticPlatformFactory staticPlatformFactory;
            Factories::GrayPlatformFactory grayPlatformFactory;
            Factories::HorizontalPlatformFactory horizontalPlatformFactory;
            Factories::VerticalPlatformFactory verticalPlatformFactory;
            Factories::BonusFactory bonusFactory;

        public:
            World();

            void update(float deltaTime, float cameraY);
            void reset();
            void generateInitialPlatforms();
            void removeEntitiesOutOfView();
            float findHighestPlatformY() const;
            void generateNewPlatforms(float highestY);

            // Getters
            std::shared_ptr<Entities::Player> getPlayer() const;
            const std::vector<std::shared_ptr<Entities::Entity>>& getEntities() const;
            std::shared_ptr<Score> getScore() const;
            std::shared_ptr<Graphics::Background> getBackground() const;
        };
    }
}

#endif //WORLD_H
