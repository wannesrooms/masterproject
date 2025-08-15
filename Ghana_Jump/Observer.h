#ifndef OBSERVER_H
#define OBSERVER_H

#include <SFML/Graphics.hpp>

namespace GhanaJump {
    namespace Graphics {
        /**
         * @class Observer
         * @brief De interface voor het Observer-ontwerppatroon.
         *
         * Klassen die deze interface implementeren kunnen zich registreren bij een
         * `Subject` om op de hoogte te worden gehouden van veranderingen.
         */
        class Observer {
        public:
            virtual void update(float cameraY) = 0; // Pure virtuele functies
            virtual ~Observer() = default;
        };
    }
}

#endif //OBSERVER_H
