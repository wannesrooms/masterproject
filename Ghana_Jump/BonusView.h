#ifndef BONUSVIEW_H
#define BONUSVIEW_H

#include "EntityView.h"
#include <memory>
#include "Bonus.h"

namespace GhanaJump {
    namespace Graphics {
        /**
         * @class BonusView
         * @brief De visuele representatie van een Bonus-object.
         *
         * Deze klasse is verantwoordelijk voor het tekenen van de juiste sprite
         * voor een bonus op de correcte positie op het scherm.
         */
        class BonusView : public EntityView {
        private:
            std::shared_ptr<Entities::Bonus> bonus; // Pointer naar bonus als entiteit
            sf::Texture texture;  // Texture varieert in type bonus
        public:
            BonusView(std::shared_ptr<Entities::Bonus> bonus); // Regel van drie
            ~BonusView() override = default;
            BonusView(const BonusView&) = default;
            BonusView& operator=(const BonusView&) = default;

            void render(sf::RenderWindow& window) override; // Override van EntityView
            void update(float cameraY) override; // Override van Observer, maar bonussen zijn statisch
            std::shared_ptr<Entities::Bonus> getBonus() const; // Getter
        };
    }
}

#endif //BONUSVIEW_H




