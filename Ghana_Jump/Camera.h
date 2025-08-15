#ifndef CAMERA_H
#define CAMERA_H

#include "Player.h"
#include <memory>

namespace GhanaJump {
    namespace GameLogic {
        /**
        * @class Camera
        * @brief Beheert de viewport van het spel.
        *
        * De camera volgt de speler omhoog en zorgt ervoor dat de speler
        * in beeld blijft terwijl deze stijgt. De camera beweegt nooit omlaag,
        * wat het 'oneindig klimmen'-gevoel van het spel creëert.
        */
        class Camera {
        private:
            float viewX, viewY;   // Middelpunt van het zichtbare scherm
            float width, height;  // Afmetingen van het zichtbare scherm
            float highestReachedY; // Hoogste punt ooit bereikt door de speler

        public:
            Camera();

            void update(std::shared_ptr<Entities::Player> player); // Camera hangt af van de speler
            float getViewY() const; // Getter voor de  y-positie
            void reset(); // Wordt opnieuw ingesteld bij een nieuw spel
        };
    }
}

#endif //CAMERA_H


