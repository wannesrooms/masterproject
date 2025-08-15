#ifndef RANDOM_H
#define RANDOM_H

#include <random>

namespace GhanaJump {
    namespace Utilities {
        /**
         * @class Random
         * @brief Een Singleton-klasse voor het genereren van willekeurige getallen.
         *
         * Biedt een centrale, geseed'de random number generator (RNG) die overal
         * in de applicatie kan worden gebruikt om consistente willekeur te garanderen.
         */
        class Random { 
            private:
            std::mt19937 rng;
            Random();

        public:
            static Random& getInstance();
            int getInt(int min, int max); // Willekeurig geheel getal in een interval
            float getFloat(float min, float max); // Willekeurig kommagetal in een interval
        };
    }
}

#endif //RANDOM_H


