#ifndef ENTITYVIEW_H
#define ENTITYVIEW_H

#include "Observer.h"
#include <SFML/Graphics.hpp>

namespace GhanaJump {
    namespace Graphics {
        /**
         * @class EntityView
         * @brief De abstracte basisklasse voor de visuele representatie van een Entity.
         *
         * Elke `EntityView` is een `Observer` die de staat van een `Entity` observeert
         * en verantwoordelijk is voor het tekenen ervan op het scherm.
         */
        class EntityView : public Observer {
        public:
            virtual void update(float cameraY) override = 0; // Virtuele functies

            virtual void render(sf::RenderWindow& window) = 0;

            sf::Sprite sprite; // Elke view heeft een sprite

            virtual ~EntityView() = default; // Virtuele destructor
        };
    }
}

#endif //ENTITYVIEW_H




