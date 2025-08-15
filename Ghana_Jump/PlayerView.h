#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include "EntityView.h" 
#include <memory>
#include "Player.h"    

namespace GhanaJump {
    namespace Graphics {
        /**
         * @class PlayerView
         * @brief De visuele representatie van de speler.
         *
         * Deze klasse is verantwoordelijk voor het tekenen van de speler en zorgt ervoor
         * dat de juiste sprite (links- of rechtskijkend) wordt getoond.
         */
        class PlayerView : public EntityView {
        private:
            std::shared_ptr<Entities::Player> player;  // Referentie naar de speler als entiteit
            sf::Texture textureLeft, textureRight; // Texturen voor links en rechts te bewegen

        public:
            PlayerView(std::shared_ptr<Entities::Player> player); // Regel van drie
            ~PlayerView() override = default;
            PlayerView(const PlayerView&) = default;
            PlayerView& operator=(const PlayerView&) = default;

            void render(sf::RenderWindow& window) override; // Override van EntityView
            void update(float cameraY) override; // Override van Observer
        };
    }
}

#endif // PLAYERVIEW_H
